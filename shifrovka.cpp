#pragma once
#include "shifrovka.h"
#include "mainwindow.h"
#include <string>
#include <QString>
#include <QChar>
#include <Qmap>
//#include <bool>

shifrovka::shifrovka()
{

}

QString shifrovka::Cezar(QString vvod, int sdvig)
{
    bool a = false;
    //int b = 0;
    QString shifr="";
    QString alphavit = "abcdefghigklmnopqrstuvwxyz";
    QString vv = vvod;
    vvod = vvod.toLower();
    for(int i = 0; i<vvod.length(); i++)
    {
        if (vvod[i]=="\n")
        {
            shifr.append("\n");
        }
        else
        {
            for(int l = 0; l<alphavit.length(); l++)
            {
                if(vvod[i]==alphavit[l])
                {
                    a=true;
                    //b=l+sdvig;
                    if(alphavit.length()<=l+sdvig)
                    {
                        l-=alphavit.length();
                    }
                    if(QChar(vv[i]).isUpper())
                    {
                        shifr.append(alphavit[l+sdvig].toUpper());
                    }
                    else
                    {
                        shifr.append(alphavit[l+sdvig]);
                    }
                    break;
                }

            }
            if(!a)
            {
                shifr.append(vvod[i]);
            }
            a=false;
        }
    }
    return shifr;
}

QString shifrovka::Vizher(QString vvod, QString kluch)
{
    int a = 0;
    bool b = 0;
    int c = 0;
    int i = 0;
    bool k = 0;
    int y = 0;
    QString shifr="";
    QString alphavit = "abcdefghigklmnopqrstuvwxyz";
    QString vv = vvod;
    vvod = vvod.toLower();
    kluch = kluch.toLower();
    while(i<vvod.length())
    {
        if (vvod[i]=="\n")
        {
            shifr.append("\n");
            i++;
        }
        else
        {
            for(int l = 0; l<alphavit.length(); l++)
            {
                if(kluch[a]==alphavit[l])
                {
                    b=1;
                    c=l;
                    break;
                }
            }
            if(b)
            {
                for(int l = 0; l<alphavit.length(); l++)
                {
                    if(vvod[i]==alphavit[l])
                    {
                        if(l+c>=alphavit.length())
                        {
                            l-=alphavit.length();
                        }
                        if(QChar(vv[i]).isUpper())
                        {
                            shifr.append(alphavit[l+c].toUpper());
                        }
                        else
                        {
                            shifr.append(alphavit[l+c]);
                        }
                        k=1;
                        break;
                    }
                }
                if(!k)
                {
                    shifr.append(vvod[i]);
                }
                i++;
                k=0;
                y=0;
            }
            else
            {
                y++;
                if(y>=kluch.length())
                {
                    return "Введите правильный ключ";
                }
            }
            a++;
            if(a==kluch.length())
            {
                a=0;
            }
            b=0;
        }
    }
    return shifr;
}

QString shifrovka::Morze(QString vvod)
{
    QMap<QString, QString> alphavit = {{"a", "*-"}, {"b", "-***"}, {"c", "-*-*"}, {"d", "-**"}, {"e", "*"}, {"f", "**-*"}, {"g", "--*"}, {"h", "****"}, {"i", "**"},
    {"j", "*---"}, {"k", "-*-"}, {"l", "*-**"}, {"m", "--"}, {"n", "-*"}, {"o", "---"}, {"p", "*--*"}, {"q", "--*-"}, {"r", "*-*"}, {"s", "***"}, {"t", "-"},
    {"u", "**-"}, {"v", "***-"}, {"w", "*--"}, {"x", "-**-"}, {"y", "-*--"}, {"z", "--**"}, {" ", "   "}, {"\n", "\n"},
    {"1", "*----"}, {"2", "**---"}, {"3", "***--"}, {"4", "****-"}, {"5", "*****"}, {"6", "-****"}, {"7", "--***"}, {"8", "---**"}, {"9", "----*"}, {"0", "-----"}};
    QString shifr = "";
    vvod = vvod.toLower();
    for(int i = 0; i<vvod.length(); i++)
    {
        if(alphavit.find(vvod[i])!=alphavit.end())
        {
            if(alphavit.find(vvod[i])==alphavit.find(" "))
            {
                shifr.append(alphavit.value(vvod[i]));
            }
            else
            {
                if(i+1<vvod.length())
                {
                    if(alphavit.find(vvod[i+1])==alphavit.find(" "))
                    {
                        shifr.append(alphavit.value(vvod[i]));
                    }
                    else
                    {
                        shifr.append(alphavit.value(vvod[i]));
                        shifr.append("  ");
                    }
                }
                else
                {
                    shifr.append(alphavit.value(vvod[i]));
                }
            }
        }

    }
    return shifr;
}

