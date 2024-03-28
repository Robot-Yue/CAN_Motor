/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../USBCAN/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[482];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "getValidDatalist"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "onGetProtocolData"
QT_MOC_LITERAL(4, 47, 12), // "VCI_CAN_OBJ*"
QT_MOC_LITERAL(5, 60, 3), // "vci"
QT_MOC_LITERAL(6, 64, 5), // "dwRel"
QT_MOC_LITERAL(7, 70, 7), // "channel"
QT_MOC_LITERAL(8, 78, 11), // "onBoardInfo"
QT_MOC_LITERAL(9, 90, 14), // "VCI_BOARD_INFO"
QT_MOC_LITERAL(10, 105, 3), // "vbi"
QT_MOC_LITERAL(11, 109, 28), // "on_pushButtonOpenCan_clicked"
QT_MOC_LITERAL(12, 138, 29), // "on_pushButton_InitCan_clicked"
QT_MOC_LITERAL(13, 168, 30), // "on_pushButton_startCan_clicked"
QT_MOC_LITERAL(14, 199, 29), // "on_pushButton_speedUp_clicked"
QT_MOC_LITERAL(15, 229, 31), // "on_pushButton_speeddown_clicked"
QT_MOC_LITERAL(16, 261, 31), // "on_pushButton_speedStop_clicked"
QT_MOC_LITERAL(17, 293, 32), // "on_pushButton_pulseStart_clicked"
QT_MOC_LITERAL(18, 326, 33), // "on_pushButton_PositionAsk_cli..."
QT_MOC_LITERAL(19, 360, 18), // "onGetValidDatalist"
QT_MOC_LITERAL(20, 379, 34), // "on_pushButton_PositionAskM_cl..."
QT_MOC_LITERAL(21, 414, 29), // "on_pushButton_SetZero_clicked"
QT_MOC_LITERAL(22, 444, 37) // "on_pushButton_gotoLimitSwitch..."

    },
    "MainWindow\0getValidDatalist\0\0"
    "onGetProtocolData\0VCI_CAN_OBJ*\0vci\0"
    "dwRel\0channel\0onBoardInfo\0VCI_BOARD_INFO\0"
    "vbi\0on_pushButtonOpenCan_clicked\0"
    "on_pushButton_InitCan_clicked\0"
    "on_pushButton_startCan_clicked\0"
    "on_pushButton_speedUp_clicked\0"
    "on_pushButton_speeddown_clicked\0"
    "on_pushButton_speedStop_clicked\0"
    "on_pushButton_pulseStart_clicked\0"
    "on_pushButton_PositionAsk_clicked\0"
    "onGetValidDatalist\0"
    "on_pushButton_PositionAskM_clicked\0"
    "on_pushButton_SetZero_clicked\0"
    "on_pushButton_gotoLimitSwitch_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   90,    2, 0x08 /* Private */,
       8,    1,   97,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    0,  106,    2, 0x08 /* Private */,
      18,    0,  107,    2, 0x08 /* Private */,
      19,    0,  108,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,
      21,    0,  110,    2, 0x08 /* Private */,
      22,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::UInt, QMetaType::UInt,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
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
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getValidDatalist(); break;
        case 1: _t->onGetProtocolData((*reinterpret_cast< VCI_CAN_OBJ*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3]))); break;
        case 2: _t->onBoardInfo((*reinterpret_cast< VCI_BOARD_INFO(*)>(_a[1]))); break;
        case 3: _t->on_pushButtonOpenCan_clicked(); break;
        case 4: _t->on_pushButton_InitCan_clicked(); break;
        case 5: _t->on_pushButton_startCan_clicked(); break;
        case 6: _t->on_pushButton_speedUp_clicked(); break;
        case 7: _t->on_pushButton_speeddown_clicked(); break;
        case 8: _t->on_pushButton_speedStop_clicked(); break;
        case 9: _t->on_pushButton_pulseStart_clicked(); break;
        case 10: _t->on_pushButton_PositionAsk_clicked(); break;
        case 11: _t->onGetValidDatalist(); break;
        case 12: _t->on_pushButton_PositionAskM_clicked(); break;
        case 13: _t->on_pushButton_SetZero_clicked(); break;
        case 14: _t->on_pushButton_gotoLimitSwitch_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::getValidDatalist)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::getValidDatalist()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
