#ifndef ENCODINGDECODING_H
#define ENCODINGDECODING_H

#include <QWidget>

namespace Ui {
class EncodingDecoding;
}

class EncodingDecoding : public QWidget
{
    Q_OBJECT

public:
    explicit EncodingDecoding(QWidget *parent = nullptr);
    ~EncodingDecoding();

private slots:
    void on_btnBackToMain_clicked();

    void on_btnUrlEncoding_clicked();

    void on_btnUrlDecoding_clicked();

    void on_btnCopyEncoding_clicked();

    void on_btnBase64Encoding_clicked();

    void on_btnBase64Decoding_clicked();

private:
    Ui::EncodingDecoding *ui;
};

#endif // ENCODINGDECODING_H
