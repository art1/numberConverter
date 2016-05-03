#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    float one = 1.0f;
    uint8_t tmp[4];
    floatToChar(tmp,one);
    qDebug()<<tmp[0]<<tmp[1]<<tmp[2]<<tmp[3];

}

void MainWindow::floatToChar(uint8_t* target, float number){
    char *tmp = (char *) &number;

    for(int i=0;i<4;i++){
        target[i] = tmp[i];
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//binary stuff changed from GUI
void MainWindow::on_lineEdit_bin_textEdited(const QString &arg1)
{
    bool ok;
    if(ui->signed_2->isChecked()){

    } else {
        long val = arg1.toLong(&ok,2);
        if(ok){
            ui->lineEdit_hex->setText(QString::number(val,16));
            ui->lineEdit_dec->setText(QString::number(val));
            QChar c((int)val);
            if(val >=0 && val <=255)ui->lineEdit_ascii->setText(c);
            else ui->lineEdit_ascii->setText("n/a");
        }
    }
}

// hex stuff changed from GUI
void MainWindow::on_lineEdit_hex_textEdited(const QString &arg1)
{
    bool ok;
    if(ui->signed_2->isChecked()){

    } else {
        QString tmp = arg1.toUpper();
        int val = tmp.toInt(&ok,16);
        ui->lineEdit_bin->setText((tmp.setNum(val,2)));
        ui->lineEdit_dec->setText(QString::number(val));
        QChar c(val);
        if(val >=0 && val <=255)ui->lineEdit_ascii->setText(c);
        else ui->lineEdit_ascii->setText("n/a");
    }
}

//dec stuff changed from GUI
void MainWindow::on_lineEdit_dec_textEdited(const QString &arg1)
{
    bool ok;
    if(ui->signed_2->isChecked()){

    } else {
        //        ui->lineEdit_hex->setText(QString::number(arg1.toInt(&ok,16)));
        int val = arg1.toInt(&ok);
        if(ok){
            ui->lineEdit_bin->setText(QString::number(val,2));
            ui->lineEdit_hex->setText(QString::number(val,16));
            QChar c(val);
            if(val >=0 && val <=255)ui->lineEdit_ascii->setText(c);
            else ui->lineEdit_ascii->setText("n/a");
            // convert integer to float representatoin
            float t = (float)val;
            char *tmp = (char *) &t;
            QString u = "";
            for(int i=0;i<4;i++){
                u.append(QString::number((uint8_t)tmp[i]));
                if(tmp[i] == 0) u.append("0");
                u.append(" ");
            }
            ui->lineEdit_float->setText(u);
        }


    }
}

// char stuff
void MainWindow::on_lineEdit_ascii_textEdited(const QString &arg1)
{
    bool ok;
    if(ui->signed_2->isChecked()){

    } else {
        if(arg1.length() > 0){
            QChar c = arg1.at(0);
            int val = arg1.at(0).toLatin1();
            ui->lineEdit_bin->setText(QString::number(val,2));
            ui->lineEdit_hex->setText(QString::number(val,16));
            ui->lineEdit_dec->setText(QString::number(val));

        }
    }
}


// int to float as byte representation!
void MainWindow::on_lineEdit_float_textEdited(const QString &arg1)
{
    bool ok;
    if(ui->signed_2->isChecked()){

    }else{

    }
}



//clicked button signed
void MainWindow::on_signed_2_clicked()
{
    this->changeSign();
}

void MainWindow::on_unsigned_2_clicked()
{
    this->changeSign();
}

void MainWindow::changeSign(){

}




