#include "stringprocess.h"
#include "ui_stringprocess.h"
#include "./mainwindow.h"
#include<QApplication>
#include<QStringList>
#include<QClipboard>
#include<QDateTime>
#include<QTimer>

StringProcess::StringProcess(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StringProcess)
{
    ui->setupUi(this);
}

StringProcess::~StringProcess()
{
    delete ui;
}


// 下划线转小驼峰处理函数
QString processUnderline2SmallCamelCase(const QString &rawTextString) {
    if (rawTextString.isEmpty()) {
        return rawTextString;
    }
    QString  processedTextString;
    bool nextUpper = false;
    for(auto c : rawTextString) {
        if(c == '_'){
            nextUpper = true;
        } else {
            if (nextUpper) {
                processedTextString.append(c.toUpper());
                nextUpper = false;
            } else {
                if (processedTextString.isEmpty()){
                    processedTextString.append(c.toLower());
                } else{
                    processedTextString.append(c);
                }
            }
        }
    }
    return processedTextString;
}

// 下划线转大驼峰处理函数
QString processUnderline2BigCamelCase(const QString &rawTextString) {
    if (rawTextString.isEmpty()) {
        return rawTextString;
    }
    QStringList partsDivNewLine = rawTextString.split('\n', Qt::SkipEmptyParts);
    QString processedTextString;
    Q_FOREACH(const QString &partDivNewLine, partsDivNewLine) {
        QStringList parts = partDivNewLine.split('_', Qt::SkipEmptyParts);
        Q_FOREACH(const QString &part, parts){
            if (!part.isEmpty()) {
                processedTextString += part[0].toUpper();
                if (part.length() > 1) {
                    processedTextString += part.mid(1).toLower();
                }
            }
        }
        processedTextString.append("\n");
    }
    return processedTextString;
}

// 全大写
QString process2AllUpperCase(const QString &rawTextString) {
    if (rawTextString.isEmpty()) {
        return rawTextString;
    }
    QString processedTextString = rawTextString.toUpper();
    return processedTextString;
}

// 全小写
QString process2AllLowerCase(const QString &rawTextString) {
    if (rawTextString.isEmpty()) {
        return rawTextString;
    }
    QString processedTextString = rawTextString.toLower();
    return processedTextString;
}

// 首字母大写
QString process2TitleUpperCase(const QString &rawTextString) {
    if (rawTextString.isEmpty()) {
        return rawTextString;
    }
    QStringList partsDivNewLine = rawTextString.split('\n', Qt::SkipEmptyParts);

    QString processedTextString;
    Q_FOREACH(const QString&partDivNewLine, partsDivNewLine) {
        QString preparedStr = partDivNewLine;
        preparedStr = preparedStr.trimmed();
        if(!preparedStr.isEmpty()){
            preparedStr[0] = preparedStr[0].toUpper();
            processedTextString.append(preparedStr);
            processedTextString.append("\n");
        }
    }
    return processedTextString;
}

// 大驼峰转下划线
QString processUpperCamelCase2Underline(const QString &rawTextString){
    if (rawTextString.isEmpty()) {
        return rawTextString;
    }
    QString processedTextString;

    QStringList partsDivNewLine = rawTextString.split('\n', Qt::SkipEmptyParts);
    Q_FOREACH(const QString&partDivNewLine, partsDivNewLine) {
        QString preparedStr = partDivNewLine;
        preparedStr = preparedStr.trimmed();
        if (preparedStr.isEmpty()) {
            continue;
        }

        QString result;
        for (int i = 0; i < preparedStr.length(); ++i) {
            QChar c = preparedStr.at(i);
            if (c.isUpper()) {
                if (i != 0) {
                    result.append('_');
                }
                result.append(c.toLower());
            } else {
                result.append(c);
            }
        }

        if (!processedTextString.isEmpty()) {
            processedTextString.append('\n');
        }
        processedTextString.append(result);
    }
    return processedTextString;
}

// 下划线转小驼峰
void StringProcess::on_btnUnderline2SmallCamelCase_clicked()
{
    QString rawTextString = ui->plainTextEditRaw->toPlainText();
    QString processedTextString = processUnderline2SmallCamelCase(rawTextString);
    ui->textBrowserProcessed->setPlainText(processedTextString);
}


// 复制转换的结果
void StringProcess::on_btnCopyProcessedText_clicked()
{
    QString processedTextString = ui->textBrowserProcessed->toPlainText();
    QClipboard *clip = QApplication::clipboard();
    clip->setText(processedTextString);
}

// 返回主页面
void StringProcess::on_btnBackToMain_clicked()
{
    MainWindow *mainWindowWindow = new MainWindow();
    mainWindowWindow->show();
    this->destroy();
}

// 下划线转大驼峰
void StringProcess::on_btnUnderline2BigCamelCase_clicked()
{
    QString rawTextString = ui->plainTextEditRaw->toPlainText();
    QString processedTextString = processUnderline2BigCamelCase(rawTextString);
    ui->textBrowserProcessed->setPlainText(processedTextString);
}

// 转换成全大写
void StringProcess::on_btn2Upper_clicked()
{
    QString rawTextString = ui->plainTextEditRaw->toPlainText();
    QString processedTextString = process2AllUpperCase(rawTextString);
    ui->textBrowserProcessed->setPlainText(processedTextString);
}

// 转换成全小写
void StringProcess::on_btn2Lower_clicked()
{
    QString rawTextString = ui->plainTextEditRaw->toPlainText();
    QString processedTextString = process2AllLowerCase(rawTextString);
    ui->textBrowserProcessed->setPlainText(processedTextString);
}

// 转换成首字母大写
void StringProcess::on_btnTitleUpperCase_clicked()
{
    QString rawTextString = ui->plainTextEditRaw->toPlainText();
    QString processedTextString = process2TitleUpperCase(rawTextString);
    ui->textBrowserProcessed->setPlainText(processedTextString);
}


// 大驼峰转下划线
void StringProcess::on_btnCamelCase2Underline_clicked()
{
    QString rawTextString = ui->plainTextEditRaw->toPlainText();
    QString processedTextString = processUpperCamelCase2Underline(rawTextString);
    ui->textBrowserProcessed->setPlainText(processedTextString);
}
