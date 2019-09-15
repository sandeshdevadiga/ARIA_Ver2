#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cCategory.h"
#include "cMediaPlayer.h"
#include <QString>
#include <QDebug>
#include "BasicDatatype.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    otemp= new QMediaPlaylist;
    nrepeat_status=0;
    ui->setupUi(this);

    sIMAGEDIR = QDir::homePath()+QDir::separator()+"Images/";

    ui->Play_toggle->setCheckable(true);
    ui->Switch_View->setCheckable(true);
    ui->Favourite->setCheckable(true);
    ui->Shuffle->setCheckable(true);
    ui->HomeView_Frame->setGeometry(50,20,710,310);
    ui->Detailed_Viewframe->setGeometry(50,20,710,310);
    ui->Detailed_Viewframe->setShown(false);
    ui->HomeView_Frame->setShown(true);
    ui->verticalScrollBar->setValue(50);
    ui->Songs_Widget->addItems(oMediaPlayer.sgetallsonglist());
    ui->Volume_label->setNum(50);
    ui->verticalScrollBar->setStyleSheet("background: black;color : orange");
    otemp=oMediaPlayer.oCategory.get_allsongsplaylist();
    clearallTabs();
    seticonsforfirsttime();
    ui->AllSongs->setStyleSheet("background :black;color : orange");
    sRepeatText = "Repeat Once";
    sShuffleText = "Shuffle On";

    QObject::connect(oMediaPlayer.oPlayer,SIGNAL(positionChanged(qint64)),this,SLOT(on_positionChanged(qint64)));
    QObject::connect(oMediaPlayer.oPlayer,SIGNAL(durationChanged(qint64)),this,SLOT(on_duration_changed(qint64)));
    QObject::connect(oMediaPlayer.oPlayer,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stateChangedetect(QMediaPlayer::State)));
}

MainWindow::~MainWindow(){
    QString sfilename,sfavfile="Favourites.txt";
    sfilename = oMediaPlayer.oCategory.sPATH + sfavfile;
    QFile file(sfilename);
    if(file.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);   // we will serialize the data into the file
        for(int i=0;i<oMediaPlayer.oMediaPlaylist.sgetfavourites().count();i++){
            out << oMediaPlayer.oMediaPlaylist.sgetfavourites().value(i) + "\n";
        }
        file.close();

    }
    delete ui;
}

/* FUNCTION :on_Play_toggle_toggled 
  DESCRIPTION : This function is called everytime play button is clicked, it play and pauses  the current track in playlist depending on its state( checked/uncheaked);
PARAMETERs : bcheaked : State of button(from the framework).

  RETURNVALUE : void

*/

void MainWindow::on_Play_toggle_toggled(bool bchecked){

    if(bchecked){
        //        ui->Play_toggle->setText("Pause");
        oMediaPlayer.vplay_track();
    }
    else{
        //        ui->Play_toggle->setText("Play");
        oMediaPlayer.vpause_track();
    }
}

/* FUNCTION :on_Next_clicked 
  DESCRIPTION : This function is called everytime next button is clicked, it plays the next track in playlist.
  RETURNVALUE : void

*/






void MainWindow::on_Next_clicked()
{
    oMediaPlayer.vnext_track();
}


/* FUNCTION :on_Previous_clicked 
  DESCRIPTION : This function is called everytime next button is clicked, it plays the previous track in playlist.
  RETURNVALUE : void

*/


void MainWindow::on_Previous_clicked()
{
    oMediaPlayer.vprevious_track();
}


/* FUNCTION :on_Switched_View_toggled 
  DESCRIPTION : This function is called everytime Switch  button is clicked, the screen will be switched between Home view and detailed view depending on its state of button( checked/unchecked).
PARAMETERs : bcheaked :State of button(from the framework).
 RETURNVALUE : void

*/
void MainWindow::on_Switch_View_toggled(bool bchecked){

    if(bchecked){
        ui->Detailed_Viewframe->setShown(true);
        ui->HomeView_Frame->setShown(false);
    }
    else{
        ui->Detailed_Viewframe->setShown(false);
        ui->HomeView_Frame->setShown(true);
    }
    if(sTab=="Favorites"){

        ui->Songs_Widget->clear();
        ui->Songs_Widget->addItems(oMediaPlayer.oMediaPlaylist.sgetfavourites());
    }

}

