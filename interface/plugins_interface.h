#ifndef PLUGINS_INTERFACE_H
#define PLUGINS_INTERFACE_H

#include <QString>
#include <QObject>

class TestInterface {
public:
    virtual ~TestInterface() {}
    virtual QString print(const QString &) = 0;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(TestInterface, "Test.Plugin.TestInterface")
QT_END_NAMESPACE

#endif // PLUGINS_INTERFACE_H
