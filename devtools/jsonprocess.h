#ifndef JSONPROCESS_H
#define JSONPROCESS_H

#include <QWidget>

namespace Ui {
class JsonProcess;
}

class JsonProcess : public QWidget
{
    Q_OBJECT

public:
    explicit JsonProcess(QWidget *parent = nullptr);
    ~JsonProcess();

private slots:
    void on_btnBackToMain_clicked();

    void on_btnJsonFormat_clicked();

    void on_btnJsonCompress_clicked();

    void on_btnCopyProcessedText_clicked();

private:
    Ui::JsonProcess *ui;
};

#endif // JSONPROCESS_H
