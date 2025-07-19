#include "jsonprocess.h"
#include "ui_jsonprocess.h"
#include "./mainwindow.h"
#include <QJsonDocument>
#include <QJsonParseError>
#include <QClipboard>

JsonProcess::JsonProcess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::JsonProcess)
{
    ui->setupUi(this);
}

JsonProcess::~JsonProcess()
{
    delete ui;
}

void JsonProcess::on_btnBackToMain_clicked()
{
    MainWindow *mainWindowWindow = new MainWindow();
    mainWindowWindow->show();
    this->destroy();
}

QString formatJsonWithValidation(const QString& jsonInput) {
    // 转换为UTF-8编码的字节数组
    QByteArray jsonData = jsonInput.toUtf8();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        // 计算错误位置（行号/列号）
        int line = 1;
        int column = 1;
        for (int i = 0; i < parseError.offset && i < jsonData.size(); ++i) {
            if (jsonData.at(i) == '\n') {
                ++line;
                column = 1;
            } else {
                ++column;
            }
        }

        return QString("JSON格式错误: %1\n位置: 行 %2, 列 %3\n错误上下文: %4")
            .arg(parseError.errorString())
            .arg(line)
            .arg(column)
            .arg(jsonInput.mid(qMax(0, parseError.offset - 20), 40));  // 显示错误位置前后文本
    }

    // 格式化为带缩进的可读JSON
    return doc.toJson(QJsonDocument::Indented);
}

void JsonProcess::on_btnJsonFormat_clicked()
{
    QString rawTextString = ui->plainTextEditRaw->toPlainText();
    QString processedTextString = formatJsonWithValidation(rawTextString);
    ui->textBrowserProcessed->setLineWrapMode(QTextEdit::NoWrap);
    ui->textBrowserProcessed->setPlainText(processedTextString);
}

QString compressJsonWithValidation(const QString& jsonInput) {
    // 转换为UTF-8编码的字节数组
    QByteArray jsonData = jsonInput.toUtf8();

    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        // 计算错误位置（行号/列号）
        int line = 1;
        int column = 1;
        for (int i = 0; i < parseError.offset && i < jsonData.size(); ++i) {
            if (jsonData.at(i) == '\n') {
                ++line;
                column = 1;
            } else {
                ++column;
            }
        }

        return QString("JSON格式错误: %1\n位置: 行 %2, 列 %3\n错误上下文: %4")
            .arg(parseError.errorString())
            .arg(line)
            .arg(column)
            .arg(jsonInput.mid(qMax(0, parseError.offset - 20), 40));
    }

    // 压缩JSON（去除所有不必要的空白字符）
    return QString::fromUtf8(doc.toJson(QJsonDocument::Compact));
}


void JsonProcess::on_btnJsonCompress_clicked()
{
    QString rawTextString = ui->plainTextEditRaw->toPlainText();
    QString processedTextString = compressJsonWithValidation(rawTextString);
    ui->textBrowserProcessed->setLineWrapMode(QTextEdit::WidgetWidth);
    ui->textBrowserProcessed->setPlainText(processedTextString);
}


void JsonProcess::on_btnCopyProcessedText_clicked()
{
    QString processedTextString = ui->textBrowserProcessed->toPlainText();
    QClipboard *clip = QApplication::clipboard();
    clip->setText(processedTextString);
}
