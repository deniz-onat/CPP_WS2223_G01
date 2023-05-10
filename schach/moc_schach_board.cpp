/****************************************************************************
** Meta object code from reading C++ file 'schach_board.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "schach_board.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'schach_board.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Board_t {
    QByteArrayData data[31];
    char stringdata0[355];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Board_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Board_t qt_meta_stringdata_Board = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Board"
QT_MOC_LITERAL(1, 6, 9), // "Buttonpos"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 1), // "x"
QT_MOC_LITERAL(4, 19, 1), // "y"
QT_MOC_LITERAL(5, 21, 11), // "mustPromote"
QT_MOC_LITERAL(6, 33, 4), // "type"
QT_MOC_LITERAL(7, 38, 10), // "startBoard"
QT_MOC_LITERAL(8, 49, 9), // "moveLabel"
QT_MOC_LITERAL(9, 59, 5), // "fromX"
QT_MOC_LITERAL(10, 65, 5), // "fromY"
QT_MOC_LITERAL(11, 71, 3), // "toX"
QT_MOC_LITERAL(12, 75, 3), // "toY"
QT_MOC_LITERAL(13, 79, 8), // "highLite"
QT_MOC_LITERAL(14, 88, 32), // "std::vector<std::pair<int,int> >"
QT_MOC_LITERAL(15, 121, 5), // "moves"
QT_MOC_LITERAL(16, 127, 6), // "NoMove"
QT_MOC_LITERAL(17, 134, 10), // "promptShow"
QT_MOC_LITERAL(18, 145, 7), // "Promote"
QT_MOC_LITERAL(19, 153, 11), // "gamePrompts"
QT_MOC_LITERAL(20, 165, 4), // "turn"
QT_MOC_LITERAL(21, 170, 13), // "checkedPrompt"
QT_MOC_LITERAL(22, 184, 10), // "matePrompt"
QT_MOC_LITERAL(23, 195, 19), // "on_fb_WBurg_clicked"
QT_MOC_LITERAL(24, 215, 19), // "on_fb_WPope_clicked"
QT_MOC_LITERAL(25, 235, 20), // "on_fb_WKrieg_clicked"
QT_MOC_LITERAL(26, 256, 18), // "on_fb_WBae_clicked"
QT_MOC_LITERAL(27, 275, 18), // "on_fb_BBae_clicked"
QT_MOC_LITERAL(28, 294, 20), // "on_fb_BKrieg_clicked"
QT_MOC_LITERAL(29, 315, 19), // "on_fb_BPope_clicked"
QT_MOC_LITERAL(30, 335, 19) // "on_fb_BBurg_clicked"

    },
    "Board\0Buttonpos\0\0x\0y\0mustPromote\0type\0"
    "startBoard\0moveLabel\0fromX\0fromY\0toX\0"
    "toY\0highLite\0std::vector<std::pair<int,int> >\0"
    "moves\0NoMove\0promptShow\0Promote\0"
    "gamePrompts\0turn\0checkedPrompt\0"
    "matePrompt\0on_fb_WBurg_clicked\0"
    "on_fb_WPope_clicked\0on_fb_WKrieg_clicked\0"
    "on_fb_WBae_clicked\0on_fb_BBae_clicked\0"
    "on_fb_BKrieg_clicked\0on_fb_BPope_clicked\0"
    "on_fb_BBurg_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Board[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  109,    2, 0x06 /* Public */,
       5,    1,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,  117,    2, 0x0a /* Public */,
       8,    4,  120,    2, 0x0a /* Public */,
      13,    3,  129,    2, 0x0a /* Public */,
      16,    0,  136,    2, 0x0a /* Public */,
      17,    1,  137,    2, 0x0a /* Public */,
      18,    3,  140,    2, 0x0a /* Public */,
      19,    1,  147,    2, 0x0a /* Public */,
      21,    0,  150,    2, 0x0a /* Public */,
      22,    2,  151,    2, 0x0a /* Public */,
      23,    0,  156,    2, 0x08 /* Private */,
      24,    0,  157,    2, 0x08 /* Private */,
      25,    0,  158,    2, 0x08 /* Private */,
      26,    0,  159,    2, 0x08 /* Private */,
      27,    0,  160,    2, 0x08 /* Private */,
      28,    0,  161,    2, 0x08 /* Private */,
      29,    0,  162,    2, 0x08 /* Private */,
      30,    0,  163,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::Int,   15,    9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    6,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,   20,
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

void Board::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Board *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Buttonpos((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->mustPromote((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->startBoard((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->moveLabel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 4: _t->highLite((*reinterpret_cast< std::vector<std::pair<int,int> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: _t->NoMove(); break;
        case 6: _t->promptShow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->Promote((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->gamePrompts((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->checkedPrompt(); break;
        case 10: _t->matePrompt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->on_fb_WBurg_clicked(); break;
        case 12: _t->on_fb_WPope_clicked(); break;
        case 13: _t->on_fb_WKrieg_clicked(); break;
        case 14: _t->on_fb_WBae_clicked(); break;
        case 15: _t->on_fb_BBae_clicked(); break;
        case 16: _t->on_fb_BKrieg_clicked(); break;
        case 17: _t->on_fb_BPope_clicked(); break;
        case 18: _t->on_fb_BBurg_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Board::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::Buttonpos)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Board::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Board::mustPromote)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Board::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Board.data,
    qt_meta_data_Board,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Board::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Board::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Board.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Board::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Board::Buttonpos(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Board::mustPromote(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
