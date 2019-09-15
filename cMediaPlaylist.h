#ifndef CMEDIAPLAYLIST_H
#define CMEDIAPLAYLIST_H
#include "cMediaPlaylist.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "cCategory.h"
#include "BasicDatatype.h"


class tclMediaPlaylist
{

public:

    tclMediaPlaylist();
    QStringList sgetfavourites();
    tVoid vremovefavouriteitem(QString sname);
    tVoid vsetfavouriteitem(QString sname);
    tBool bcheckiffavorite(QString sname);

private :
    tVoid vfetchfavourites();
    QStringList sFavSongs;

};

#endif // CMEDIAPLAYLIST_H
