#include "filetext.h"
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QTextStream>

FileText::FileText()
{

}

QString FileText::Vsyat(QString vvod)
{
    QString text="";
    QString vivod="";
    for(int i = 0; i<vvod.length(); i++)
    {
        if(vvod[i]=="\\")
        {
            text+="/";
        }
        else
        {
            if(vvod[i]!="\"")
            {
                text+=vvod[i];
            }
        }
    }
    QFile file(text);
    if(!file.open(QIODevice::ReadOnly))
    {
        return "Error with the capture file";
    }
    vivod=file.readAll();
    file.close();
    return vivod;
}

QString FileText::Zapisat(QString vivod, QString adres, QString namef)
{
    QString adresend="";
    for(int i = 0; i<adres.length(); i++)
    {
        if(adres[i]=="\\")
        {
            adresend+="/";
        }
        else
        {
            if(adres[i]!="\"")
            {
                adresend+=adres[i];
            }
        }
    }
    if(adresend[adresend.length()-1]=="/")
    {
        adresend+=namef+".txt";
    }
    else
    {
        adresend+="/"+namef+".txt";
    }
    QFile file(adresend);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return "Error with the save file";
    }
    //file.write(vivod);
    //file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out<<vivod;
    file.close();
    return "Saved in your file";
}