/* FUNCTION :on_duration_changed
  DESCRIPTION : This function is called everytime we get a signal    positionChanged from QmediaPlayer object. Track meta data is fetched and  updated , end rack time is updated, the track is checked if its in favourite list or not.
PARAMETERs : duration : Duration of track(from the framework).
  RETURNVALUE : void

*/

void MainWindow::on_duration_changed(qint64 duration){

    sSongname ="Playing: " + oMediaPlayer.oPlayer->metaData(QtMultimediaKit::Title).toString();
    QFontMetrics metrics(ui->Playing_label->font());

    sSongname = metrics.elidedText(sSongname,Qt::ElideRight,ui->Playing_label->width());

    ui->Playing_label->setText(sSongname);
    QString sMetaData = sSongname + "\n";
    sMetaData=oMediaPlayer.sgetmetadata(sMetaData);
    ui->Meta_Data->setText(sMetaData);
    ui->Seek_bar->setRange(0,duration);//convert milli seconds to seconds
    duration=duration*0.001;
    tInt nt=duration;
    ui->End_Time->setText(QString::number(nt/60) + ":" +QString::number(nt%60));

    sCurrent_Track = oMediaPlayer.oPlaylist->currentMedia().canonicalUrl().toString();
    sCurrent_Track.remove("file://"+oMediaPlayer.oCategory.sPATH);

    for_SettingFocus();
    isfavourite();
    fornumberofsongs();
}

/* FUNCTION :on_Repeat_clicked.
  DESCRIPTION : This function is called everytime we click on Repeat button. And Playlist is set to Random/Loop/Sequential depeding on status of button.
RETURNVALUE : void

*/

void MainWindow::on_Repeat_clicked(){

    nrepeat_status++;
    nrepeat_status=nrepeat_status%3;
    if(nrepeat_status==0){
        // ui->Repeat->setText("Repeat Once");
        sRepeatText = "Repeat Once";
        seticonimage("repeat once.png",ui->Repeat);
        oMediaPlayer.vsequentialloop();
    }
    else if(nrepeat_status==1){
        //ui->Repeat->setText("Repeat All");
        sRepeatText = "Repeat All";
        seticonimage("repeatall.png",ui->Repeat);
        oMediaPlayer.viteminloop();
    }
    else if(nrepeat_status==2){
        //ui->Repeat->setText("Repeat None");
        seticonimage("repeatnone.png",ui->Repeat);
        sRepeatText = "Repeat None";
        if(ui->Shuffle->text()=="Shuffle Off"){
            oMediaPlayer.vrandomloop();
        }
        else
            oMediaPlayer.vplaylist_loop();
    }
}


/*
 FUNCTION :on_Shuffle_toggled
  DESCRIPTION : This function is called everytime we click on  Repeat button. And Playlist is set to Random/Loop/Sequential depeding on status of button.
PARAMETERs : bcheaked : State of button(from the framework).
RETURNVALUE : void.

*/



void MainWindow::on_Shuffle_toggled(bool bchecked){
    if(bchecked){
        //        ui->Shuffle->setText("Shuffle Off");
        sShuffleText="Shuffle Off";
        seticonimage("shuffleon11.png",ui->Shuffle);
        if(ui->Repeat->text()=="Repeat All"){
            oMediaPlayer.viteminloop();
        }
        else{
            oMediaPlayer.vrandomloop();
        }
    }
    else{
        sShuffleText="Shuffle On";
        //        ui->Shuffle->setText("Shuffle On");
        seticonimage("shuffleoff11.png",ui->Shuffle);
        if(ui->Repeat->text()=="Repeat All"){
            oMediaPlayer.viteminloop();
        }
        else{
            oMediaPlayer.vsequentialloop();
        }
    }

}



/*
 FUNCTION :on_verticalScrollBar_valueChanged
  DESCRIPTION : This function is called everytime the user click on scroll.  The Scrollbar value is got and the corresponding value is set as volume.
PARAMETERs : nvalue: Value of scrollbar position (from the framework).
RETURNVALUE : void.

*/


void MainWindow::on_verticalScrollBar_valueChanged(int nvalue){
    oMediaPlayer.vvolumechanged(100-nvalue);
    ui->Volume_label->setNum(100-nvalue);
}


