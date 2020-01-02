#ifndef GETSYSINFO_H
#define GETSYSINFO_H

#include <QString>
#include <sys/statfs.h>
#include <QProcess>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QRegExp>
#include <QList>

class GetSysInfo
{
public:
    GetSysInfo();

    QString getCpuTemperature();
    QString getCpuInfo();
    QString getMemInfo();
};

#endif // GETSYSINFO_H
