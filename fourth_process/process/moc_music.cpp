/****************************************************************************
** Meta object code from reading C++ file 'music.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "music.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'music.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Music_t {
    QByteArrayData data[16];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Music_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Music_t qt_meta_stringdata_Music = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Music"
QT_MOC_LITERAL(1, 6, 24), // "on_pushButton_up_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 32), // "on_pushButton_start_stop_clicked"
QT_MOC_LITERAL(4, 65, 26), // "on_pushButton_next_clicked"
QT_MOC_LITERAL(5, 92, 14), // "read_something"
QT_MOC_LITERAL(6, 107, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(7, 140, 5), // "value"
QT_MOC_LITERAL(8, 146, 12), // "get_sec_time"
QT_MOC_LITERAL(9, 159, 12), // "get_pos_time"
QT_MOC_LITERAL(10, 172, 11), // "display_lrc"
QT_MOC_LITERAL(11, 184, 26), // "on_pushButton_exit_clicked"
QT_MOC_LITERAL(12, 211, 26), // "on_pushButton_minu_clicked"
QT_MOC_LITERAL(13, 238, 25), // "on_pushButton_add_clicked"
QT_MOC_LITERAL(14, 264, 21), // "on_listWidget_clicked"
QT_MOC_LITERAL(15, 286, 5) // "index"

    },
    "Music\0on_pushButton_up_clicked\0\0"
    "on_pushButton_start_stop_clicked\0"
    "on_pushButton_next_clicked\0read_something\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "get_sec_time\0get_pos_time\0display_lrc\0"
    "on_pushButton_exit_clicked\0"
    "on_pushButton_minu_clicked\0"
    "on_pushButton_add_clicked\0"
    "on_listWidget_clicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Music[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    1,   78,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    1,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   15,

       0        // eod
};

void Music::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Music *_t = static_cast<Music *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_up_clicked(); break;
        case 1: _t->on_pushButton_start_stop_clicked(); break;
        case 2: _t->on_pushButton_next_clicked(); break;
        case 3: _t->read_something(); break;
        case 4: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->get_sec_time(); break;
        case 6: _t->get_pos_time(); break;
        case 7: _t->display_lrc(); break;
        case 8: _t->on_pushButton_exit_clicked(); break;
        case 9: _t->on_pushButton_minu_clicked(); break;
        case 10: _t->on_pushButton_add_clicked(); break;
        case 11: _t->on_listWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Music::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Music.data,
      qt_meta_data_Music,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Music::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Music::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Music.stringdata0))
        return static_cast<void*>(const_cast< Music*>(this));
    return QDialog::qt_metacast(_clname);
}

int Music::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
