// GPL-3.0

#ifndef GETSYSINFO_H
#define GETSYSINFO_H

#include <QIODevice>
#include <QString>
#include <sys/statfs.h>
#include <QProcess>
#include <QObject>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QRegExp>
#include <QList>

#include "data_struct.h"

class GetSysInfo
{
public:
    GetSysInfo();
    ~GetSysInfo();

    double getCpuTemperature();
    double getCpuInfo();
    double getCpuUsageInfo();
    MemSwapRate getMemInfo();
    NetFlows getNetFlows();

private:
    MemStruct memstruct;                // store struct for mem
    double    cpuUsage_total_last=0.0;  // 上一次 cpu total
    double    cpuUsage_idle_last=0.0;   // 上一次 cpu idle
    NetFlows  netFlows_last={0,0};      // 上一次 net 收发总量
};

#endif // GETSYSINFO_H
