/****************************************************************************
** Meta object code from reading C++ file 'video.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "video.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'video.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Video_t {
    QByteArrayData data[16];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Video_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Video_t qt_meta_stringdata_Video = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Video"
QT_MOC_LITERAL(1, 6, 27), // "on_pushButton_start_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 26), // "on_pushButton_down_clicked"
QT_MOC_LITERAL(4, 62, 27), // "on_pushButton_pause_clicked"
QT_MOC_LITERAL(5, 90, 24), // "on_pushButton_up_clicked"
QT_MOC_LITERAL(6, 115, 25), // "on_pushButton_end_clicked"
QT_MOC_LITERAL(7, 141, 34), // "on_horizontalSlider_2_valueCh..."
QT_MOC_LITERAL(8, 176, 5), // "value"
QT_MOC_LITERAL(9, 182, 27), // "on_progressBar_valueChanged"
QT_MOC_LITERAL(10, 210, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(11, 243, 13), // "read_all_data"
QT_MOC_LITERAL(12, 257, 8), // "get_time"
QT_MOC_LITERAL(13, 266, 27), // "on_pushButton_speed_clicked"
QT_MOC_LITERAL(14, 294, 21), // "on_listWidget_clicked"
QT_MOC_LITERAL(15, 316, 5) // "index"

    },
    "Video\0on_pushButton_start_clicked\0\0"
    "on_pushButton_down_clicked\0"
    "on_pushButton_pause_clicked\0"
    "on_pushButton_up_clicked\0"
    "on_pushButton_end_clicked\0"
    "on_horizontalSlider_2_valueChanged\0"
    "value\0on_progressBar_valueChanged\0"
    "on_horizontalSlider_valueChanged\0"
    "read_all_data\0get_time\0"
    "on_pushButton_speed_clicked\0"
    "on_listWidget_clicked\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Video[] = {

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
       6,    0,   78,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
       9,    1,   82,    2, 0x08 /* Private */,
      10,    1,   85,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    1,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,   15,

       0        // eod
};

void Video::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Video *_t = static_cast<Video *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_start_clicked(); break;
        case 1: _t->on_pushButton_down_clicked(); break;
        case 2: _t->on_pushButton_pause_clicked(); break;
        case 3: _t->on_pushButton_up_clicked(); break;
        case 4: _t->on_pushButton_end_clicked(); break;
        case 5: _t->on_horizontalSlider_2_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_progressBar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->read_all_data(); break;
        case 9: _t->get_time(); break;
        case 10: _t->on_pushButton_speed_clicked(); break;
        case 11: _t->on_listWidget_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Video::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Video.data,
      qt_meta_data_Video,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Video::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Video::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Video.stringdata0))
        return static_cast<void*>(const_cast< Video*>(this));
    return QDialog::qt_metacast(_clname);
}

int Video::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
