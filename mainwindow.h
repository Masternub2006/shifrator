#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include "shifrovka.h"
#include "filetext.h"
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QLabel>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int Zapis();
    int Menyai();
    int Adres();
    int Perevod(bool radiobut);

private:
    QPushButton* sohr;
    QPushButton* mena;
    QTextEdit* vih;
    QTextEdit* vh;
    QTextEdit* Kl;
    QLineEdit* adres;
    QLineEdit* nazv;
    QCheckBox* SohrVFile;
    QComboBox* vibor;
    QRadioButton* rus;
    QRadioButton* eng;
    bool SecretKey = 0;
    bool pere = false;
    bool filebol=false;
    QString filetextov;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
