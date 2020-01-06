#ifndef GETSYSINFO_H
#define GETSYSINFO_H

// GPL-3.0

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

#include "datastruct.h"

class GetSysInfo : public DataStruct
{
public:
    GetSysInfo();
    ~GetSysInfo();

    QString getCpuTemperature();
    double getCpuInfo();
    double getCpuUsageInfo();
    double getMemInfo();   

private:
    QProcess process;                // Qprocess
    DataStruct::MemStruct memstruct; // store struct
    unsigned long long mem_used;     // mem used
    double cpu_usage;                // cpu usage
    double cpuUsage_total_last=0.0;  // 上一次 cpu total
    double cpuUsage_idle_last=0.0;   // 上一次 cpu idle

    QFile *file_proc_stat = new QFile("/proc/stat"); // open /proc/stat
};

#endif // GETSYSINFO_H