/*
 FUNCTION :on_positionChanged
  DESCRIPTION : This function is called whenever there is positionChanged signal from media player. Seekbar position is updated. 
PARAMETERs : position:  position of the the track at this instant (from the framework).
RETURNVALUE : void.

*/




void MainWindow::on_positionChanged(qint64 position){
    ui->Seek_bar->setValue(position);
    position = position*0.001;
    tInt nmin=position/60,nsec=position%60;
    QString stime=QString::number(nmin) + ":" +QString::number(nsec);
    ui->Start_Time->setText(stime);
}

/*
 FUNCTION :on_Seek_bar_sliderMoved
  DESCRIPTION : This function is called whenever the seek bar position is Changed. Track is updated to the seek position. 
PARAMETERs : nposition:  position of the seek  (from the framework).
RETURNVALUE : void.

*/


void MainWindow::on_Seek_bar_sliderMoved(int nposition){
    oMediaPlayer.vseekbar(nposition);
}



/*
 FUNCTION :on_AllSongs_clicked
  DESCRIPTION : This function is called whenever the Allsongs button is clicked. And respective action is carried out. 
RETURNVALUE : void

*/


void MainWindow::on_AllSongs_clicked(){

    sTab="AllSongs";

    clearallTabs();
    ui->AllSongs->setStyleSheet("background :black;color : orange");

    otemp = new QMediaPlaylist;
    ui->Songs_Widget->show();
    ui->Album_Artist_Widget->hide();

    ui->Songs_Widget->clear();
    ui->Songs_Widget->addItems(oMediaPlayer.sgetallsonglist());

    QStringList sAll_Songs;
    sAll_Songs = oMediaPlayer.oCategory.sget_allsongs();

    nCurrent_Idx=sAll_Songs.indexOf(sCurrent_Track,0);

    for_SettingFocus(nCurrent_Idx);

    for(tInt i=0; i<(sAll_Songs.count());i++){

        otemp->addMedia(QUrl::fromLocalFile(oMediaPlayer.oCategory.sPATH+sAll_Songs.value(i)));
    }

}

/*
 FUNCTION :on_Songs_Widget_itemClicked
  DESCRIPTION : This function is called whenever an item in list widget is clicked. And respective action is carried out. 
PARAMETERs : item:  the pointer to item clicked  (from the framework).
RETURNVALUE : void.

*/


void MainWindow::on_Songs_Widget_itemClicked(QListWidgetItem *item){

    if(sTab=="Favorites"){

        QStringList CategorySongs=oMediaPlayer.oMediaPlaylist.sgetfavourites();

        otemp= new QMediaPlaylist;

        for(tInt i=0; i<(CategorySongs.count());i++)
        {
            otemp->addMedia(QUrl::fromLocalFile(oMediaPlayer.oCategory.sPATH+CategorySongs.value(i)));
        }

    }

    oMediaPlayer.vsetcurrentplaylist(otemp);

    oMediaPlayer.vreassignrandomandshuffle(sRepeatText,sShuffleText);

    nIndexoflist=item->listWidget()->currentRow();
    oMediaPlayer.vgetIndexoflist(nIndexoflist);

    MainWindow::on_Play_toggle_toggled(true);
    ui->Play_toggle->setChecked(true);

}

/*
 FUNCTION :on_Albums_clicked(){
  DESCRIPTION : This function is called whenever the Albums button is clicked. And respective action is carried out. 
RETURNVALUE : void

*/

void MainWindow::on_Albums_clicked(){

    sTab="Albums";
    clearallTabs();
    ui->Albums->setText("Albums");
    ui->Albums->setStyleSheet("background : black;color : orange");

    ui->Album_Artist_Widget->clear();
    ui->Songs_Widget->hide();
    ui->Album_Artist_Widget->show();
    ui->Album_Artist_Widget->addItems(oMediaPlayer.oCategory.sget_allAlbums());

    nArtistStatus=0;
    nAlbumStatus=1;
}


/*
 FUNCTION :on_Artists_clicked
  DESCRIPTION : This function is called whenever the Artists button is clicked. And respective action is carried out. 
RETURNVALUE : void

*/

