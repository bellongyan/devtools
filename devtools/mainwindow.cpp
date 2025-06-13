#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./stringprocess.h"
#include "./encodingdecoding.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 转到字符处理
void MainWindow::on_btnStringProcess_clicked()
{
    StringProcess *stringProcessWindow = new StringProcess();
    stringProcessWindow->setAttribute(Qt::WA_DeleteOnClose);
    connect(stringProcessWindow, &StringProcess::destroyed, this, &MainWindow::show);
    stringProcessWindow->show();
    this->hide();
}

// 转到编解码处理
void MainWindow::on_btnEncoding_clicked()
{
    EncodingDecoding *encodingDecodingWindow = new EncodingDecoding();
    encodingDecodingWindow->setAttribute(Qt::WA_DeleteOnClose);
    connect(encodingDecodingWindow, &EncodingDecoding::destroyed, this, &MainWindow::show);
    encodingDecodingWindow->show();
    this->hide();
}

// 退出应用
void MainWindow::on_btnExit_clicked()
{
    QApplication::quit();
}

