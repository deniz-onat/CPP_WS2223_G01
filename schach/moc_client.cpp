/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[42];
    char stringdata0[433];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Client_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Client"
QT_MOC_LITERAL(1, 7, 9), // "initLogic"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "triggerMove"
QT_MOC_LITERAL(4, 30, 5), // "fromX"
QT_MOC_LITERAL(5, 36, 5), // "fromY"
QT_MOC_LITERAL(6, 42, 3), // "toX"
QT_MOC_LITERAL(7, 46, 3), // "toY"
QT_MOC_LITERAL(8, 50, 4), // "type"
QT_MOC_LITERAL(9, 55, 11), // "consequence"
QT_MOC_LITERAL(10, 67, 12), // "turnFinished"
QT_MOC_LITERAL(11, 80, 8), // "startGui"
QT_MOC_LITERAL(12, 89, 12), // "startingSide"
QT_MOC_LITERAL(13, 102, 9), // "firstToGo"
QT_MOC_LITERAL(14, 112, 9), // "launchGui"
QT_MOC_LITERAL(15, 122, 14), // "colorSelection"
QT_MOC_LITERAL(16, 137, 5), // "color"
QT_MOC_LITERAL(17, 143, 12), // "getPromotion"
QT_MOC_LITERAL(18, 156, 1), // "x"
QT_MOC_LITERAL(19, 158, 1), // "y"
QT_MOC_LITERAL(20, 160, 16), // "triggerPromotion"
QT_MOC_LITERAL(21, 177, 20), // "guiCloseNotification"
QT_MOC_LITERAL(22, 198, 15), // "connectToServer"
QT_MOC_LITERAL(23, 214, 16), // "enableConnection"
QT_MOC_LITERAL(24, 231, 20), // "disconnectFromServer"
QT_MOC_LITERAL(25, 252, 12), // "disconnected"
QT_MOC_LITERAL(26, 265, 15), // "closeConnection"
QT_MOC_LITERAL(27, 281, 11), // "socketError"
QT_MOC_LITERAL(28, 293, 13), // "setHostAddres"
QT_MOC_LITERAL(29, 307, 6), // "addres"
QT_MOC_LITERAL(30, 314, 7), // "setPort"
QT_MOC_LITERAL(31, 322, 4), // "port"
QT_MOC_LITERAL(32, 327, 13), // "recieveSignal"
QT_MOC_LITERAL(33, 341, 10), // "sendSignal"
QT_MOC_LITERAL(34, 352, 3), // "cmd"
QT_MOC_LITERAL(35, 356, 8), // "startRow"
QT_MOC_LITERAL(36, 365, 11), // "startColumn"
QT_MOC_LITERAL(37, 377, 9), // "targetRow"
QT_MOC_LITERAL(38, 387, 12), // "targetColumn"
QT_MOC_LITERAL(39, 400, 13), // "promotionType"
QT_MOC_LITERAL(40, 414, 11), // "concequense"
QT_MOC_LITERAL(41, 426, 6) // "status"

    },
    "Client\0initLogic\0\0triggerMove\0fromX\0"
    "fromY\0toX\0toY\0type\0consequence\0"
    "turnFinished\0startGui\0startingSide\0"
    "firstToGo\0launchGui\0colorSelection\0"
    "color\0getPromotion\0x\0y\0triggerPromotion\0"
    "guiCloseNotification\0connectToServer\0"
    "enableConnection\0disconnectFromServer\0"
    "disconnected\0closeConnection\0socketError\0"
    "setHostAddres\0addres\0setPort\0port\0"
    "recieveSignal\0sendSignal\0cmd\0startRow\0"
    "startColumn\0targetRow\0targetColumn\0"
    "promotionType\0concequense\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  149,    2, 0x06 /* Public */,
       3,    6,  150,    2, 0x06 /* Public */,
      10,    0,  163,    2, 0x06 /* Public */,
      11,    1,  164,    2, 0x06 /* Public */,
      12,    1,  167,    2, 0x06 /* Public */,
      14,    0,  170,    2, 0x06 /* Public */,
      15,    1,  171,    2, 0x06 /* Public */,
      17,    3,  174,    2, 0x06 /* Public */,
      20,    0,  181,    2, 0x06 /* Public */,
      21,    0,  182,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      22,    0,  183,    2, 0x0a /* Public */,
      23,    0,  184,    2, 0x0a /* Public */,
      24,    0,  185,    2, 0x0a /* Public */,
      25,    0,  186,    2, 0x0a /* Public */,
      26,    0,  187,    2, 0x0a /* Public */,
      27,    0,  188,    2, 0x0a /* Public */,
      28,    1,  189,    2, 0x0a /* Public */,
      30,    1,  192,    2, 0x0a /* Public */,
      32,    0,  195,    2, 0x0a /* Public */,
      33,    8,  196,    2, 0x0a /* Public */,
      33,    7,  213,    2, 0x2a /* Public | MethodCloned */,
      33,    6,  228,    2, 0x2a /* Public | MethodCloned */,
      33,    5,  241,    2, 0x2a /* Public | MethodCloned */,
      33,    4,  252,    2, 0x2a /* Public | MethodCloned */,
      33,    3,  261,    2, 0x2a /* Public | MethodCloned */,
      33,    2,  268,    2, 0x2a /* Public | MethodCloned */,
      33,    1,  273,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   18,   19,    8,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   34,   35,   36,   37,   38,   39,   40,   41,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   34,   35,   36,   37,   38,   39,   40,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   34,   35,   36,   37,   38,   39,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   34,   35,   36,   37,   38,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   34,   35,   36,   37,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   34,   35,   36,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar,   34,   35,
    QMetaType::Void, QMetaType::UChar,   34,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initLogic(); break;
        case 1: _t->triggerMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 2: _t->turnFinished(); break;
        case 3: _t->startGui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->startingSide((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->launchGui(); break;
        case 6: _t->colorSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->getPromotion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->triggerPromotion(); break;
        case 9: _t->guiCloseNotification(); break;
        case 10: _t->connectToServer(); break;
        case 11: _t->enableConnection(); break;
        case 12: _t->disconnectFromServer(); break;
        case 13: _t->disconnected(); break;
        case 14: _t->closeConnection(); break;
        case 15: _t->socketError(); break;
        case 16: _t->setHostAddres((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->setPort((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->recieveSignal(); break;
        case 19: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6])),(*reinterpret_cast< quint8(*)>(_a[7])),(*reinterpret_cast< quint8(*)>(_a[8]))); break;
        case 20: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6])),(*reinterpret_cast< quint8(*)>(_a[7]))); break;
        case 21: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6]))); break;
        case 22: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5]))); break;
        case 23: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4]))); break;
        case 24: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3]))); break;
        case 25: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2]))); break;
        case 26: _t->sendSignal((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::initLogic)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)(int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::triggerMove)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::turnFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::startGui)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::startingSide)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::launchGui)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Client::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::colorSelection)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Client::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::getPromotion)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::triggerPromotion)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Client::guiCloseNotification)) {
                *result = 9;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Client::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Client.data,
    qt_meta_data_Client,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void Client::initLogic()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Client::triggerMove(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Client::turnFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Client::startGui(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Client::startingSide(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Client::launchGui()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Client::colorSelection(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Client::getPromotion(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Client::triggerPromotion()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Client::guiCloseNotification()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
