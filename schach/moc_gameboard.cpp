/****************************************************************************
** Meta object code from reading C++ file 'gameboard.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gameboard.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameboard.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Gameboard_t {
    QByteArrayData data[42];
    char stringdata0[416];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gameboard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gameboard_t qt_meta_stringdata_Gameboard = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Gameboard"
QT_MOC_LITERAL(1, 10, 7), // "initGui"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 4), // "turn"
QT_MOC_LITERAL(4, 24, 8), // "sendMove"
QT_MOC_LITERAL(5, 33, 5), // "fromX"
QT_MOC_LITERAL(6, 39, 5), // "fromY"
QT_MOC_LITERAL(7, 45, 3), // "toX"
QT_MOC_LITERAL(8, 49, 3), // "toY"
QT_MOC_LITERAL(9, 53, 14), // "sendLegalMoves"
QT_MOC_LITERAL(10, 68, 32), // "std::vector<std::pair<int,int> >"
QT_MOC_LITERAL(11, 101, 11), // "_legalMoves"
QT_MOC_LITERAL(12, 113, 6), // "_fromX"
QT_MOC_LITERAL(13, 120, 6), // "_fromY"
QT_MOC_LITERAL(14, 127, 12), // "sendNotLegal"
QT_MOC_LITERAL(15, 140, 15), // "networkSendMove"
QT_MOC_LITERAL(16, 156, 3), // "cmd"
QT_MOC_LITERAL(17, 160, 8), // "startRow"
QT_MOC_LITERAL(18, 169, 12), // "startColumun"
QT_MOC_LITERAL(19, 182, 9), // "targetRow"
QT_MOC_LITERAL(20, 192, 12), // "targetColumn"
QT_MOC_LITERAL(21, 205, 13), // "promotionType"
QT_MOC_LITERAL(22, 219, 11), // "consequence"
QT_MOC_LITERAL(23, 231, 6), // "status"
QT_MOC_LITERAL(24, 238, 13), // "sendPromotion"
QT_MOC_LITERAL(25, 252, 1), // "x"
QT_MOC_LITERAL(26, 254, 9), // "sendCheck"
QT_MOC_LITERAL(27, 264, 1), // "y"
QT_MOC_LITERAL(28, 266, 11), // "hasPromoted"
QT_MOC_LITERAL(29, 278, 4), // "type"
QT_MOC_LITERAL(30, 283, 16), // "getPromotionType"
QT_MOC_LITERAL(31, 300, 9), // "logicTurn"
QT_MOC_LITERAL(32, 310, 5), // "_turn"
QT_MOC_LITERAL(33, 316, 10), // "guiChecked"
QT_MOC_LITERAL(34, 327, 10), // "sendCastle"
QT_MOC_LITERAL(35, 338, 7), // "endGame"
QT_MOC_LITERAL(36, 346, 13), // "initGameboard"
QT_MOC_LITERAL(37, 360, 8), // "getClick"
QT_MOC_LITERAL(38, 369, 12), // "getPromotion"
QT_MOC_LITERAL(39, 382, 14), // "setPlayerColor"
QT_MOC_LITERAL(40, 397, 5), // "color"
QT_MOC_LITERAL(41, 403, 12) // "networkInput"

    },
    "Gameboard\0initGui\0\0turn\0sendMove\0fromX\0"
    "fromY\0toX\0toY\0sendLegalMoves\0"
    "std::vector<std::pair<int,int> >\0"
    "_legalMoves\0_fromX\0_fromY\0sendNotLegal\0"
    "networkSendMove\0cmd\0startRow\0startColumun\0"
    "targetRow\0targetColumn\0promotionType\0"
    "consequence\0status\0sendPromotion\0x\0"
    "sendCheck\0y\0hasPromoted\0type\0"
    "getPromotionType\0logicTurn\0_turn\0"
    "guiChecked\0sendCastle\0endGame\0"
    "initGameboard\0getClick\0getPromotion\0"
    "setPlayerColor\0color\0networkInput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gameboard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       4,    4,  107,    2, 0x06 /* Public */,
       9,    3,  116,    2, 0x06 /* Public */,
      14,    0,  123,    2, 0x06 /* Public */,
      15,    8,  124,    2, 0x06 /* Public */,
      24,    1,  141,    2, 0x06 /* Public */,
      26,    2,  144,    2, 0x06 /* Public */,
      28,    3,  149,    2, 0x06 /* Public */,
      30,    1,  156,    2, 0x06 /* Public */,
      31,    1,  159,    2, 0x06 /* Public */,
      33,    0,  162,    2, 0x06 /* Public */,
      34,    0,  163,    2, 0x06 /* Public */,
      35,    2,  164,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      36,    0,  169,    2, 0x0a /* Public */,
      37,    2,  170,    2, 0x0a /* Public */,
      38,    1,  175,    2, 0x0a /* Public */,
      39,    1,  178,    2, 0x0a /* Public */,
      41,    6,  181,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int, QMetaType::Int,   11,   12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar, QMetaType::UChar,   16,   17,   18,   19,   20,   21,   22,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   25,   27,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   25,   27,   29,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   29,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   25,   27,
    QMetaType::Void, QMetaType::Int,   29,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    5,    6,    7,    8,   21,   22,

       0        // eod
};

void Gameboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Gameboard *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->initGui((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sendMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->sendLegalMoves((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->sendNotLegal(); break;
        case 4: _t->networkSendMove((*reinterpret_cast< quint8(*)>(_a[1])),(*reinterpret_cast< quint8(*)>(_a[2])),(*reinterpret_cast< quint8(*)>(_a[3])),(*reinterpret_cast< quint8(*)>(_a[4])),(*reinterpret_cast< quint8(*)>(_a[5])),(*reinterpret_cast< quint8(*)>(_a[6])),(*reinterpret_cast< quint8(*)>(_a[7])),(*reinterpret_cast< quint8(*)>(_a[8]))); break;
        case 5: _t->sendPromotion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->sendCheck((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->hasPromoted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->getPromotionType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->logicTurn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->guiChecked(); break;
        case 11: _t->sendCastle(); break;
        case 12: _t->endGame((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->initGameboard(); break;
        case 14: _t->getClick((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->getPromotion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setPlayerColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->networkInput((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Gameboard::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::initGui)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::sendMove)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(std::vector<std::pair<int,int>> , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::sendLegalMoves)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::sendNotLegal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(quint8 , quint8 , quint8 , quint8 , quint8 , quint8 , quint8 , quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::networkSendMove)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::sendPromotion)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::sendCheck)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::hasPromoted)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::getPromotionType)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::logicTurn)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::guiChecked)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::sendCastle)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Gameboard::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Gameboard::endGame)) {
                *result = 12;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Gameboard::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Gameboard.data,
    qt_meta_data_Gameboard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Gameboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gameboard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Gameboard.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Gameboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Gameboard::initGui(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Gameboard::sendMove(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Gameboard::sendLegalMoves(std::vector<std::pair<int,int>> _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Gameboard::sendNotLegal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Gameboard::networkSendMove(quint8 _t1, quint8 _t2, quint8 _t3, quint8 _t4, quint8 _t5, quint8 _t6, quint8 _t7, quint8 _t8)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)), const_cast<void*>(reinterpret_cast<const void*>(&_t7)), const_cast<void*>(reinterpret_cast<const void*>(&_t8)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Gameboard::sendPromotion(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Gameboard::sendCheck(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Gameboard::hasPromoted(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Gameboard::getPromotionType(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Gameboard::logicTurn(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Gameboard::guiChecked()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void Gameboard::sendCastle()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Gameboard::endGame(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
