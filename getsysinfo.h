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

#include "datastruct.h"

class GetSysInfo : public DataStruct
{
public:
    GetSysInfo();

    QString getCpuTemperature();
    QString getCpuInfo();
    QString getMemInfo();

    struct CpuStruct cpu_struct;
};

#endif // GETSYSINFO_H
