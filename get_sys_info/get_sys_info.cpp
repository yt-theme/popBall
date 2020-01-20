// GPL-3.0

#include "header/get_sys_info.h"

GetSysInfo::GetSysInfo()
{
    qDebug() << "GetSysInfo 构造 =>";
}

GetSysInfo::~GetSysInfo() {

}

// cpu 温度
double GetSysInfo::getCpuTemperature() {
    QFile *process = new QFile;
    process->setFileName("/sys/class/thermal/thermal_zone0/temp");
    process->open(QIODevice::ReadOnly|QIODevice::Text);

    double temperature = process->readLine().toDouble();

    process->close();
    delete process;
    return temperature/1000;
}

//cpu 信息
double GetSysInfo::getCpuInfo() {
    QString tmp_str = "";
    QFile *process = new QFile;
    process->setFileName("/proc/cpuinfo");
    process->open(QIODevice::ReadOnly|QIODevice::Text);

    tmp_str = process->readAll().replace("\t", "");
    QStringList tmp_str_arr = tmp_str.split("\n");

    double num_of_cpu = 0.0;
    double max_freq = 0.0;
    double min_freq = 10000000000.0;
    double sum_freq = 0.0;

    for (int i=0; i<tmp_str_arr.size(); i++) {
        if (tmp_str_arr[i].contains("cpu MHz")) {
           double tmp_split = tmp_str_arr[i].split(":")[1].trimmed().toDouble();

           if (tmp_split > max_freq) { max_freq = tmp_split; }
           if (tmp_split < min_freq) { min_freq = tmp_split; }

           sum_freq += tmp_split;
           num_of_cpu += 1;
        }
    }
    
    max_freq = (max_freq/1000);

    process->close();
    delete process;
    return max_freq;
}

//cpu 使用率
double GetSysInfo::getCpuUsageInfo() {
    double cpu_usage = 0.0;
    QFile *process = new QFile;
    process->setFileName("/proc/stat");
    process->open(QIODevice::ReadOnly|QIODevice::Text);

    QString     data_string = process->readLine().replace("\t", "").replace("\n", "");
    QStringList data_list   = data_string.split(" ", QString::SkipEmptyParts);

    double total = data_list[1].toDouble() +
                   data_list[2].toDouble() +
                   data_list[3].toDouble() +
                   data_list[4].toDouble() +
                   data_list[5].toDouble() +
                   data_list[6].toDouble() +
                   data_list[7].toDouble() +
                   data_list[8].toDouble() +
                   data_list[9].toDouble() +
                   data_list[10].toDouble();

    double idle = data_list[4].toDouble();

    cpu_usage = static_cast<double>((total - cpuUsage_total_last) - (idle - cpuUsage_idle_last))/(total - cpuUsage_total_last) * 100;

    // last usage store
    cpuUsage_total_last = total;
    cpuUsage_idle_last = idle;

    process->close();
    delete process;
    return cpu_usage;
}

// memory_rate and swap_used
MemSwapRate GetSysInfo::getMemInfo() {
    MemSwapRate rateStruct;

    QFile *process = new QFile;
    process->setFileName("/proc/meminfo");
    process->open(QIODevice::ReadOnly|QIODevice::Text);

    QString     data_string = process->readAll().replace("\t", "");
    QStringList data_list   = data_string.split("\n", QString::SkipEmptyParts);

    for (auto ite : data_list) {
        // every item for lines
        QStringList ite_list = ite.split(":", QString::SkipEmptyParts);
        if (ite_list[0] == "MemTotal")     { memstruct.MemTotal = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "MemFree")      { memstruct.MemFree = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "MemAvailable") { memstruct.MemAvailable = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "Cached")       { memstruct.Cached = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "Buffers")      { memstruct.Buffers = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "SwapTotal")    { memstruct.SwapTotal = ite_list[1].trimmed().split(" ")[0].toULongLong(); }
        if (ite_list[0] == "SwapFree")     { memstruct.SwapFree = ite_list[1].trimmed().split(" ")[0].toULongLong(); }

    }

    unsigned long long mem_used  = memstruct.MemTotal - (memstruct.Buffers + memstruct.MemFree + memstruct.Cached);
    unsigned long long swap_used = memstruct.SwapTotal - memstruct.SwapFree;

    rateStruct.mem  = static_cast<double>(mem_used) / memstruct.MemTotal * 100;
    rateStruct.swap = static_cast<double>(swap_used) / memstruct.SwapTotal * 100;

    process->close();
    delete process;
    return rateStruct;
}

NetFlows GetSysInfo::getNetFlows() {
    NetFlows netFlows_current={0, 0};

    QFile *process = new QFile;
    process->setFileName("/proc/net/dev");
    process->open(QIODevice::ReadOnly|QIODevice::Text);

    QString data_string = process->readAll().replace("\t", "");
    QStringList data_list = data_string.split("\n", QString::SkipEmptyParts);

    data_list.pop_front();
    data_list.pop_front();

    for (auto item: data_list) {
        QStringList tmp = item.split(" ", QString::SkipEmptyParts);
        netFlows_current.receive  += tmp[1].toDouble();
        netFlows_current.transmit += tmp[9].toDouble();
    }

    // compare with last
    NetFlows result;
    result.receive  = netFlows_current.receive - netFlows_last.receive;
    result.transmit = netFlows_current.transmit - netFlows_last.transmit;

    // store current to last;
    netFlows_last.receive  = netFlows_current.receive;
    netFlows_last.transmit = netFlows_current.transmit;

    process->close();
    delete process;
    return result;
}
