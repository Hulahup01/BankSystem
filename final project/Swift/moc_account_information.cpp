/****************************************************************************
** Meta object code from reading C++ file 'account_information.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../account_information.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'account_information.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Account_information_t {
    const uint offsetsAndSize[24];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Account_information_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Account_information_t qt_meta_stringdata_Account_information = {
    {
QT_MOC_LITERAL(0, 19), // "Account_information"
QT_MOC_LITERAL(20, 36), // "signal_CheckData_Account_Info..."
QT_MOC_LITERAL(57, 0), // ""
QT_MOC_LITERAL(58, 34), // "signal_SignOut_Account_Inform..."
QT_MOC_LITERAL(93, 39), // "signal_RefreshMoney_Account_I..."
QT_MOC_LITERAL(133, 28), // "on_pushButton_SignIn_clicked"
QT_MOC_LITERAL(162, 27), // "on_pushButton_Close_clicked"
QT_MOC_LITERAL(190, 29), // "on_pushButton_SignOut_clicked"
QT_MOC_LITERAL(220, 29), // "on_pushButton_Refresh_clicked"
QT_MOC_LITERAL(250, 44), // "slot_Fail_Incorrect_Data_Acco..."
QT_MOC_LITERAL(295, 44), // "slot_Sending_Information_Acco..."
QT_MOC_LITERAL(340, 42) // "slot_Send_Money_Status_Accoun..."

    },
    "Account_information\0"
    "signal_CheckData_Account_Information\0"
    "\0signal_SignOut_Account_Information\0"
    "signal_RefreshMoney_Account_Information\0"
    "on_pushButton_SignIn_clicked\0"
    "on_pushButton_Close_clicked\0"
    "on_pushButton_SignOut_clicked\0"
    "on_pushButton_Refresh_clicked\0"
    "slot_Fail_Incorrect_Data_Account_Information\0"
    "slot_Sending_Information_Account_Information\0"
    "slot_Send_Money_Status_Account_Information"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Account_information[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    5,   74,    2, 0x06,    1 /* Public */,
       3,    0,   85,    2, 0x06,    7 /* Public */,
       4,    5,   86,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   97,    2, 0x08,   14 /* Private */,
       6,    0,   98,    2, 0x08,   15 /* Private */,
       7,    0,   99,    2, 0x08,   16 /* Private */,
       8,    0,  100,    2, 0x08,   17 /* Private */,
       9,    0,  101,    2, 0x0a,   18 /* Public */,
      10,    8,  102,    2, 0x0a,   19 /* Public */,
      11,    1,  119,    2, 0x0a,   28 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Short, QMetaType::Short,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Short, QMetaType::Short,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Double,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::Double,    2,

       0        // eod
};

void Account_information::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Account_information *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signal_CheckData_Account_Information((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< short(*)>(_a[4])),(*reinterpret_cast< short(*)>(_a[5]))); break;
        case 1: _t->signal_SignOut_Account_Information(); break;
        case 2: _t->signal_RefreshMoney_Account_Information((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< short(*)>(_a[4])),(*reinterpret_cast< short(*)>(_a[5]))); break;
        case 3: _t->on_pushButton_SignIn_clicked(); break;
        case 4: _t->on_pushButton_Close_clicked(); break;
        case 5: _t->on_pushButton_SignOut_clicked(); break;
        case 6: _t->on_pushButton_Refresh_clicked(); break;
        case 7: _t->slot_Fail_Incorrect_Data_Account_Information(); break;
        case 8: _t->slot_Sending_Information_Account_Information((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< double(*)>(_a[8]))); break;
        case 9: _t->slot_Send_Money_Status_Account_Information((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Account_information::*)(QString , QString , QString , short int , short int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account_information::signal_CheckData_Account_Information)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Account_information::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account_information::signal_SignOut_Account_Information)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Account_information::*)(QString , QString , QString , short int , short int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Account_information::signal_RefreshMoney_Account_Information)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Account_information::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Account_information.offsetsAndSize,
    qt_meta_data_Account_information,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Account_information_t
, QtPrivate::TypeAndForceComplete<Account_information, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<short int, std::false_type>, QtPrivate::TypeAndForceComplete<short int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<short int, std::false_type>, QtPrivate::TypeAndForceComplete<short int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>


>,
    nullptr
} };


const QMetaObject *Account_information::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Account_information::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Account_information.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Account_information::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Account_information::signal_CheckData_Account_Information(QString _t1, QString _t2, QString _t3, short int _t4, short int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Account_information::signal_SignOut_Account_Information()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Account_information::signal_RefreshMoney_Account_Information(QString _t1, QString _t2, QString _t3, short int _t4, short int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