QString shifrovka::Polibi(QString vvod)
{
    QMap<QString, QString> alphavit = {{"a", "11"}, {"b", "12"}, {"c", "13"}, {"d", "14"}, {"e", "15"}, {"f", "21"}, {"g", "22"}, {"h", "23"}, {"i", "24"}, {"j", "24"},
    {"k", "25"}, {"l", "31"}, {"m", "32"}, {"n", "33"}, {"o", "34"}, {"p", "35"}, {"q", "41"}, {"r", "42"}, {"s", "43"}, {"t", "44"}, {"u", "45"}, {"v", "51"},
    {"w", "52"}, {"x", "53"}, {"y", "54"}, {"z", "55"}, {" ", " "}, {".", "."}, {"!", "!"}, {",", ","}, {"!", "!"}, {"\n", "\n"}};
    QString shifr = "";
    vvod = vvod.toLower();
    for(int i = 0; i<vvod.length(); i++)
    {
        if(alphavit.find(vvod[i])!=alphavit.end())
        {
            shifr.append(alphavit.value(vvod[i]));
        }
        /*else
        {
            shifr.append(vvod[i]);
        }//*/
    }
    return shifr;
}

QString shifrovka::CezarDec(QString vvod, int sdvig)
{
    bool a = 0;
    //int b = 0;
    QString shifr="";
    QString alphavit = "abcdefghigklmnopqrstuvwxyz";
    QString vv = vvod;
    vvod = vvod.toLower();
    for(int i = 0; i<vvod.length(); i++)
    {
        if (vvod[i]=="\n")
        {
            shifr.append("\n");
        }
        else
        {
            for(int l = 0; l<alphavit.length(); l++)
            {
                if(vvod[i]==alphavit[l])
                {
                    a=1;
                    //b=l+sdvig;
                    if(l-sdvig<0)
                    {
                        l+=alphavit.length();
                    }
                    if(QChar(vv[i]).isUpper())
                    {
                        shifr.append(alphavit[l-sdvig].toUpper());
                    }
                    else
                    {
                        shifr.append(alphavit[l-sdvig]);
                    }
                    break;
                }
            }
            if(!a)
            {
                shifr.append(vvod[i]);
            }
            a=0;
        }
    }
    return shifr;
}

QString shifrovka::VizherDec(QString vvod, QString kluch)
{
    int a = 0;
    bool b = 0;
    int c = 0;
    int i = 0;
    bool k = 0;
    int y = 0;
    QString shifr="";
    QString alphavit = "abcdefghigklmnopqrstuvwxyz";
    QString vv = vvod;
    vvod = vvod.toLower();
    kluch = kluch.toLower();
    while(i<vvod.length())
    {
        if (vvod[i]=="\n")
        {
            shifr.append("\n");
            i++;
        }
        else
        {
            for(int l = 0; l<alphavit.length(); l++)
            {
                if(kluch[a]==alphavit[l])
                {
                    b=1;
                    c=l;
                    break;
                }
            }
            if(b)
            {
                for(int l = 0; l<alphavit.length(); l++)
                {
                    if(vvod[i]==alphavit[l])
                    {
                        if(l-c<0)
                        {
                            l+=alphavit.length();
                        }
                        if(QChar(vv[i]).isUpper())
                        {
                            shifr.append(alphavit[l-c].toUpper());
                        }
                        else
                        {
                            shifr.append(alphavit[l-c]);
                        }
                        k=1;
                        break;
                    }
                }
                if(!k)
                {
                    shifr.append(vvod[i]);
                }
                i++;
                k=0;
                y=0;
            }
            else
            {
                y++;
                if(y>=kluch.length())
                {
                    return "Введите правильный ключ";
                }
            }
            a++;
            if(a==kluch.length())
            {
                a=0;
            }
            b=0;
        }
    }
    return shifr;
}

