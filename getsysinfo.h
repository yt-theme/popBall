#ifndef GETSYSINFO_H
#define GETSYSINFO_H

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
    QString getCpuInfo();
    QString getCpuUsageInfo();
    QString getMemInfo();

    QString cpuUsage_last = ""; // 上一次 cpu 使用率数据

    struct CpuStruct cpu_struct;

private:
    QFile *file_proc_stat = new QFile("/proc/stat"); // open /proc/stat


};

#endif // GETSYSINFO_H
