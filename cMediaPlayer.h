#ifndef CMEDIAPLAYER_H
#define CMEDIAPLAYER_H
#include "cCategory.h"
#include <QString>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <cMediaPlaylist.h>
#include "BasicDatatype.h"


class tclMediaPlayer
{

public:
    tclMediaPlaylist oMediaPlaylist;
    tclCategory oCategory;
    tclMediaPlayer();
    QMediaPlayer *oPlayer ;
    QMediaPlaylist *oPlaylist;
    QStringList sgetallsonglist();
    tVoid vplay_track();
    tVoid vpause_track();
    tVoid vnext_track();
    tVoid vprevious_track();
    tVoid vgetIndexoflist(tInt nindex);
    tVoid von_duration_changedcmedia(qint64 duration);
    tVoid viteminloop();
    tVoid vrandomloop();
    tVoid vsequentialloop();
    tVoid vplaylist_loop();
    tVoid vvolumechanged(tInt nvolume);
    tVoid vseekbar(tInt nposition);
    QStringList  sget_allArtists();
    QStringList  sget_allAlbums();
    QStringList sget_albumsongs(QString sAlbumName);
    tVoid vsetcurrentplaylist(QMediaPlaylist *oplaylist);
    QString sgetmetadata(QString sSongname);
    tVoid vreassignrandomandshuffle(QString,QString);


private:
    QStringList  sallsongslist;

};

#endif // CMEDIAPLAYER_H
