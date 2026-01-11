#ifndef SHIFROVKA_H
#define SHIFROVKA_H

#pragma once
#include "mainwindow.h"
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>

//QT_BEGIN_NAMESPACE
//namespace Ui {class MainWindow;}
//QT_END_NAMESPACE

class shifrovka// : public QMainWindow
{
    //Q_OBJECT
public:
    shifrovka();
    QString Cezar(QString vvod, int sdvig);
    QString Vizher(QString vvod, QString kluch);
    QString Morze(QString vvod);
    QString Polibi(QString vvod);
    QString CezarDec(QString vvod, int sdvig);
    QString VizherDec(QString vvod, QString kluch);
    QString MorzeDec(QString vvod);
    QString PolibiDec(QString vvod);
    QString CezarRus(QString vvod, int sdvig);
    QString VizherRus(QString vvod, QString kluch);
    QString MorzeRus(QString vvod);
    QString PolibiRus(QString vvod);
    QString CezarDecRus(QString vvod, int sdvig);
    QString VizherDecRus(QString vvod, QString kluch);
    QString MorzeDecRus(QString vvod);
    QString PolibiDecRus(QString vvod);
    QString Gaster(QString vvod);
private:
    //QTextEdit *viv;
    //Ui::MainWindow *ui;
};

#endif // SHIFROVKA_H
