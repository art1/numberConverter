#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>

class converter : public QObject
{
    Q_OBJECT
public:
    converter();

signals:
    void updateBin8(QString);
    void updateBin16(QString);
    void updateBin32(QString);
    void updateFloatMem(QString);
    void updateHex(QString);
    void updateASCII(QString);
    void updateDec(QString);

public slots:
    void convBin8(QString _arg);
    void convBin16(QString _arg);
    void convBin32(QString _arg);
    void convFloatMem(QString _arg);
    void convHex(QString _arg);
    void convASCII(QString _arg);
    void convDec(QString _arg);
};

#endif // CONVERTER_H
