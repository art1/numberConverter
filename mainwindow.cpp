#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
        tmp.setNum(val,2);
        // prepend zeroes for better byte readability
        while(((tmp.size() % 8) < 8) && ((tmp.size() % 8) > 0)) tmp.prepend("0");
        for(int i=tmp.size();i>0;i-=8) tmp.insert(i, " ");

        if(!(ui->lineEdit_hex->text() == "")){
            ui->lineEdit_bin->setText(tmp);
            ui->lineEdit_dec->setText(QString::number(val));
            QChar c(val);
            if(val >=0 && val <=255) ui->lineEdit_ascii->setText(c);
            else ui->lineEdit_ascii->setText("n/a");
        } else {
            ui->lineEdit_ascii->clear();
            ui->lineEdit_bin->clear();
            ui->lineEdit_dec->clear();
            ui->lineEdit_float->clear();
        }
    }
}


//dec stuff changed from GUI
void MainWindow::on_lineEdit_dec_textEdited(const QString &arg1)
{
    bool ok;
    if(ui->signed_2->isChecked()){

    } else {
        QString u = "";
        int val = arg1.toInt(&ok);
        if(ok){
            QString temp = QString::number(val,2);
            while(((temp.size() % 8) < 8) && ((temp.size() % 8) > 0)) temp.prepend("0");
            for(int i=temp.size();i>0;i-=8) temp.insert(i, " ");
            ui->lineEdit_bin->setText(temp);
            ui->lineEdit_hex->setText(QString::number(val,16));

            QChar c(val);
            if(val >=0 && val <=255)ui->lineEdit_ascii->setText(c);
            else ui->lineEdit_ascii->setText("n/a");

            // convert integer to float representatoin
            float t = (float)val;
            char *tmp = (char *) &t;
            for(int i=0;i<4;i++){
                u.append(QString::number((uint8_t)tmp[i]));
                if(tmp[i] == 0) u.append("0");
                u.append(" ");
            }
        } else {
            float val = arg1.toFloat(&ok);
            if(ok){
                // convert float to float representatoin in bytes
                char *tmp = (char *) &val;
                for(int i=0;i<4;i++){
                    u.append(QString::number((uint8_t)tmp[i]));
                    if(tmp[i] == 0) u.append("0");
                    u.append(" ");
                }
            }
            // set other vals to n/a or zero, cause floats in hex/bin -> nah not needed now
            ui->lineEdit_ascii->setText("n/a");
            ui->lineEdit_bin->clear();
            ui->lineEdit_hex->clear();
        }
        ui->lineEdit_float->setText(u);
    }
}


// char stuff
void MainWindow::on_lineEdit_ascii_textEdited(const QString &arg1)
{
    if(ui->signed_2->isChecked()){

    } else {
        if(arg1.length() > 0){
            int val = arg1.at(0).toLatin1();
            ui->lineEdit_bin->setText(QString::number(val,2));
            ui->lineEdit_hex->setText(QString::number(val,16));
            ui->lineEdit_dec->setText(QString::number(val));
            ui->lineEdit_dec->insert("");

        }
    }
}


// int to float as byte representation!
void MainWindow::on_lineEdit_float_textEdited(const QString &arg1)
{
    if(ui->signed_2->isChecked()){

    }else{
        QStringList vals = ui->lineEdit_float->text().split(QRegExp("\\s"));
        if(vals.size() == 4){
            bool ok = true;
            bool tmp = false;
            // check if input valid bytes
            for(int i=0;i<4;i++){
                if(vals.at(i).toInt(&tmp) >= 255) tmp = false;
                ok &= tmp;
            }
            if(ok){
                float out;
                uint8_t * ptr = (uint8_t *) &out;
                for(int i=0;i<4;i++) ptr[i] = vals.at(i).toInt();
                ui->lineEdit_dec->setText(QString::number(out));
            } else ui->lineEdit_dec->clear();
        }

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