void MainWindow::on_Artists_clicked(){

    sTab="Artists";
    clearallTabs();
    ui->Artists->setText("Artists");
    ui->Artists->setStyleSheet("background : black;color : orange");

    ui->Album_Artist_Widget->clear();
    ui->Songs_Widget->hide();
    ui->Album_Artist_Widget->show();
    ui->Album_Artist_Widget->addItems(oMediaPlayer.oCategory.sget_allArtists());
    nArtistStatus=1;
    nAlbumStatus=0;
}
/*
 FUNCTION :on_Album_Artist_Widget_itemClicked
  DESCRIPTION : This function is called whenever an item in list widget is clicked. And respective action is carried out. 
PARAMETERs : item:  the pointer to item clicked  (from the framework).
RETURNVALUE : void.

*/






void MainWindow::on_Album_Artist_Widget_itemClicked(QListWidgetItem *item){
    QString sname=item->text();

    if(sTab=="Albums"){
        ui->Albums->setStyleSheet("background : black;color : orange");
        ui->Albums->setText("Back");
    }
    else if(sTab=="Artists"){
        ui->Artists->setStyleSheet("background : black;color : orange");
        ui->Artists->setText("Back");
    }

    while(ui->Songs_Widget->count()>0)
    {
        ui->Songs_Widget->takeItem(0);
    }

    QStringList sCategorySongs;
    if(nArtistStatus==1 && nAlbumStatus==0){
        sCategorySongs=oMediaPlayer.oCategory.sget_artistsongs(sname);
        ui->Songs_Widget->addItems(sCategorySongs);
        ui->Songs_Widget->show();
        ui->Album_Artist_Widget->hide();
    }
    else if(nArtistStatus==0 && nAlbumStatus==1){
        sCategorySongs=oMediaPlayer.oCategory.sget_albumsongs(sname);
        ui->Songs_Widget->addItems(sCategorySongs);
        ui->Songs_Widget->show();
        ui->Album_Artist_Widget->hide();
    }

    nCurrent_Idx=sCategorySongs.indexOf(sCurrent_Track,0);

    for_SettingFocus(nCurrent_Idx);

    otemp= new QMediaPlaylist;


    for(tInt i=0; i<(sCategorySongs.count());i++)
    {
        otemp->addMedia(QUrl::fromLocalFile(oMediaPlayer.oCategory.sPATH+sCategorySongs.value(i)));
    }

}


/*
 FUNCTION :on_Favourites_clicked
  DESCRIPTION : This function is called whenever the Favourites button is clicked. And respective action is carried out. 
RETURNVALUE : void

*/




void MainWindow::on_Favourites_clicked(){
    sTab="Favorites";
    clearallTabs();
    ui->Favourites->setStyleSheet("background : black;color : orange");

    ui->Songs_Widget->clear();

    QStringList CategorySongs=oMediaPlayer.oMediaPlaylist.sgetfavourites();

    nCurrent_Idx=CategorySongs.indexOf(sCurrent_Track,0);

    ui->Songs_Widget->addItems(oMediaPlayer.oMediaPlaylist.sgetfavourites());
    ui->Songs_Widget->show();
    ui->Album_Artist_Widget->hide();

    for_SettingFocus(nCurrent_Idx);


    otemp= new QMediaPlaylist;

    for(tInt i=0; i<(CategorySongs.count());i++)
    {
        otemp->addMedia(QUrl::fromLocalFile(oMediaPlayer.oCategory.sPATH+CategorySongs.value(i)));
    }

}

/*
 FUNCTION :isfavourite
  DESCRIPTION : This function is called when there is a new track in playtlist ( called inside function onDurationchanged). The function checks if the songs is in favourite list on not. 
RETURNVALUE : void

*/



void MainWindow::isfavourite(){

    nFavStatus=oMediaPlayer.oMediaPlaylist.bcheckiffavorite(sCurrent_Track);

    if(nFavStatus){

        seticonimage("favon11.png",ui->Favourite);
    }
    else{

        seticonimage("favoff11.png",ui->Favourite);

    }

}
/*
 FUNCTION :for_SettingFocus
  DESCRIPTION : This function is called when there is a new track in playtlist ( called inside function onDurationchanged).The function sets focus on the song playing in list widget. 
RETURNVALUE : void

*/



