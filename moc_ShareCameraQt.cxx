/****************************************************************************
** Meta object code from reading C++ file 'ShareCameraQt.h'
**
** Created: Sat Mar 16 14:46:23 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ShareCameraQt.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShareCameraQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ShareCameraQt[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      26,   14,   14,   14, 0x08,
      50,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ShareCameraQt[] = {
    "ShareCameraQt\0\0slotExit()\0"
    "on_pushButton_clicked()\0"
    "on_pushButton_2_clicked()\0"
};

void ShareCameraQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ShareCameraQt *_t = static_cast<ShareCameraQt *>(_o);
        switch (_id) {
        case 0: _t->slotExit(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ShareCameraQt::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ShareCameraQt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ShareCameraQt,
      qt_meta_data_ShareCameraQt, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ShareCameraQt::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ShareCameraQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ShareCameraQt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ShareCameraQt))
        return static_cast<void*>(const_cast< ShareCameraQt*>(this));
    if (!strcmp(_clname, "Ui::ShareCameraQt"))
        return static_cast< Ui::ShareCameraQt*>(const_cast< ShareCameraQt*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ShareCameraQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
