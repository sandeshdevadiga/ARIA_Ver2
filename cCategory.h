#ifndef CCATEGORY_H
#define CCATEGORY_H
#include <QListWidgetItem>
#include <QDirIterator>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QString>
#include "BasicDatatype.h"

class tclCategory
{


public:
    tclCategory();
    QString sPATH;
    QStringList sget_allsongs();

    QMediaPlaylist* get_allsongsplaylist();
    QStringList  sget_allAlbums();
    QStringList  sget_allArtists();
    QStringList  sget_artistsongs(QString sArtistName);
    QStringList sget_albumsongs(QString sAlbumName);
    tVoid vRUNFORFIRSTTIME();

private:
    QMediaPlaylist *oallsongs_playlist;
    QStringList sallsongs_list;
    QMultiHash<QString, tInt> oArtistHash;
    QMultiHash<QString, tInt> oAlbumHash;
    QStringList sArtists;
    QStringList sAlbums;
};
#endif // CCATEGORY_H
