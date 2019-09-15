#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cMediaPlayer.h>
#include <QString>
#include <cCategory.h>
#include <QPushButton>
#include <BasicDatatype.h>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Q_OBJECT
    tclMediaPlayer oMediaPlayer;
    tInt nIndexoflist,nCurrent_Idx;
    QString sSongname;
    tInt nrepeat_status;
    QString sShuffleText,sRepeatText;
    QStringList sArtists;
    QStringList sAlbums;
    tInt nAlbumStatus;
    tInt nArtistStatus;
    QMediaPlaylist *otemp;
    tInt nFavStatus;
    QString sTab;
    QString sCurrent_Track;
    QString sIMAGEDIR;




private slots:


    void on_Play_toggle_toggled(bool bchecked);

    void on_Next_clicked();

    void on_Previous_clicked();

    void on_Switch_View_toggled(bool bchecked);

    void on_duration_changed(qint64 duration);

    void on_Repeat_clicked();

    void on_Shuffle_toggled(bool bchecked);

    void on_verticalScrollBar_valueChanged(int nvalue);

    void on_positionChanged(qint64 position);

    void on_Seek_bar_sliderMoved(int nposition);

    void on_AllSongs_clicked();

    void on_Songs_Widget_itemClicked(QListWidgetItem *item);

    void on_Albums_clicked();

    void on_Artists_clicked();

    void on_Album_Artist_Widget_itemClicked(QListWidgetItem *item);

    void isfavourite();

    void on_Favourites_clicked();


    void for_SettingFocus();

    void for_SettingFocus(int nindex2);

    void clearallTabs();

    void fornumberofsongs();

    void stateChangedetect(QMediaPlayer::State);

    void seticonimage(QString sname,QPushButton *pbutton);

    void seticonsforfirsttime();

    void on_Favourite_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
