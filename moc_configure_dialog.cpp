/****************************************************************************
** Meta object code from reading C++ file 'configure_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "header/configure_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configure_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ConfigureDialog_t {
    QByteArrayData data[17];
    char stringdata0[474];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigureDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigureDialog_t qt_meta_stringdata_ConfigureDialog = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ConfigureDialog"
QT_MOC_LITERAL(1, 16, 35), // "on_refresh_interval_editingFi..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 27), // "on_showCpu_checkbox_toggled"
QT_MOC_LITERAL(4, 81, 7), // "checked"
QT_MOC_LITERAL(5, 89, 33), // "on_labelFont_size_editingFini..."
QT_MOC_LITERAL(6, 123, 31), // "on_main_opacity_editingFinished"
QT_MOC_LITERAL(7, 155, 29), // "on_select_color_main_released"
QT_MOC_LITERAL(8, 185, 37), // "on_select_color_outer_border_..."
QT_MOC_LITERAL(9, 223, 28), // "on_select_color_mem_released"
QT_MOC_LITERAL(10, 252, 29), // "on_select_color_swap_released"
QT_MOC_LITERAL(11, 282, 33), // "on_select_color_cpu_line_rele..."
QT_MOC_LITERAL(12, 316, 34), // "on_select_color_cpu_usage_rel..."
QT_MOC_LITERAL(13, 351, 29), // "on_restore_configure_released"
QT_MOC_LITERAL(14, 381, 26), // "on_radioButton_net_toggled"
QT_MOC_LITERAL(15, 408, 26), // "on_radioButton_cpu_toggled"
QT_MOC_LITERAL(16, 435, 38) // "on_system_monitor_path_editin..."

    },
    "ConfigureDialog\0on_refresh_interval_editingFinished\0"
    "\0on_showCpu_checkbox_toggled\0checked\0"
    "on_labelFont_size_editingFinished\0"
    "on_main_opacity_editingFinished\0"
    "on_select_color_main_released\0"
    "on_select_color_outer_border_released\0"
    "on_select_color_mem_released\0"
    "on_select_color_swap_released\0"
    "on_select_color_cpu_line_released\0"
    "on_select_color_cpu_usage_released\0"
    "on_restore_configure_released\0"
    "on_radioButton_net_toggled\0"
    "on_radioButton_cpu_toggled\0"
    "on_system_monitor_path_editingFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigureDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    1,   85,    2, 0x08 /* Private */,
       5,    0,   88,    2, 0x08 /* Private */,
       6,    0,   89,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    0,   91,    2, 0x08 /* Private */,
       9,    0,   92,    2, 0x08 /* Private */,
      10,    0,   93,    2, 0x08 /* Private */,
      11,    0,   94,    2, 0x08 /* Private */,
      12,    0,   95,    2, 0x08 /* Private */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    1,   97,    2, 0x08 /* Private */,
      15,    1,  100,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,

       0        // eod
};

void ConfigureDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfigureDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_refresh_interval_editingFinished(); break;
        case 1: _t->on_showCpu_checkbox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->on_labelFont_size_editingFinished(); break;
        case 3: _t->on_main_opacity_editingFinished(); break;
        case 4: _t->on_select_color_main_released(); break;
        case 5: _t->on_select_color_outer_border_released(); break;
        case 6: _t->on_select_color_mem_released(); break;
        case 7: _t->on_select_color_swap_released(); break;
        case 8: _t->on_select_color_cpu_line_released(); break;
        case 9: _t->on_select_color_cpu_usage_released(); break;
        case 10: _t->on_restore_configure_released(); break;
        case 11: _t->on_radioButton_net_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_radioButton_cpu_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_system_monitor_path_editingFinished(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ConfigureDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_ConfigureDialog.data,
    qt_meta_data_ConfigureDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ConfigureDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigureDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigureDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ConfigureDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
