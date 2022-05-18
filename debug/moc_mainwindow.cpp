/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[42];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 13), // "keyPressEvent"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 10), // "QKeyEvent*"
QT_MOC_LITERAL(37, 5), // "event"
QT_MOC_LITERAL(43, 9), // "handleAdd"
QT_MOC_LITERAL(53, 12), // "handleUpdate"
QT_MOC_LITERAL(66, 12), // "handleRemove"
QT_MOC_LITERAL(79, 12), // "handleSortID"
QT_MOC_LITERAL(92, 14), // "handleSortName"
QT_MOC_LITERAL(107, 15), // "handleSortStock"
QT_MOC_LITERAL(123, 15), // "handleSortPrice"
QT_MOC_LITERAL(139, 15), // "handleSortSugar"
QT_MOC_LITERAL(155, 14), // "handleSortType"
QT_MOC_LITERAL(170, 16), // "handleFilterName"
QT_MOC_LITERAL(187, 17), // "handleFilterStock"
QT_MOC_LITERAL(205, 17), // "handleFilterPrice"
QT_MOC_LITERAL(223, 17), // "handleFilterSugar"
QT_MOC_LITERAL(241, 16), // "handleFilterType"
QT_MOC_LITERAL(258, 10), // "handleUndo"
QT_MOC_LITERAL(269, 10) // "handleRedo"

    },
    "MainWindow\0keyPressEvent\0\0QKeyEvent*\0"
    "event\0handleAdd\0handleUpdate\0handleRemove\0"
    "handleSortID\0handleSortName\0handleSortStock\0"
    "handleSortPrice\0handleSortSugar\0"
    "handleSortType\0handleFilterName\0"
    "handleFilterStock\0handleFilterPrice\0"
    "handleFilterSugar\0handleFilterType\0"
    "handleUndo\0handleRedo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    2, 0x08,    1 /* Private */,
       5,    0,  119,    2, 0x08,    3 /* Private */,
       6,    0,  120,    2, 0x08,    4 /* Private */,
       7,    0,  121,    2, 0x08,    5 /* Private */,
       8,    0,  122,    2, 0x08,    6 /* Private */,
       9,    0,  123,    2, 0x08,    7 /* Private */,
      10,    0,  124,    2, 0x08,    8 /* Private */,
      11,    0,  125,    2, 0x08,    9 /* Private */,
      12,    0,  126,    2, 0x08,   10 /* Private */,
      13,    0,  127,    2, 0x08,   11 /* Private */,
      14,    0,  128,    2, 0x08,   12 /* Private */,
      15,    0,  129,    2, 0x08,   13 /* Private */,
      16,    0,  130,    2, 0x08,   14 /* Private */,
      17,    0,  131,    2, 0x08,   15 /* Private */,
      18,    0,  132,    2, 0x08,   16 /* Private */,
      19,    0,  133,    2, 0x08,   17 /* Private */,
      20,    0,  134,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->keyPressEvent((*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[1]))); break;
        case 1: _t->handleAdd(); break;
        case 2: _t->handleUpdate(); break;
        case 3: _t->handleRemove(); break;
        case 4: _t->handleSortID(); break;
        case 5: _t->handleSortName(); break;
        case 6: _t->handleSortStock(); break;
        case 7: _t->handleSortPrice(); break;
        case 8: _t->handleSortSugar(); break;
        case 9: _t->handleSortType(); break;
        case 10: _t->handleFilterName(); break;
        case 11: _t->handleFilterStock(); break;
        case 12: _t->handleFilterPrice(); break;
        case 13: _t->handleFilterSugar(); break;
        case 14: _t->handleFilterType(); break;
        case 15: _t->handleUndo(); break;
        case 16: _t->handleRedo(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