QString shifrovka::MorzeDec(QString vvod)
{
    QMap<QString, QString> alphavit ={{"*-", "a"}, {"-***", "b"}, {"-*-*", "c"}, {"-**", "d"}, {"*", "e"}, {"**-*", "f"}, {"--*", "g"}, {"****", "h"}, {"**", "i"},
    {"*---", "j"}, {"-*-", "k"}, {"*-**", "l"}, {"--", "m"}, {"-*", "n"}, {"---", "o"}, {"*--*", "p"}, {"--*-", "q"}, {"*-*", "r"}, {"***", "s"}, {"-", "t"},
    {"**-", "u"}, {"***-", "v"}, {"*--", "w"}, {"-**-", "x"}, {"-*--", "y"}, {"--**", "z"},
    {"*----", "1"}, {"**---", "2"}, {"***--", "3"}, {"****-", "4"}, {"*****", "5"}, {"-****", "6"}, {"--***", "7"}, {"---**", "8"}, {"----*", "9"}, {"-----", "0"}};
    QString shifr = "";
    bool a = 0;
    int b = 2;
    QString c = "";
    for(int i = 0; i<vvod.length(); i++)
    {
        if(vvod[i]==" ")
        {
            if(alphavit.find(c)!=alphavit.end())
            {
                shifr.append(alphavit.value(c));
                b=0;
            }
            c = "";
            while(true)
            {
                if (b>=2)
                {
                    shifr.append(" ");
                }
                i++;
                b++;
                if(i>=vvod.length()&&!a)
                {
                    return "";
                }
                if(i>=vvod.length())
                {
                    return shifr;
                }
                if(vvod[i]!=" ")
                {
                    break;
                }
            }
        }
        if(vvod[i]=="\n")
        {
            shifr.append("\n");
        }
        if(vvod[i]=="*"||vvod[i]=="-")
        {
            c+=vvod[i];
            a=1;
        }
        b=2;
    }
    if(alphavit.find(c)!=alphavit.end())
    {
        shifr.append(alphavit.value(c));
        b=0;
    }
    return shifr;
}

QString shifrovka::PolibiDec(QString vvod)
{
    QMap<QString, QString> alphavit = {{"11", "a"}, {"12", "b"}, {"13", "c"}, {"14", "d"}, {"15", "e"}, {"21", "f"}, {"22", "g"}, {"23", "h"}, {"24", "i"},
    {"25", "k"}, {"31", "l"}, {"32", "m"}, {"33", "n"}, {"34", "o"}, {"35", "p"}, {"41", "q"}, {"42", "r"}, {"43", "s"}, {"44", "t"}, {"45", "u"}, {"51", "v"},
    {"52", "w"}, {"53", "x"}, {"54", "y"}, {"55", "z"}, {".", "."}, {"!", "!"}, {",", ","}, {"!", "!"}, {"\n", "\n"}};
    QString shifr = "";
    for(int i = 0; i<vvod.length(); i++)
    {
        if(vvod[i]==" ")
        {
            shifr.append(" ");
        }
        else
        {
            if (vvod[i]=="\n")
            {
                shifr.append("\n");
            }
            else
            {
                if(i+1<vvod.length())
                {
                    if(alphavit.find(vvod.mid(i, 2))!=alphavit.end())
                    {
                        shifr.append(alphavit.value(vvod.mid(i, 2)));
                        i++;
                    }
                }
            }
        }
    }
    return shifr;
}

