#include "mainwindow.h"
#include "password.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Password w;
    w.show();
    return a.exec();
}
