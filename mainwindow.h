#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void floatToChar(uint8_t* target, float number);

private slots:
    void on_lineEdit_bin_textEdited(const QString &arg1);

    void on_lineEdit_hex_textEdited(const QString &arg1);

    void on_lineEdit_dec_textEdited(const QString &arg1);

    void on_signed_2_clicked();

    void on_unsigned_2_clicked();

    void on_lineEdit_ascii_textEdited(const QString &arg1);

    void on_lineEdit_float_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void changeSign();
};

#endif // MAINWINDOW_H
