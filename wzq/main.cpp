#include "mainwindow.h"
#include "login.h"
#include "rank.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();
    //return a.exec();
    Rank r;
    r.show();
    return r.exec();

}
