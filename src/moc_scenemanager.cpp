/****************************************************************************
** Meta object code from reading C++ file 'scenemanager.h'
**
** Created: Fri Jun 18 09:09:43 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scenemanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scenemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SceneManager[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   14,   13,   13, 0x0a,
      37,   14,   13,   13, 0x0a,
      55,   51,   13,   13, 0x0a,
      87,   13,   13,   13, 0x0a,
     112,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SceneManager[] = {
    "SceneManager\0\0fileName\0save(QString)\0"
    "load(QString)\0idx\0currentItemChanged(QModelIndex)\0"
    "duplicateSelectedItems()\0deleteSelectedItems()\0"
};

const QMetaObject SceneManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SceneManager,
      qt_meta_data_SceneManager, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SceneManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SceneManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SceneManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SceneManager))
        return static_cast<void*>(const_cast< SceneManager*>(this));
    return QObject::qt_metacast(_clname);
}

int SceneManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: save((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: load((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: currentItemChanged((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: duplicateSelectedItems(); break;
        case 4: deleteSelectedItems(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE