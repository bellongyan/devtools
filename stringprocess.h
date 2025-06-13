#ifndef STRINGPROCESS_H
#define STRINGPROCESS_H
#include<QLabel>

#include <QWidget>

namespace Ui {
class StringProcess;
}

class StringProcess : public QWidget
{
    Q_OBJECT

public:
    explicit StringProcess(QWidget *parent = nullptr);
    ~StringProcess();

private slots:
    void on_btnUnderline2SmallCamelCase_clicked();

    void on_btnCopyProcessedText_clicked();

    void on_btnBackToMain_clicked();

    void on_btnUnderline2BigCamelCase_clicked();

    void on_btn2Upper_clicked();

    void on_btn2Lower_clicked();

    void on_btnTitleUpperCase_clicked();

    void on_btnCamelCase2Underline_clicked();

private:
    Ui::StringProcess *ui;
};

#endif // STRINGPROCESS_H