QString shifrovka::CezarRus(QString vvod, int sdvig)
{
    bool a = false;
    //int b = 0;
    QString shifr="";
    QString alphavit = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString vv = vvod;
    vvod = vvod.toLower();
    for(int i = 0; i<vvod.length(); i++)
    {
        if (vvod[i]=="\n")
        {
            shifr.append("\n");
        }
        else
        {
            for(int l = 0; l<alphavit.length(); l++)
            {
                if(vvod[i]==alphavit[l])
                {
                    a=true;
                    //b=l+sdvig;
                    if(alphavit.length()<=l+sdvig)
                    {
                        l-=alphavit.length();
                    }
                    if(QChar(vv[i]).isUpper())
                    {
                        shifr.append(alphavit[l+sdvig].toUpper());
                    }
                    else
                    {
                        shifr.append(alphavit[l+sdvig]);
                    }
                    break;
                }
            }
            if(!a)
            {
                shifr.append(vvod[i]);
            }
            a=false;
        }
    }
    return shifr;
}

QString shifrovka::VizherRus(QString vvod, QString kluch)
{
    int a = 0;
    bool b = 0;
    int c = 0;
    int i = 0;
    bool k = 0;
    int y = 0;
    QString shifr="";
    QString alphavit = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString vv = vvod;
    vvod = vvod.toLower();
    kluch = kluch.toLower();
    while(i<vvod.length())
    {
        if (vvod[i]=="\n")
        {
            shifr.append("\n");
            i++;
        }
        else
        {
            for(int l = 0; l<alphavit.length(); l++)
            {
                if(kluch[a]==alphavit[l])
                {
                    b=1;
                    c=l;
                    break;
                }
            }
            if(b)
            {
                for(int l = 0; l<alphavit.length(); l++)
                {
                    if(vvod[i]==alphavit[l])
                    {
                        if(l+c>=alphavit.length())
                        {
                            l-=alphavit.length();
                        }
                        if(QChar(vv[i]).isUpper())
                        {
                            shifr.append(alphavit[l+c].toUpper());
                        }
                        else
                        {
                            shifr.append(alphavit[l+c]);
                        }
                        k=1;
                        break;
                    }
                }
                if(!k)
                {
                    shifr.append(vvod[i]);
                }
                i++;
                k=0;
                y=0;
            }
            else
            {
                y++;
                if(y>=kluch.length())
                {
                    return "Введите правильный ключ";
                }
            }
            a++;
            if(a==kluch.length())
            {
                a=0;
            }
            b=0;
        }
    }
    return shifr;
}

QString shifrovka::MorzeRus(QString vvod)
{
    QMap<QString, QString> alphavit = {{"а", "*-"}, {"б", "-***"}, {"в", "*--"}, {"г", "--*"}, {"д", "-**"}, {"е", "*"}, {"ё", "*"}, {"ж", "***-"}, {"з", "--**"}, {"и", "**"},
    {"й", "*---"}, {"к", "-*-"}, {"л", "*-**"}, {"м", "--"}, {"н", "-*"}, {"о", "---"}, {"п", "*--*"}, {"р", "*-*"}, {"с", "***"}, {"т", "-"}, {"у", "**-"}, {"ф", "**-*"},
    {"х", "****"}, {"ц", "-*-*"}, {"ч", "---*"}, {"ш", "----"}, {"щ", "--*-"}, {"ъ", "*--*-*"}, {"ы", "-*--"}, {"ь", "-**-"}, {"э", "**-**"}, {"ю", "**--"}, {"я", "*-*-"}, {" ", "   "},
    {"1", "*----"}, {"2", "**---"}, {"3", "***--"}, {"4", "****-"}, {"5", "*****"}, {"6", "-****"}, {"7", "--***"}, {"8", "---**"}, {"9", "----*"}, {"0", "-----"}, {"\n", "\n"}};
    QString shifr = "";
    vvod = vvod.toLower();
    for(int i = 0; i<vvod.length(); i++)
    {
        if(alphavit.find(vvod[i])!=alphavit.end())
        {
            if(alphavit.find(vvod[i])==alphavit.find(" "))
            {
                shifr.append(" ");
            }
            else
            {
                if(i+1<vvod.length())
                {
                    if(alphavit.find(vvod[i+1])==alphavit.find(" "))
                    {
                        shifr.append(alphavit.value(vvod[i]));
                    }
                    else
                    {
                        shifr.append(alphavit.value(vvod[i]));
                        shifr.append("  ");
                    }
                }
                else
                {
                    shifr.append(alphavit.value(vvod[i]));
                }
            }
        }

    }
    return shifr;
}

