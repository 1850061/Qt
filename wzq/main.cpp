#include "mainwindow.h"
#include "login.h"
#include "rank.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int flag=1;
    if(flag){
        MainWindow w;
        w.show();
        return a.exec();
    }
    else{
        Rank r;
        r.show();
        return r.exec();
    }
}
