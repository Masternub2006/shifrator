#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    //сделай класс на функции для 1. шифровки, дешифровки и 2. записи в файл(забора из него)
}