QString shifrovka::PolibiRus(QString vvod)
{
    QMap<QString, QString> alphavit = {{" ", " "}, {"а", "11"}, {"б", "12"}, {"в", "13"}, {"г", "14"}, {"д", "15"}, {"е", "16"}, {"ё", "21"}, {"ж", "22"}, {"з", "23"}, {"и", "24"},
    {"й", "25"}, {"к", "26"}, {"л", "31"}, {"м", "32"}, {"н", "33"}, {"о", "34"}, {"п", "35"}, {"р", "36"}, {"с", "41"}, {"т", "42"}, {"у", "43"}, {"ф", "44"}, {"х", "45"},
    {"ц", "46"}, {"ч", "51"}, {"ш", "52"}, {"щ", "53"}, {"ъ", "54"}, {"ы", "55"}, {"ь", "56"}, {"э", "61"}, {"ю", "62"}, {"я", "63"}, {",", "64"}, {".", "65"}, {"-", "66"}, {"\n", "\n"}};
    QString shifr = "";
    vvod = vvod.toLower();
    for(int i = 0; i<vvod.length(); i++)
    {
        if(alphavit.find(vvod[i])!=alphavit.end())
        {
            shifr.append(alphavit.value(vvod[i]));
        }

    }
    return shifr;
}

QString shifrovka::CezarDecRus(QString vvod, int sdvig)
{
    bool a = 0;
    //int b = 0;
    QString shifr="";
    QString alphavit = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString vv = vvod;
    vvod = vvod.toLower();
    for(int i = 0; i<vvod.length(); i++)
    {
        if (vvod[i]=="\n")
        {
            shifr.append("\n");
        }
        else
        {
            for(int l = 0; l<alphavit.length(); l++)
            {
                if(vvod[i]==alphavit[l])
                {
                    a=1;
                    //b=l+sdvig;
                    if(l-sdvig<0)
                    {
                        l+=alphavit.length();
                    }
                    if(QChar(vv[i]).isUpper())
                    {
                        shifr.append(alphavit[l-sdvig].toUpper());
                    }
                    else
                    {
                        shifr.append(alphavit[l-sdvig]);
                    }
                    break;
                }
            }
            if(!a)
            {
                shifr.append(vvod[i]);
            }
            a=0;
        }
    }
    return shifr;
}

QString shifrovka::VizherDecRus(QString vvod, QString kluch)
{
    int a = 0;
    bool b = 0;
    int c = 0;
    int i = 0;
    bool k = 0;
    int y = 0;
    QString shifr="";
    QString alphavit = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    QString vv = vvod;
    vvod = vvod.toLower();
    kluch = kluch.toLower();
    while(i<vvod.length())
    {
        if (vvod[i]=="\n")
        {
            shifr.append("\n");
            i++;
        }
        else
        {
            for(int l = 0; l<alphavit.length(); l++)
            {
                if(kluch[a]==alphavit[l])
                {
                    b=1;
                    c=l;
                    break;
                }
            }
            if(b)
            {
                for(int l = 0; l<alphavit.length(); l++)
                {
                    if(vvod[i]==alphavit[l])
                    {
                        if(l-c<0)
                        {
                            l+=alphavit.length();
                        }
                        if(QChar(vv[i]).isUpper())
                        {
                            shifr.append(alphavit[l-c].toUpper());
                        }
                        else
                        {
                            shifr.append(alphavit[l-c]);
                        }
                        k=1;
                        break;
                    }
                }
                if(!k)
                {
                    shifr.append(vvod[i]);
                }
                i++;
                k=0;
                y=0;
            }
            else
            {
                y++;
                if(y>=kluch.length())
                {
                    return "Введите правильный ключ";
                }
            }
            a++;
            if(a==kluch.length())
            {
                a=0;
            }
            b=0;
        }
    }
    return shifr;
}

