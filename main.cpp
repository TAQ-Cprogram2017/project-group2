#include <QCoreApplication>
#include "mainwindow.h"
#include <QApplication>
#include <QTime>
#include <QSplashScreen>
#include <QDebug>
#include <QElapsedTimer>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPixmap pix(":/new/prefix1/huhaomingzhenshuai.png") ;
   QSplashScreen splash(pix);
    splash.resize(pix.size());
   splash.show();
    app.processEvents();

       MainWindow w;
       w.show();

       //splash.finish(&w);
       return app.exec();
}

