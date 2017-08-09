#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <QDebug>
using namespace std ;

int main(int argc, char *argv[])
{
    char outfile [240] ;
    int nsecs ;
    QApplication a(argc, argv);
    if (argc > 2) {
        strcpy (outfile, *++argv) ;
        nsecs = atoi (*++argv)  ;

    }
    MainWindow w;
    w.setScanParams (outfile, nsecs ) ;
    w.show();
    Sleep (5000);
    w.startAcquire();
    
    return a.exec();
}