QString shifrovka::MorzeDecRus(QString vvod)
{
    QMap<QString, QString> alphavit = {{"*-", "а"}, {"-***", "б"}, {"*--", "в"}, {"--*", "г"}, {"-**", "д"}, {"*", "е"}, {"***-", "ж"}, {"--**", "з"}, {"**", "и"},
    {"*---", "й"}, {"-*-", "к"}, {"*-**", "л"}, {"--", "м"}, {"-*", "н"}, {"---", "о"}, {"*--*", "п"}, {"*-*", "р"}, {"***", "с"}, {"-", "т"}, {"**-", "у"}, {"**-*", "ф"},
    {"****", "х"}, {"-*-*", "ц"}, {"---*", "ч"}, {"----", "ш"}, {"--*-", "щ"}, {"*--*-*", "ъ"}, {"-*--", "ы"}, {"-**-", "ь"}, {"**-**", "э"}, {"**--", "ю"}, {"*-*-", "я"},
    {"*----", "1"}, {"**---", "2"}, {"***--", "3"}, {"****-", "4"}, {"*****", "5"}, {"-****", "6"}, {"--***", "7"}, {"---**", "8"}, {"----*", "9"}, {"-----", "0"}};
    QString shifr = "";
    bool a = 0;
    int b = 2;
    QString c = "";
    for(int i = 0; i<vvod.length(); i++)
    {
        if(vvod[i]==" ")
        {
            if(alphavit.find(c)!=alphavit.end())
            {
                shifr.append(alphavit.value(c));
                b=0;
            }
            c = "";
            while(true)
            {
                if (b>=2)
                {
                    shifr.append(" ");
                }
                i++;
                b++;
                if(i>=vvod.length()&&!a)
                {
                    return "";
                }
                if(i>=vvod.length())
                {
                    return shifr;
                }
                if(vvod[i]!=" ")
                {
                    break;
                }
            }
        }
        if(vvod[i]=="*"||vvod[i]=="-")
        {
            c+=vvod[i];
            a=1;
        }
        b=2;
    }
    if(alphavit.find(c)!=alphavit.end())
    {
        shifr.append(alphavit.value(c));
        b=0;
    }
    return shifr;
}

QString shifrovka::PolibiDecRus(QString vvod)
{
    QMap<QString, QString> alphavit = {{"11", "а"}, {"12", "б"}, {"13", "в"}, {"14", "г"}, {"15", "д"}, {"16", "е"}, {"21", "ё"}, {"22", "ж"}, {"23", "з"}, {"24", "и"},
    {"25", "й"}, {"26", "к"}, {"31", "л"}, {"32", "м"}, {"33", "н"}, {"34", "о"}, {"35", "п"}, {"36", "р"}, {"41", "с"}, {"42", "т"}, {"43", "у"}, {"44", "ф"}, {"45", "х"},
    {"46", "ц"}, {"51", "ч"}, {"52", "ш"}, {"53", "щ"}, {"54", "ъ"}, {"55", "ы"}, {"56", "ь"}, {"61", "э"}, {"62", "ю"}, {"63", "я"}, {"64", ","}, {"65", "."}, {"66", "-"}, {"\n", "\n"}};
    QString shifr = "";
    for(int i = 0; i<vvod.length(); i++)
    {
        if(vvod[i]==" ")
        {
            shifr.append(" ");
        }
        else
        {
            if (vvod[i]=="\n")
            {
                shifr.append("\n");
            }
            else
            {
                if(i+1<vvod.length())
                {
                    if(alphavit.find(vvod.mid(i, 2))!=alphavit.end())
                    {
                        shifr.append(alphavit.value(vvod.mid(i, 2)));
                        i++;
                    }
                }
            }
        }
    }
    return shifr;
}

QString shifrovka::Gaster(QString vvod)
{
    return "System exit...";
}

/*shifrovka::~shifrovka()
{
    delete viv;
}//*/
