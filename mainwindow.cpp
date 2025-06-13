#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./stringprocess.h"

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

void MainWindow::on_btnStringProcess_clicked()
{
    StringProcess *stringProcessWindow = new StringProcess();
    stringProcessWindow->setAttribute(Qt::WA_DeleteOnClose);
    connect(stringProcessWindow, &StringProcess::destroyed, this, &MainWindow::show);
    stringProcessWindow->show();
    this->hide();
}

