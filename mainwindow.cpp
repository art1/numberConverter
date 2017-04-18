#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conv = new converter();
    // -> that way
    connect(ui->lineEdit_ascii,SIGNAL(textEdited(QString)),conv,SLOT(convASCII(QString)));
    connect(ui->lineEdit_dec,SIGNAL(textEdited(QString)),conv,SLOT(convDec(QString)));
    connect(ui->lineEdit_float,SIGNAL(textEdited(QString)),conv,SLOT(convFloatMem(QString)));
    connect(ui->lineEdit_hex,SIGNAL(textEdited(QString)),conv,SLOT(convHex(QString)));
    connect(ui->lineEdit_int8,SIGNAL(textEdited(QString)),conv,SLOT(convBin8(QString)));
    connect(ui->lineEdit_int16,SIGNAL(textEdited(QString)),conv,SLOT(convBin16(QString)));
    connect(ui->lineEdit_int32,SIGNAL(textEdited(QString)),conv,SLOT(convBin32(QString)));

    // <- this way
    connect(conv,SIGNAL(updateASCII(QString)),ui->lineEdit_ascii,SLOT(setText(QString)));
    connect(conv,SIGNAL(updateDec(QString)),ui->lineEdit_dec,SLOT(setText(QString)));
    connect(conv,SIGNAL(updateFloatMem(QString)),ui->lineEdit_float,SLOT(setText(QString)));
    connect(conv,SIGNAL(updateHex(QString)),ui->lineEdit_hex,SLOT(setText(QString)));
    connect(conv,SIGNAL(updateBin8(QString)),ui->lineEdit_int8,SLOT(setText(QString)));
    connect(conv,SIGNAL(updateBin16(QString)),ui->lineEdit_int16,SLOT(setText(QString)));
    connect(conv,SIGNAL(updateBin32(QString)),ui->lineEdit_int32,SLOT(setText(QString)));
}


MainWindow::~MainWindow()
{
    delete ui;
}
