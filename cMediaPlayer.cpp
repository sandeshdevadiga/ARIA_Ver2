/* Class : MediaPlayer
  Task : This Class handles all the QMediaPlayer and QMediaPlaylist functions like play,pause,next,shuffle,repeat
          change volume,change seekbar position,set playlist etc
*/

#include "cMediaPlayer.h"
#include <QMediaPlaylist>
#include <QDebug>


tclMediaPlayer::tclMediaPlayer()
{

    oPlayer =new QMediaPlayer;
    oPlaylist= oCategory.get_allsongsplaylist();
    oPlayer->setPlaylist(oPlaylist);
}

/* FUNCTION : getallsongslist
  DESCRIPTION : This function returns all songs list from Category class
  RETURNVALUE : allsongslist : Contains all songs present in media directory
*/

QStringList  tclMediaPlayer:: sgetallsonglist(){
    sallsongslist=  oCategory.sget_allsongs();
    return sallsongslist;
}

/* FUNCTION : vplay_track
  DESCRIPTION : Play the song from the playlist
  RETURNVALUE : tVoid
*/

tVoid tclMediaPlayer::vplay_track(){
    oPlayer->play();
}

/* FUNCTION : vpause_track
  DESCRIPTION : pause the Playing song
  RETURNVALUE : tVoid
*/

tVoid tclMediaPlayer::vpause_track(){
    oPlayer->pause();
}
/* FUNCTION : vnext_track
  DESCRIPTION : plays the next song
  RETURNVALUE : void
*/
tVoid tclMediaPlayer::vnext_track(){
    oPlaylist->next();
}

/* FUNCTION : vprevious_track
  DESCRIPTION : Plays the previous song
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::vprevious_track(){
    oPlaylist->previous();
}

/* FUNCTION : getIndexoflist
  DESCRIPTION : Sets the choosen item to play
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::vgetIndexoflist(tInt nindex){
    oPlaylist->setCurrentIndex(nindex);
}

/* FUNCTION : iteminloop
  DESCRIPTION : Sets the current item in loop (Repeat Once)
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::viteminloop(){
    oPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

/* FUNCTION : randomloop
  DESCRIPTION : Sets the playlist to go to random indexes (Shuffle on)
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::vrandomloop(){
    oPlaylist->setPlaybackMode(QMediaPlaylist::Random);
}

/* FUNCTION : sequentialloop
  DESCRIPTION : Sets the playlist go to sequential indexes (Shuffle off)
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::vsequentialloop(){
    oPlaylist->setPlaybackMode(QMediaPlaylist::Sequential);
}

/* FUNCTION : playlist_loop
  DESCRIPTION : Sets the playlist to repeat playing all songs of current playlist( Repeat all )
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::vplaylist_loop()
{
    oPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
}

/* FUNCTION : volumechanged
  DESCRIPTION : To increase or decrease volume
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::vvolumechanged(tInt nvolume)
{
    oPlayer->setVolume(nvolume);
}

/* FUNCTION : seekbar
  DESCRIPTION : to change(seek) the position of current playing song
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::vseekbar(tInt nposition){
    oPlayer->setPosition(nposition);
}

/* FUNCTION : get_allAlbums
  DESCRIPTION : returns all Albums from category class
  RETURNVALUE : All Albums list
*/

QStringList tclMediaPlayer ::sget_allAlbums(){
    return oCategory.sget_allAlbums();
}

/* FUNCTION : get_allArtists
  DESCRIPTION : returns all artists from category class
  RETURNVALUE : All Artists list
*/

QStringList  tclMediaPlayer::sget_allArtists(){
    return  oCategory.sget_allArtists();
}

/* FUNCTION : get_albumsongs
  DESCRIPTION : returns songs of a particular album from category class
  PARAMETERS : AlbumName : Name of Album for which songs to be extracted
  RETURNVALUE : QStringlist of Song names in Album
*/

QStringList tclMediaPlayer::sget_albumsongs(QString sAlbumName){
    return oCategory.sget_albumsongs(sAlbumName);
}

/* FUNCTION : setcurrentplaylist
  DESCRIPTION : To set a playlist as current(Playing) playlist
  PARAMETERS : playlist : Playlist to set as current playlist
  RETURNVALUE : void
*/

tVoid tclMediaPlayer::vsetcurrentplaylist(QMediaPlaylist * oplaylist){
    oPlaylist=oplaylist;
    oPlayer->setPlaylist(oPlaylist);
}

/*FUNCTION : getmetadata
  DESCRIPTION : returns the MetaData, That consists of Title,AlbumName,ArtistName
  PARAMETERS : MetaData : tclMediaPlayerially it contains the title of playing song
  RETURNVALUE : MetaData : AlbumTitle and ArtistTitle are appended to title.
  */

QString tclMediaPlayer::sgetmetadata(QString sMetaData){

    sMetaData = sMetaData + "Album : " + oPlayer->metaData(QtMultimediaKit::AlbumTitle).toString() + "\n";
    sMetaData = sMetaData + "Artist : " + oPlayer->metaData(QtMultimediaKit::AlbumArtist).toString() +"\n";
    return sMetaData;
}

/*FUNCTION : reassignrandomandshuffle
  DESCRIPTION : When ever a new playlist is assigned to current playlist this function is called to
                reassign the previously selected random and shuffle conditions
  PARAMETERS :
        * RepeatCheck : Repeat Status will be stored in this
        * ShuffleCheck : Shuffle Status will be stored in this

  RETURNVALUE : void
  */

tVoid tclMediaPlayer::vreassignrandomandshuffle(QString sRepeatCheck, QString sShuffleCheck ){

    if(sRepeatCheck=="Repeat Once")
    {
        if(sShuffleCheck=="Shuffle Off"){
            oPlaylist->setPlaybackMode(QMediaPlaylist::Random);
        }
        else{
            oPlaylist->setPlaybackMode(QMediaPlaylist::Sequential);
        }

    }
    else if(sRepeatCheck=="Repeat None"){

        if(sShuffleCheck=="Shuffle Off"){
            oPlaylist->setPlaybackMode(QMediaPlaylist::Random);
        }
        else{
            oPlaylist->setPlaybackMode(QMediaPlaylist::Loop);
        }
    }
    else{

        oPlaylist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    }
}
