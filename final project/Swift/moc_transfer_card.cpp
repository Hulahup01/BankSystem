/****************************************************************************
** Meta object code from reading C++ file 'transfer_card.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../transfer_card.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'transfer_card.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Transfer_card_t {
    const uint offsetsAndSize[18];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Transfer_card_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Transfer_card_t qt_meta_stringdata_Transfer_card = {
    {
QT_MOC_LITERAL(0, 13), // "Transfer_card"
QT_MOC_LITERAL(14, 24), // "on_step_1_button_clicked"
QT_MOC_LITERAL(39, 0), // ""
QT_MOC_LITERAL(40, 24), // "on_step_2_button_clicked"
QT_MOC_LITERAL(65, 24), // "on_step_3_button_clicked"
QT_MOC_LITERAL(90, 29), // "on_card_numb_edit_textChanged"
QT_MOC_LITERAL(120, 4), // "arg1"
QT_MOC_LITERAL(125, 27), // "on_gift_no_perc_textChanged"
QT_MOC_LITERAL(153, 31) // "on_card_numb_edit_2_textChanged"

    },
    "Transfer_card\0on_step_1_button_clicked\0"
    "\0on_step_2_button_clicked\0"
    "on_step_3_button_clicked\0"
    "on_card_numb_edit_textChanged\0arg1\0"
    "on_gift_no_perc_textChanged\0"
    "on_card_numb_edit_2_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Transfer_card[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    1,   53,    2, 0x08,    4 /* Private */,
       7,    1,   56,    2, 0x08,    6 /* Private */,
       8,    1,   59,    2, 0x08,    8 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void Transfer_card::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Transfer_card *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_step_1_button_clicked(); break;
        case 1: _t->on_step_2_button_clicked(); break;
        case 2: _t->on_step_3_button_clicked(); break;
        case 3: _t->on_card_numb_edit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_gift_no_perc_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_card_numb_edit_2_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Transfer_card::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Transfer_card.offsetsAndSize,
    qt_meta_data_Transfer_card,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Transfer_card_t
, QtPrivate::TypeAndForceComplete<Transfer_card, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *Transfer_card::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Transfer_card::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Transfer_card.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Transfer_card::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
