/****************************************************************************
** Meta object code from reading C++ file 'serverconnection.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../serverconnection.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN16ServerConnectionE_t {};
} // unnamed namespace

template <> constexpr inline auto ServerConnection::qt_create_metaobjectdata<qt_meta_tag_ZN16ServerConnectionE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ServerConnection",
        "loginResult",
        "",
        "success",
        "message",
        "registerResult",
        "messageReceived",
        "QJsonObject",
        "messagesReceived",
        "QJsonArray",
        "messages",
        "friendRequestResult",
        "friendRequestResponseResult",
        "friendRequestsReceived",
        "requests",
        "friendsReceived",
        "friends",
        "onConnected",
        "onTextMessageReceived"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'loginResult'
        QtMocHelpers::SignalData<void(bool, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'registerResult'
        QtMocHelpers::SignalData<void(bool, const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'messageReceived'
        QtMocHelpers::SignalData<void(const QJsonObject &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 4 },
        }}),
        // Signal 'messagesReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 10 },
        }}),
        // Signal 'friendRequestResult'
        QtMocHelpers::SignalData<void(bool, const QString &)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'friendRequestResponseResult'
        QtMocHelpers::SignalData<void(bool, const QString &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 3 }, { QMetaType::QString, 4 },
        }}),
        // Signal 'friendRequestsReceived'
        QtMocHelpers::SignalData<void(const QJsonArray &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 9, 14 },
        }}),
        // Signal 'friendsReceived'
        QtMocHelpers::SignalData<void(QStringList)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 16 },
        }}),
        // Slot 'onConnected'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onTextMessageReceived'
        QtMocHelpers::SlotData<void(const QString &)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ServerConnection, qt_meta_tag_ZN16ServerConnectionE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ServerConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ServerConnectionE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ServerConnectionE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16ServerConnectionE_t>.metaTypes,
    nullptr
} };

void ServerConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ServerConnection *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->loginResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->registerResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->messageReceived((*reinterpret_cast<std::add_pointer_t<QJsonObject>>(_a[1]))); break;
        case 3: _t->messagesReceived((*reinterpret_cast<std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 4: _t->friendRequestResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->friendRequestResponseResult((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 6: _t->friendRequestsReceived((*reinterpret_cast<std::add_pointer_t<QJsonArray>>(_a[1]))); break;
        case 7: _t->friendsReceived((*reinterpret_cast<std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 8: _t->onConnected(); break;
        case 9: _t->onTextMessageReceived((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ServerConnection::*)(bool , const QString & )>(_a, &ServerConnection::loginResult, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerConnection::*)(bool , const QString & )>(_a, &ServerConnection::registerResult, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerConnection::*)(const QJsonObject & )>(_a, &ServerConnection::messageReceived, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerConnection::*)(const QJsonArray & )>(_a, &ServerConnection::messagesReceived, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerConnection::*)(bool , const QString & )>(_a, &ServerConnection::friendRequestResult, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerConnection::*)(bool , const QString & )>(_a, &ServerConnection::friendRequestResponseResult, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerConnection::*)(const QJsonArray & )>(_a, &ServerConnection::friendRequestsReceived, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (ServerConnection::*)(QStringList )>(_a, &ServerConnection::friendsReceived, 7))
            return;
    }
}

const QMetaObject *ServerConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16ServerConnectionE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ServerConnection::loginResult(bool _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void ServerConnection::registerResult(bool _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void ServerConnection::messageReceived(const QJsonObject & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void ServerConnection::messagesReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void ServerConnection::friendRequestResult(bool _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void ServerConnection::friendRequestResponseResult(bool _t1, const QString & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1, _t2);
}

// SIGNAL 6
void ServerConnection::friendRequestsReceived(const QJsonArray & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1);
}

// SIGNAL 7
void ServerConnection::friendsReceived(QStringList _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 7, nullptr, _t1);
}
QT_WARNING_POP
