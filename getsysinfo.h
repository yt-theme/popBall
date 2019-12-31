#ifndef GETSYSINFO_H
#define GETSYSINFO_H

#include <QString>
#include <sys/statfs.h>
#include <QProcess>
#include <QObject>

class GetSysInfo
{
public:
    GetSysInfo();

    QString getCpuInfo();
};

#endif // GETSYSINFO_H
