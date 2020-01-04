#include "getsysinfo.h"

GetSysInfo::GetSysInfo()
{
    qDebug() << "GetSysInfo 构造 =>";
}

GetSysInfo::~GetSysInfo() {
    delete file_proc_stat;
}

//cpu 信息
double GetSysInfo::getCpuInfo() {
    QString tmp_str = "";
    QProcess process;
    process.start("cat /proc/cpuinfo");
    process.waitForFinished();

    tmp_str = process.readAll().replace("\t", "");

    QStringList tmp_str_arr = tmp_str.split("\n");

    double num_of_cpu = 0.0;
    double max_freq = 0.0;
    double min_freq = 10000000000.0;
    double ave_freq = 0.0;
    double sum_freq = 0.0;

    for (int i=0; i<tmp_str_arr.size(); i++) {
        if (tmp_str_arr[i].contains("cpu MHz")) {

//           qDebug() << "getCpuInfo =>" << tmp_str_arr[i];
           double tmp_split = tmp_str_arr[i].split(":")[1].trimmed().toDouble();

           if (tmp_split > max_freq) { max_freq = tmp_split; }
           if (tmp_split < min_freq) { min_freq = tmp_split; }

           sum_freq += tmp_split;
           num_of_cpu += 1;
        }
    }

    ave_freq = sum_freq / num_of_cpu;
    max_freq = (max_freq/1000);

    process.close();
    return max_freq;
}

//cpu 使用率
QString GetSysInfo::getCpuUsageInfo() {
    QString tmp_result;
    // read file
    bool ok = file_proc_stat->open(QIODevice::ReadOnly);
    if (!ok) { return "NOK"; }
    while (!file_proc_stat->atEnd()) {
        QByteArray line = file_proc_stat->readAll();
        qDebug() << "line =>" << line;
    }
    file_proc_stat->close();

    return tmp_result;
}

double GetSysInfo::getMemInfo() {
    QProcess process;
    process.start("cat /proc/meminfo");
    process.waitForFinished();

//    QString tmp_str_total = process.readLine().replace("\t", "").replace("\n", "");
//    QString tmp_str_free  = process.readLine().replace("\t", "").replace("\n", "");
//    QStringList tmp_str_total_arr = tmp_str_total.split(":");
//    QStringList tmp_str_free_arr  = tmp_str_free.split(":");
//    unsigned long long total = tmp_str_total_arr[1].trimmed().split(" ")[0].trimmed().toULongLong();
//    unsigned long long free  = tmp_str_free_arr[1].trimmed().split(" ")[0].trimmed().toULongLong();
//    // 百分比 range
//    double range = (double)(total - free)/total;
    QString     data_string = process.readAll().replace("\t", "");
    QStringList data_list   = data_string.split("\n", QString::SkipEmptyParts);

    // store struct
    DataStruct::MemStruct memstruct;

    for (auto ite : data_list) {
        // every item for lines
        QStringList ite_list = ite.split(":", QString::SkipEmptyParts);
        if (ite_list[0] == "MemTotal")     { memstruct.MemTotal = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "MemFree")      { memstruct.MemFree = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "MemAvailable") { memstruct.MemAvailable = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "Cached")       { memstruct.Cached = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "Buffers")      { memstruct.Buffers = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
    }

    qDebug() << "getMemInfo =>"
             << memstruct.MemTotal
             << memstruct.MemFree
             << "sys free =>" << memstruct.MemFree
             << "free =>" << memstruct.Buffers + memstruct.MemFree + memstruct.Cached
             << "used =>" << memstruct.MemTotal - (memstruct.Buffers + memstruct.MemFree + memstruct.Cached)
             ;
    unsigned long long used = memstruct.MemTotal - (memstruct.Buffers + memstruct.MemFree + memstruct.Cached);

    double rate = (double)used / memstruct.MemTotal * 100;

    process.close();
    return rate;
}
