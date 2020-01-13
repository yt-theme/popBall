#ifndef GETSYSINFO_H
#define GETSYSINFO_H

// GPL-3.0

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

    QString getCpuTemperature();
    double getCpuInfo();
    double getCpuUsageInfo();
    double getMemInfo();   

private:
    MemStruct memstruct; // store struct
    unsigned long long mem_used;     // mem used
    double cpu_usage;                // cpu usage
    double cpuUsage_total_last=0.0;  // 上一次 cpu total
    double cpuUsage_idle_last=0.0;   // 上一次 cpu idle

    QFile *file_proc_stat = new QFile("/proc/stat"); // open /proc/stat
};

#endif // GETSYSINFO_H
