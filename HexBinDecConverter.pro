#-------------------------------------------------
#
# Project created by QtCreator 2015-12-24T16:21:07
#
#-------------------------------------------------
QMAKE_MAC_SDK = macosx10.12

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HexBinDecConverter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    converter.cpp

HEADERS  += mainwindow.h \
    converter.h

FORMS    += mainwindow.ui
