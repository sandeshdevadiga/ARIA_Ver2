/* Class : Category
  Task : This Class handles all the songs,Albums and Artists
*/

#include "cCategory.h"
#include <QDebug>

tclCategory::tclCategory()

{
    sPATH = QDir::homePath()+QDir::separator()+"Music/";
    oallsongs_playlist = new QMediaPlaylist;
    tclCategory::vRUNFORFIRSTTIME();
}
/* FUNCTION : RUNFORFIRSTTIME
  DESCRIPTION :
      * Loads all songs in allsongs_list from the directory "/home/emertxe/Music/"
      * Creates Hash Tables for Albums and Artists
      * Removes any duplicate Albums and Artists
  PARAMETERS :
      * i : Index for going through the list
      * it : Object for Directory access
      * song_tag : Object for QFile to read Favourite list
      * Artists : Has Artist Names
      * Albums : Has Album Names
      * oArtistHash : Hash Table for Artists
      * oAlbumHash : hash Table for Albums
      * allsonglist : Contains List of All Songs in media library
  RETURNVALUE : void
*/

tVoid tclCategory::vRUNFORFIRSTTIME(){

    tInt i=0;
    QDirIterator it(sPATH, QStringList() << "*.mp3", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){

        QFile song_tag(it.filePath());
        if(song_tag.open(QIODevice::ReadOnly)){
            song_tag.seek(song_tag.size()-125);
            song_tag.readLine(31);
            sArtists << song_tag.readLine(31);
            oArtistHash.insert(sArtists.value(i), i);
            sAlbums << song_tag.readLine(31);
            oAlbumHash.insert(sAlbums.value(i), i);
            i++;
        }


        oallsongs_playlist->addMedia(QUrl::fromLocalFile(it.next()));
        sallsongs_list.append(it.fileName());

    }

    sArtists.removeDuplicates();
    sAlbums.removeDuplicates();
}

/* FUNCTION : get_allsongs
  DESCRIPTION : This function returns all songs present in media player
  RETURNVALUE : allsongs_list : Contains All Songs present in media player
*/

QStringList  tclCategory::sget_allsongs(){

    return sallsongs_list;

}

/* FUNCTION : get_allAlbums
  DESCRIPTION : This function returns Albums names
  RETURNVALUE : Albums : Contains all the Album names
*/
QStringList  tclCategory::sget_allAlbums(){
    return sAlbums;
}
/* FUNCTION : get_allArtists
  DESCRIPTION : This function returns Artists names
  RETURNVALUE : Artists : Contains all the Artist names
*/
QStringList  tclCategory::sget_allArtists(){
    return  sArtists;
}

/* FUNCTION : get_allsongplaylist
  DESCRIPTION : This function returns the playlist that contains the playlist of all songs
  RETURNVALUE : allsongs_playlist : QMediaPlaylist that contains allsongs playlist
*/

QMediaPlaylist* tclCategory::get_allsongsplaylist(){
    return oallsongs_playlist;
}
/* FUNCTION : get_albumsongs
  DESCRIPTION : Searches for the required album and returns songs of the respective album
  PARAMETERS :
      * AlbumName : AlbumName for which songs to be listed
      * oAlbumHash : Hash Table for Albums
      * allsonglist : Contains List of All Songs in media library
      * i : for spotting the index of the song of the corresponding album
  RETURNVALUE :  AlbumSongs : Contains all songs of the respective AlbumName
*/
QStringList tclCategory::sget_albumsongs(QString sAlbumName){
    QStringList sAlbumSongs;
    QList<tInt> list(oAlbumHash.values(sAlbumName));
    for(tInt i = 0; i<oAlbumHash.count(sAlbumName); i++ )
    {
        sAlbumSongs << sallsongs_list.value(list.value(i));
    }
    return sAlbumSongs;
}

/* FUNCTION : get_artistsongs
  DESCRIPTION : Searches for the required Artist and returns songs of the respective artist
  PARAMETERS :
      * ArtistName : ArtistName for which songs to be listed
      * oArtistHash : Hash Table for Artists
      * allsonglist : Contains List of All Songs in media library
      * i : for spotting the index of the song of the corresponding artist
  RETURNVALUE :  ArtistSongs : Contains all songs of the respective ArtistName
*/

QStringList tclCategory::sget_artistsongs(QString sArtistName){
    QStringList sArtistSongs;
    QList<tInt> list(oArtistHash.values(sArtistName));
    for(tInt i = 0; i<oArtistHash.count(sArtistName); i++ )
    {
        sArtistSongs << sallsongs_list.value(list.value(i));
    }
    return sArtistSongs;
}
