/* Class : MediaPlaylist
  Task : This Class handles Favourite Playlist
*/

#include "cMediaPlaylist.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "cCategory.h"

tclMediaPlaylist::tclMediaPlaylist()
{
    vfetchfavourites();
}
/* FUNCTION : fetchfavourites
  DESCRIPTION : Reads previously stored favouite songs from favourites text file and stores in FavSongs variable
  RETURNVALUE : void

*/

tVoid tclMediaPlaylist::vfetchfavourites(){

    QString sfilename,favfile="Favourites.txt";
    sfilename = QDir::homePath()+QDir::separator()+"Music/" + favfile;


    QFile file( sfilename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            sFavSongs.append(in.readLine());
        }
        file.close();
    }
}

/* FUNCTION : getfavourites
   DESCRIPTION : returns the FavSongs List
   RETURNVALUE : FavSongs  : contains Favourite Songs
*/

QStringList tclMediaPlaylist::sgetfavourites(){
    return sFavSongs;
}

/* FUNCTION : removefavouriteitem
   DESCRIPTION : removes a song from FavSongs List permanently
   PARAMETERs : name : Name of the song that to be removed from Favorite Songs List
   RETURNVALUE : void
*/

tVoid tclMediaPlaylist::vremovefavouriteitem(QString sname){
    if(sFavSongs.contains(sname)){
    sFavSongs.removeOne(sname);
}
}

/* FUNCTION : setfavouriteitem
   DESCRIPTION :  Adds a song to FavSong list
   PARAMETERs : name : Name of the song that to be added to Favorite Songs List
   RETURNVALUE : void

*/

tVoid tclMediaPlaylist::vsetfavouriteitem(QString sname){
    if(!sFavSongs.contains(sname) && sname.count()){
    sFavSongs.append(sname);
    }
}

/* FUNCTION : checkiffavorite
  DESCRIPTION : Checks is a Song is favourited before or not and returns true if its present else false
   PARAMETERs : name : Name of the song that to be checked from Favorite Songs List
   RETURNVALUE : bool : true if its present else fale
*/

tBool tclMediaPlaylist::bcheckiffavorite(QString sname){

    if(sFavSongs.contains(sname))
    {
        return true;
    }
    else
    {
        return false;
    }
}
