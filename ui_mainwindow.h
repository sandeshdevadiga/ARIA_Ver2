/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Sep 1 17:42:29 2016
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *Play_fixedframe;
    QLabel *Playing_label;
    QPushButton *Switch_View;
    QPushButton *Next;
    QPushButton *Play_toggle;
    QPushButton *Previous;
    QFrame *Volume_fixedframe;
    QScrollBar *verticalScrollBar;
    QLabel *Volume_label;
    QFrame *Detailed_Viewframe;
    QSlider *Seek_bar;
    QPushButton *Favourite;
    QPushButton *Repeat;
    QPushButton *Shuffle;
    QLabel *Meta_Data;
    QLabel *Start_Time;
    QLabel *numofsongs;
    QLabel *End_Time;
    QFrame *HomeView_Frame;
    QPushButton *AllSongs;
    QPushButton *Albums;
    QPushButton *Artists;
    QPushButton *Favourites;
    QListWidget *Album_Artist_Widget;
    QListWidget *Songs_Widget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 480);
        MainWindow->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Schoolbook L\";\n"
"background-color: qlineargradient(spread:pad, x1:0.476, y1:0.704682, x2:0.481, y2:1, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Play_fixedframe = new QFrame(centralWidget);
        Play_fixedframe->setObjectName(QString::fromUtf8("Play_fixedframe"));
        Play_fixedframe->setGeometry(QRect(10, 330, 751, 80));
        Play_fixedframe->setStyleSheet(QString::fromUtf8("background : transparent;\n"
"border:none;\n"
""));
        Play_fixedframe->setFrameShape(QFrame::StyledPanel);
        Play_fixedframe->setFrameShadow(QFrame::Raised);
        Playing_label = new QLabel(Play_fixedframe);
        Playing_label->setObjectName(QString::fromUtf8("Playing_label"));
        Playing_label->setGeometry(QRect(340, 40, 301, 17));
        Playing_label->setStyleSheet(QString::fromUtf8("color : black;"));
        Switch_View = new QPushButton(Play_fixedframe);
        Switch_View->setObjectName(QString::fromUtf8("Switch_View"));
        Switch_View->setGeometry(QRect(650, 20, 42, 51));
        Switch_View->setStyleSheet(QString::fromUtf8("#Switch_View{\n"
"background-color:transparent;\n"
"background-image: url(:/img/switchview.png);\n"
"border:none;\n"
"\n"
"}\n"
"#Switch_View:checked{\n"
"\n"
"            background-image: url(:/img/switchviewoff.png);\n"
"\n"
"}\n"
"#Switch_View:focus {\n"
"            border: none;\n"
"            outline: none;\n"
"    }\n"
""));
        Next = new QPushButton(Play_fixedframe);
        Next->setObjectName(QString::fromUtf8("Next"));
        Next->setGeometry(QRect(200, 20, 42, 51));
        Next->setStyleSheet(QString::fromUtf8("border : none;\n"
"background-image: url(:/img/nextone.png);\n"
"outline : none;"));
        Play_toggle = new QPushButton(Play_fixedframe);
        Play_toggle->setObjectName(QString::fromUtf8("Play_toggle"));
        Play_toggle->setGeometry(QRect(110, 20, 42, 51));
        Play_toggle->setStyleSheet(QString::fromUtf8("#Play_toggle{\n"
"background-color:transparent;\n"
"border:none;\n"
"	background-image: url(:/img/play.png);\n"
"}\n"
"#Play_toggle:checked{\n"
"	background-image: url(:/img/pause.png);\n"
"\n"
"}\n"
"    #Play_toggle:focus {\n"
"            border: none;\n"
"            outline: none;\n"
"    }\n"
""));
        Previous = new QPushButton(Play_fixedframe);
        Previous->setObjectName(QString::fromUtf8("Previous"));
        Previous->setGeometry(QRect(20, 20, 42, 51));
        Previous->setStyleSheet(QString::fromUtf8("background-image: url(:/img/previousone.png);\n"
"border : none;\n"
"outline : none;\n"
""));
        Next->raise();
        Play_toggle->raise();
        Previous->raise();
        Switch_View->raise();
        Playing_label->raise();
        Volume_fixedframe = new QFrame(centralWidget);
        Volume_fixedframe->setObjectName(QString::fromUtf8("Volume_fixedframe"));
        Volume_fixedframe->setGeometry(QRect(10, 20, 41, 311));
        Volume_fixedframe->setStyleSheet(QString::fromUtf8("background :transparent;\n"
"border:none;\n"
""));
        Volume_fixedframe->setFrameShape(QFrame::StyledPanel);
        Volume_fixedframe->setFrameShadow(QFrame::Raised);
        verticalScrollBar = new QScrollBar(Volume_fixedframe);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(10, 60, 21, 241));
        verticalScrollBar->setOrientation(Qt::Vertical);
        Volume_label = new QLabel(Volume_fixedframe);
        Volume_label->setObjectName(QString::fromUtf8("Volume_label"));
        Volume_label->setGeometry(QRect(10, 10, 31, 17));
        Volume_label->setStyleSheet(QString::fromUtf8("color : white;\n"
"background :transparent;"));
        Detailed_Viewframe = new QFrame(centralWidget);
        Detailed_Viewframe->setObjectName(QString::fromUtf8("Detailed_Viewframe"));
        Detailed_Viewframe->setGeometry(QRect(50, 20, 711, 311));
        Detailed_Viewframe->setStyleSheet(QString::fromUtf8("background :transparent;\n"
"border:none;\n"
""));
        Detailed_Viewframe->setFrameShape(QFrame::StyledPanel);
        Detailed_Viewframe->setFrameShadow(QFrame::Raised);
        Seek_bar = new QSlider(Detailed_Viewframe);
        Seek_bar->setObjectName(QString::fromUtf8("Seek_bar"));
        Seek_bar->setGeometry(QRect(30, 230, 631, 29));
        Seek_bar->setStyleSheet(QString::fromUtf8("background:transparent;"));
        Seek_bar->setOrientation(Qt::Horizontal);
        Favourite = new QPushButton(Detailed_Viewframe);
        Favourite->setObjectName(QString::fromUtf8("Favourite"));
        Favourite->setGeometry(QRect(340, 140, 55, 55));
        Favourite->setStyleSheet(QString::fromUtf8("\n"
"    #Favourite:focus {\n"
"            border: none;\n"
"            outline: none;\n"
"    }\n"
"\n"
"\n"
"\n"
""));
        Repeat = new QPushButton(Detailed_Viewframe);
        Repeat->setObjectName(QString::fromUtf8("Repeat"));
        Repeat->setGeometry(QRect(80, 140, 55, 55));
        Repeat->setStyleSheet(QString::fromUtf8("\n"
"    #Repeat:focus {\n"
"            border: none;\n"
"            outline: none;\n"
"    }\n"
"\n"
""));
        Shuffle = new QPushButton(Detailed_Viewframe);
        Shuffle->setObjectName(QString::fromUtf8("Shuffle"));
        Shuffle->setGeometry(QRect(590, 140, 55, 55));
        Shuffle->setStyleSheet(QString::fromUtf8("\n"
"   #Shuffle:focus {\n"
"            border: none;\n"
"            outline: none;\n"
"    }\n"
""));
        Meta_Data = new QLabel(Detailed_Viewframe);
        Meta_Data->setObjectName(QString::fromUtf8("Meta_Data"));
        Meta_Data->setGeometry(QRect(70, 50, 551, 81));
        Meta_Data->setStyleSheet(QString::fromUtf8("color:white;\n"
"background : transparent;"));
        Start_Time = new QLabel(Detailed_Viewframe);
        Start_Time->setObjectName(QString::fromUtf8("Start_Time"));
        Start_Time->setGeometry(QRect(31, 271, 51, 17));
        Start_Time->setStyleSheet(QString::fromUtf8("color : white;\n"
"background : transparent;"));
        numofsongs = new QLabel(Detailed_Viewframe);
        numofsongs->setObjectName(QString::fromUtf8("numofsongs"));
        numofsongs->setGeometry(QRect(340, 270, 51, 17));
        numofsongs->setStyleSheet(QString::fromUtf8("color : white;\n"
"background : transparent;"));
        End_Time = new QLabel(Detailed_Viewframe);
        End_Time->setObjectName(QString::fromUtf8("End_Time"));
        End_Time->setGeometry(QRect(615, 270, 41, 20));
        End_Time->setStyleSheet(QString::fromUtf8("color : white;\n"
"background : transparent;"));
        Start_Time->raise();
        numofsongs->raise();
        End_Time->raise();
        Seek_bar->raise();
        Favourite->raise();
        Repeat->raise();
        Shuffle->raise();
        Meta_Data->raise();
        HomeView_Frame = new QFrame(centralWidget);
        HomeView_Frame->setObjectName(QString::fromUtf8("HomeView_Frame"));
        HomeView_Frame->setGeometry(QRect(520, 60, 711, 311));
        HomeView_Frame->setStyleSheet(QString::fromUtf8("background :transparent;\n"
"border:none;\n"
""));
        HomeView_Frame->setFrameShape(QFrame::StyledPanel);
        HomeView_Frame->setFrameShadow(QFrame::Raised);
        AllSongs = new QPushButton(HomeView_Frame);
        AllSongs->setObjectName(QString::fromUtf8("AllSongs"));
        AllSongs->setGeometry(QRect(50, 10, 97, 27));
        AllSongs->setStyleSheet(QString::fromUtf8("#AllSongs{\n"
"color:white;\n"
"}"));
        Albums = new QPushButton(HomeView_Frame);
        Albums->setObjectName(QString::fromUtf8("Albums"));
        Albums->setGeometry(QRect(190, 10, 97, 27));
        Albums->setStyleSheet(QString::fromUtf8("#Albums{\n"
"color:white;\n"
"focus {\n"
"            border: none;\n"
"            outline: none;\n"
"}\n"
"}"));
        Artists = new QPushButton(HomeView_Frame);
        Artists->setObjectName(QString::fromUtf8("Artists"));
        Artists->setGeometry(QRect(340, 10, 97, 27));
        Artists->setStyleSheet(QString::fromUtf8("#Artists{\n"
"color:white;\n"
"}"));
        Favourites = new QPushButton(HomeView_Frame);
        Favourites->setObjectName(QString::fromUtf8("Favourites"));
        Favourites->setGeometry(QRect(490, 10, 97, 27));
        Album_Artist_Widget = new QListWidget(HomeView_Frame);
        Album_Artist_Widget->setObjectName(QString::fromUtf8("Album_Artist_Widget"));
        Album_Artist_Widget->setGeometry(QRect(30, 60, 641, 231));
        Album_Artist_Widget->setStyleSheet(QString::fromUtf8("#Album_Artist_Widget::item{\n"
"\n"
"\n"
"color:white;\n"
"background :transparent;\n"
"}"));
        Songs_Widget = new QListWidget(HomeView_Frame);
        Songs_Widget->setObjectName(QString::fromUtf8("Songs_Widget"));
        Songs_Widget->setGeometry(QRect(30, 60, 641, 231));
        Songs_Widget->setStyleSheet(QString::fromUtf8("\n"
"#Songs_Widget::item{\n"
"\n"
"color:white;\n"
"background :transparent;\n"
"}\n"
"#Songs_Widget::item::selected{\n"
"\n"
"color:orange;\n"
"\n"
"}"));
        MainWindow->setCentralWidget(centralWidget);
        Play_fixedframe->raise();
        Volume_fixedframe->raise();
        HomeView_Frame->raise();
        Detailed_Viewframe->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 28));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        Playing_label->setText(QString());
        Switch_View->setText(QString());
        Next->setText(QString());
        Play_toggle->setText(QString());
        Previous->setText(QString());
        Volume_label->setText(QString());
        Favourite->setText(QString());
        Repeat->setText(QString());
        Shuffle->setText(QString());
        Meta_Data->setText(QString());
        Start_Time->setText(QString());
        numofsongs->setText(QString());
        End_Time->setText(QString());
        AllSongs->setText(QApplication::translate("MainWindow", "All Songs", 0, QApplication::UnicodeUTF8));
        Albums->setText(QApplication::translate("MainWindow", "Albums", 0, QApplication::UnicodeUTF8));
        Artists->setText(QApplication::translate("MainWindow", "Artists", 0, QApplication::UnicodeUTF8));
        Favourites->setText(QApplication::translate("MainWindow", "Favourites", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