void MainWindow::for_SettingFocus(){
    QStringList Songstemp;
    for(int ii=0;ii<ui->Songs_Widget->count();ii++){
        Songstemp.append(ui->Songs_Widget->item(ii)->text());
    }

    nCurrent_Idx=Songstemp.indexOf(sCurrent_Track,0);

    if(nCurrent_Idx!=-1){
        ui->Songs_Widget->item(nCurrent_Idx)->setSelected(true);
        ui->Songs_Widget->setFocus();
    }
}


/*
 FUNCTION :for_SettingFocus
  DESCRIPTION : This function is called to set focus on the track 
PARAMETERs : nCurrent_Idx : Index of the trackPlaying in listWidget.
RETURNVALUE : void

*/


void MainWindow::for_SettingFocus(int nCurrent_Idx ){
    if(nCurrent_Idx!=-1){
        ui->Songs_Widget->item(nCurrent_Idx)->setSelected(true);
        ui->Songs_Widget->setFocus();
    }
}

/*
 FUNCTION :clearallTabs
  DESCRIPTION : This function is called to unhighlight tabs. 
  RETURNVALUE : void.

*/


void MainWindow::clearallTabs(){

    ui->Albums->setText("Albums");
    ui->Artists->setText("Artists");
    ui->AllSongs->setStyleSheet("background : black ; color:white ");
    ui->Albums->setStyleSheet("background : black ; color:white ");
    ui->Artists->setStyleSheet("background : black ; color:white ");
    ui->Favourites->setStyleSheet("background :black ; color:white ");
}




/*
 FUNCTION :fornumberofsongs
  DESCRIPTION : This function is called to update the current song number and total number of song in playlist. 
  RETURNVALUE : void.

*/


void MainWindow::fornumberofsongs(){

    tInt ncurrentnum=oMediaPlayer.oPlaylist->currentIndex()+1;
    int totalnum=oMediaPlayer.oPlaylist->mediaCount();
    QString numsongsdisplay=QString::number(ncurrentnum) + "/" +QString::number(totalnum);
    ui->numofsongs->setText(numsongsdisplay);

}

/*
 FUNCTION : stateChangedetect
  DESCRIPTION : This function is called to detect end of playlist and stops the player if repeat is OFF.
PARAMETERs : state: Player state.
RETURNVALUE : void

*/
void MainWindow:: stateChangedetect(QMediaPlayer::State ){

    if(sRepeatText == "Repeat Once" && oMediaPlayer.oPlayer->state()==0){
        MainWindow::on_Play_toggle_toggled(false);
        ui->Play_toggle->setChecked(false);
    }
}

/*
 FUNCTION :seticonimage
  DESCRIPTION : This function is called to set icon on push button.
PARAMETERs : imgname: Name of the icon.
    button: Pointer to QPushButton.
RETURNVALUE : void

*/

void  MainWindow:: seticonimage( QString imgname,QPushButton *button)
{

    QString filename =QString(sIMAGEDIR) + imgname;
    QPixmap *pic=new QPixmap(filename);
    QIcon *icon=new QIcon(*pic);
    button->setIcon(*icon);
    button->setIconSize(QSize(55,55));
    button->setFlat(true);
}

/*
 FUNCTION :seticonsforfirsttime
  DESCRIPTION : This function is called to set icon on push button for first time. 
  RETURNVALUE : void.

*/
//
void  MainWindow:: seticonsforfirsttime(){
    seticonimage("repeat once.png",ui->Repeat);
    seticonimage("shuffleoff11.png",ui->Shuffle);
    seticonimage("favoff11.png",ui->Favourite);
}

/*
 FUNCTION :on_Favourite_clicked
  DESCRIPTION : This function is called when favourite button in detailed view is clicked. 
  RETURNVALUE : void.

*/

void MainWindow::on_Favourite_clicked()
{
    if(!oMediaPlayer.oMediaPlaylist.bcheckiffavorite(sCurrent_Track))
    {

        seticonimage("favon11.png",ui->Favourite);

        oMediaPlayer.oMediaPlaylist.vsetfavouriteitem(sCurrent_Track);
    }

    else
    {
        oMediaPlayer.oMediaPlaylist.vremovefavouriteitem(sCurrent_Track);
        seticonimage("favoff11.png",ui->Favourite);

    }
}
