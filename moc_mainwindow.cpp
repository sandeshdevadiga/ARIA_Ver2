/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Sep 1 17:42:37 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   12,   11,   11, 0x08,
      50,   11,   11,   11, 0x08,
      68,   11,   11,   11, 0x08,
      90,   12,   11,   11, 0x08,
     128,  119,   11,   11, 0x08,
     156,   11,   11,   11, 0x08,
     176,   12,   11,   11, 0x08,
     208,  201,   11,   11, 0x08,
     256,  247,   11,   11, 0x08,
     293,  283,   11,   11, 0x08,
     322,   11,   11,   11, 0x08,
     349,  344,   11,   11, 0x08,
     395,   11,   11,   11, 0x08,
     415,   11,   11,   11, 0x08,
     436,  344,   11,   11, 0x08,
     489,   11,   11,   11, 0x08,
     503,   11,   11,   11, 0x08,
     527,   11,   11,   11, 0x08,
     554,  546,   11,   11, 0x08,
     576,   11,   11,   11, 0x08,
     591,   11,   11,   11, 0x08,
     610,   11,   11,   11, 0x08,
     663,  649,   11,   11, 0x08,
     698,   11,   11,   11, 0x08,
     721,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0bchecked\0on_Play_toggle_toggled(bool)\0"
    "on_Next_clicked()\0on_Previous_clicked()\0"
    "on_Switch_View_toggled(bool)\0duration\0"
    "on_duration_changed(qint64)\0"
    "on_Repeat_clicked()\0on_Shuffle_toggled(bool)\0"
    "nvalue\0on_verticalScrollBar_valueChanged(int)\0"
    "position\0on_positionChanged(qint64)\0"
    "nposition\0on_Seek_bar_sliderMoved(int)\0"
    "on_AllSongs_clicked()\0item\0"
    "on_Songs_Widget_itemClicked(QListWidgetItem*)\0"
    "on_Albums_clicked()\0on_Artists_clicked()\0"
    "on_Album_Artist_Widget_itemClicked(QListWidgetItem*)\0"
    "isfavourite()\0on_Favourites_clicked()\0"
    "for_SettingFocus()\0nindex2\0"
    "for_SettingFocus(int)\0clearallTabs()\0"
    "fornumberofsongs()\0"
    "stateChangedetect(QMediaPlayer::State)\0"
    "sname,pbutton\0seticonimage(QString,QPushButton*)\0"
    "seticonsforfirsttime()\0on_Favourite_clicked()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_Play_toggle_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_Next_clicked(); break;
        case 2: on_Previous_clicked(); break;
        case 3: on_Switch_View_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: on_duration_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: on_Repeat_clicked(); break;
        case 6: on_Shuffle_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: on_verticalScrollBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 9: on_Seek_bar_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_AllSongs_clicked(); break;
        case 11: on_Songs_Widget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: on_Albums_clicked(); break;
        case 13: on_Artists_clicked(); break;
        case 14: on_Album_Artist_Widget_itemClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 15: isfavourite(); break;
        case 16: on_Favourites_clicked(); break;
        case 17: for_SettingFocus(); break;
        case 18: for_SettingFocus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: clearallTabs(); break;
        case 20: fornumberofsongs(); break;
        case 21: stateChangedetect((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 22: seticonimage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QPushButton*(*)>(_a[2]))); break;
        case 23: seticonsforfirsttime(); break;
        case 24: on_Favourite_clicked(); break;
        default: ;
        }
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
