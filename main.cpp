#include <QtGui/QApplication>
#include "mainwindow.h"
#include "cCategory.h"
#include <QSplashScreen>
#include <QTimer>
#include <mainwindow.h>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    QSplashScreen  *splash = new QSplashScreen;

    QString sIMAGEDIR = QDir::homePath()+QDir::separator()+"Images/";

    splash->setPixmap(QPixmap(QString(sIMAGEDIR) + "splash.PNG"));
//    splash->setPixmap(QPixmap(800,480));
        splash->show();

        QTimer::singleShot(2500, splash, SLOT(close()));
       QTimer::singleShot(2500,&w, SLOT(show()));
//    w.show();


    return a.exec();
}

