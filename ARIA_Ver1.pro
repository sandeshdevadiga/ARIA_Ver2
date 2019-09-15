#-------------------------------------------------
#
# Project created by QtCreator 2016-08-08T16:46:25
#
#-------------------------------------------------

QT       += core gui

TARGET = ARIA_Ver1
TEMPLATE = app

CONFIG += mobility
MOBILITY = multimedia

INCLUDEPATH += /usr/include/QtMultimediaKit/ \
                /usr/include/QtMobility/

LIBS += -lQtMultimediaKit -L/usr/libksrtct

SOURCES += main.cpp\
        mainwindow.cpp \
    cCategory.cpp \
    cMediaPlayer.cpp \
    cMediaPlaylist.cpp

HEADERS  += mainwindow.h \
    cMediaPlayer.h \
    cMediaPlaylist.h \
    cCategory.h \
    BasicDatatype.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
