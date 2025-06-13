#include "encodingdecoding.h"
#include "ui_encodingdecoding.h"
#include "./mainwindow.h"
#include<QApplication>
#include<QClipboard>

EncodingDecoding::EncodingDecoding(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EncodingDecoding)
{
    ui->setupUi(this);
}

EncodingDecoding::~EncodingDecoding()
{
    delete ui;
}

// 返回主页面
void EncodingDecoding::on_btnBackToMain_clicked()
{
    MainWindow *mainWindowWindow = new MainWindow();
    mainWindowWindow->show();
    this->destroy();
}

// URL编码
void EncodingDecoding::on_btnUrlEncoding_clicked()
{
    QString input = ui->plainTextEditEncodingInput->toPlainText();
    QByteArray encoded = input.toUtf8().toPercentEncoding();
    QString output = QString::fromUtf8(encoded);
    ui->textBrowserEncodingOutput->setText(output);
}


// URL解码
void EncodingDecoding::on_btnUrlDecoding_clicked()
{
    QString input = ui->plainTextEditEncodingInput->toPlainText();
    input.replace('+', "%20");
    QByteArray decoded = QByteArray::fromPercentEncoding(input.toUtf8());
    QString output = QString::fromUtf8(decoded);
    ui->textBrowserEncodingOutput->setText(output);
}

// 复制结果
void EncodingDecoding::on_btnCopyEncoding_clicked()
{

    QString processedTextString = ui->textBrowserEncodingOutput->toPlainText();
    QClipboard *clip = QApplication::clipboard();
    clip->setText(processedTextString);
}

// Base64编码
void EncodingDecoding::on_btnBase64Encoding_clicked()
{

    QString input = ui->plainTextEditEncodingInput->toPlainText();
    QByteArray byteArray = input.toUtf8();
    QByteArray encoded = byteArray.toBase64();
    QString output = QString::fromUtf8(encoded);
    ui->textBrowserEncodingOutput->setText(output);
}

// Base64解码
void EncodingDecoding::on_btnBase64Decoding_clicked()
{
    QString input = ui->plainTextEditEncodingInput->toPlainText();
    QByteArray byteArray = input.toUtf8();
    QByteArray decoded = QByteArray::fromBase64(byteArray);
    QString output = QString::fromUtf8(decoded);
    ui->textBrowserEncodingOutput->setText(output);
}

