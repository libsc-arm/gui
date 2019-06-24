#include "mainwindow.h"
#include <QApplication>
#include<iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    std::cout<< "number1\n";
    w.show();

    return a.exec();
}
