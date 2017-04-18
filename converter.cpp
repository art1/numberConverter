#include "converter.h"
#include "QStringList"
#include "QRegExp"

converter::converter()
{

}



void converter::convBin8(QString _arg)
{
    bool ok;
    long val = _arg.toLong(&ok,2);
    if(ok){
        emit updateHex(QString::number(val,16));
        emit updateDec(QString::number(val));
        QChar c((int)val);
        if(val >=0 && val <=255) updateASCII(c);
        else emit updateASCII("n/a");
    }
}

void converter::convBin16(QString _arg)
{

}

void converter::convBin32(QString _arg)
{

}

void converter::convFloatMem(QString _arg)
{
    bool ok;
    QStringList vals = _arg.split(QRegExp("\\s"));
    if(vals.size() == 4){
        ok = true;
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
            emit updateDec(QString::number(out));
        } else emit updateDec("");
    }
}

void converter::convHex(QString _arg)
{
    bool ok;
    QString tmp = _arg.toUpper();
    int val = tmp.toInt(&ok,16);
    tmp.setNum(val,2);
    // prepend zeroes for better byte readability
    while(((tmp.size() % 8) < 8) && ((tmp.size() % 8) > 0)) tmp.prepend("0");
    for(int i=tmp.size();i>0;i-=8) tmp.insert(i, " ");

    if(!(_arg == "")){
        emit updateBin8(tmp);
        emit updateDec(QString::number(val));
        QChar c(val);
        if(val >=0 && val <=255) emit updateASCII(c);
        else emit updateASCII("n/a");
    } else {
        emit updateASCII("");
        emit updateBin8("");
        emit updateDec("");
        emit updateFloatMem("");
    }
}

void converter::convASCII(QString _arg)
{
    if(_arg.length() > 0){
        int val = _arg.at(0).toLatin1();
        emit updateBin8(QString::number(val,2));
        emit updateHex(QString::number(val,16));
        emit updateDec(QString::number(val));
//        emit updateDec("");

    }
}

void converter::convDec(QString _arg)
{
    bool ok;
    QString u = "";
    int val = _arg.toInt(&ok);
    if(ok){
        QString temp = QString::number(val,2);
        while(((temp.size() % 8) < 8) && ((temp.size() % 8) > 0)) temp.prepend("0");
        for(int i=temp.size();i>0;i-=8) temp.insert(i, " ");
        emit updateBin8(temp);
        emit updateHex(QString::number(val,16));

        QChar c(val);
        if(val >=0 && val <=255) emit updateASCII(c);
        else emit updateASCII("n/a");

        // convert integer to float representatoin
        float t = (float)val;
        char *tmp = (char *) &t;
        for(int i=0;i<4;i++){
            u.append(QString::number((uint8_t)tmp[i]));
            if(tmp[i] == 0) u.append("0");
            u.append(" ");
        }
    } else {
        float val = _arg.toFloat(&ok);
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
        emit updateASCII("n/a");
        emit updateBin8("");
        emit updateHex("");
    }
    emit updateFloatMem(u);
}
