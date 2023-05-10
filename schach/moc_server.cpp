/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Server_t {
    QByteArrayData data[33];
    char stringdata0[342];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Server_t qt_meta_stringdata_Server = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Server"
QT_MOC_LITERAL(1, 7, 9), // "initLogic"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 14), // "colorSelection"
QT_MOC_LITERAL(4, 33, 5), // "color"
QT_MOC_LITERAL(5, 39, 11), // "triggerMove"
QT_MOC_LITERAL(6, 51, 5), // "fromX"
QT_MOC_LITERAL(7, 57, 5), // "fromY"
QT_MOC_LITERAL(8, 63, 3), // "toX"
QT_MOC_LITERAL(9, 67, 3), // "toY"
QT_MOC_LITERAL(10, 71, 4), // "type"
QT_MOC_LITERAL(11, 76, 11), // "concequence"
QT_MOC_LITERAL(12, 88, 12), // "turnFinished"
QT_MOC_LITERAL(13, 101, 8), // "startGui"
QT_MOC_LITERAL(14, 110, 12), // "startingSide"
QT_MOC_LITERAL(15, 123, 9), // "firstToGo"
QT_MOC_LITERAL(16, 133, 16), // "triggerPromotion"
QT_MOC_LITERAL(17, 150, 20), // "guiCloseNotification"
QT_MOC_LITERAL(18, 171, 10), // "initServer"
QT_MOC_LITERAL(19, 182, 9), // "setSocket"
QT_MOC_LITERAL(20, 192, 15), // "closeConnection"
QT_MOC_LITERAL(21, 208, 11), // "socketError"
QT_MOC_LITERAL(22, 220, 15), // "sendStartSignal"
QT_MOC_LITERAL(23, 236, 13), // "recieveSignal"
QT_MOC_LITERAL(24, 250, 10), // "sendSignal"
QT_MOC_LITERAL(25, 261, 3), // "cmd"
QT_MOC_LITERAL(26, 265, 8), // "startRow"
QT_MOC_LITERAL(27, 274, 11), // "startColumn"
QT_MOC_LITERAL(28, 286, 9), // "targetRow"
QT_MOC_LITERAL(29, 296, 12), // "targetColumn"
QT_MOC_LITERAL(30, 309, 13), // "promotionType"
QT_MOC_LITERAL(31, 323, 11), // "concequense"
QT_MOC_LITERAL(32, 335, 6) // "status"

    },
    "Server\0initLogic\0\0colorSelection\0color\0"
    "triggerMove\0fromX\0fromY\0toX\0toY\0type\0"
    "concequence\0turnFinished\0startGui\0"
    "startingSide\0firstToGo\0triggerPromotion\0"
    "guiCloseNotification\0initServer\0"
    "setSocket\0closeConnection\0socketError\0"
    "sendStartSignal\0recieveSignal\0sendSignal\0"
    "cmd\0startRow\0startColumn\0targetRow\0"
    "targetColumn\0promotionType\0concequense\0"
    "status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Server[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  124,    2, 0x06 /* Public */,
       3,    1,  125,    2, 0x06 /* Public */,
       5,    6,  128,    2, 0x06 /* Public */,
      12,    0,  141,    2, 0x06 /* Public */,
      13,    1,  142,    2, 0x06 /* Public */,
      14,    1,  145,    2, 0x06 /* Public */,
      16,    0,  148,    2, 0x06 /* Public */,
      17,    0,  149,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  150,    2, 0x0a /* Public */,
      19,    0,  151,    2, 0x0a /* Public */,
      20,    0,  152,    2, 0x0a /* Public */,
      21,    0,  153,    2, 0x0a /* Public */,
      22,    0,  154,    2, 0x0a /* Public */,
      23,    0,  155,    2, 0x0a /* Public */,
      24,    8,  156,    2, 0x0a /* Public */,
      24,    7,  173,    2, 0x2a /* Public | MethodCloned */,
      24,    6,  188,    2, 0x2a /* Public | MethodCloned */,
      24,    5,  201,    2, 0x2a /* Public | MethodCloned */,
      24,    4,  212,    2, 0x2a /* Public | MethodCloned */,
      24,    3,  221,    2, 0x2a /* Public | MethodCloned */,
      24,    2,  228,    2, 0x2a /* Public | MethodCloned */,
      24,    1,  233,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    6,    7,    8,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   25,   26,   27,   28,   29,   30,   31,   32,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   25,   26,   27,   28,   29,   30,   31,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   25,   26,   27,   28,   29,   30,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   25,   26,   27,   28,   29,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   25,   26,   27,   28,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   25,   26,   27,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar,   25,   26,
    QMetaType::Void, QMetaType::UChar,   25,

       0        // eod
};

void Server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initLogic(); break;
        case 1: _t->colorSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->triggerMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 3: _t->turnFinished(); break;
        case 4: _t->startGui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->startingSide((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->triggerPromotion(); break;
        case 7: _t->guiCloseNotification(); break;
        case 8: _t->initServer(); break;
        case 9: _t->setSocket(); break;
        case 10: _t->closeConnection(); break;
        case 11: _t->socketError(); break;
        case 12: _t->sendStartSignal(); break;
        case 13: _t->recieveSignal(); break;
        case 14: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6])),(*reinterpret_cast< quint8(*)>(_a[7])),(*reinterpret_cast< quint8(*)>(_a[8]))); break;
        case 15: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6])),(*reinterpret_cast< quint8(*)>(_a[7]))); break;
        case 16: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6]))); break;
        case 17: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 18: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4]))); break;
        case 19: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 20: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 21: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::initLogic)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::colorSelection)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Server::*)(int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::triggerMove)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::turnFinished)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::startGui)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Server::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::startingSide)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::triggerPromotion)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Server::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Server::guiCloseNotification)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Server::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Server.data,
    qt_meta_data_Server,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Server.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Server::initLogic()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Server::colorSelection(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Server::triggerMove(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Server::turnFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Server::startGui(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Server::startingSide(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Server::triggerPromotion()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Server::guiCloseNotification()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
