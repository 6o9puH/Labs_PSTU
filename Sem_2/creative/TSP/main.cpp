#include "tsp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TSP w;
    w.show();
    return a.exec();
}
