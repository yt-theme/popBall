#include "getsysinfo.h"

GetSysInfo::GetSysInfo()
{
    qDebug() << "GetSysInfo 构造 =>";
}

GetSysInfo::~GetSysInfo() {
    delete file_proc_stat;
}

//cpu 信息
QString GetSysInfo::getCpuInfo() {
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

    cpu_struct.max_freq = max_freq;
    cpu_struct.min_freq = min_freq;
    cpu_struct.ave_freq = ave_freq;

    max_freq = (max_freq/1000);

    process.close();
    return QString::number(max_freq, 'f', 2) + "GHz";
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

QString GetSysInfo::getMemInfo() {
    QProcess process;
    process.start("cat /proc/meminfo");
    process.waitForFinished();

    QString tmp_str_total = process.readLine().replace("\t", "").replace("\n", "");
    QString tmp_str_free  = process.readLine().replace("\t", "").replace("\n", "");

    QStringList tmp_str_total_arr = tmp_str_total.split(":");
    QStringList tmp_str_free_arr  = tmp_str_free.split(":");

    long long total = tmp_str_total_arr[1].trimmed().split(" ")[0].trimmed().toLongLong();
    long long free  = tmp_str_free_arr[1].trimmed().split(" ")[0].trimmed().toLongLong();

    // 百分比 range
    double range = (total - free);

    qDebug() << "getMemInfo =>" << total << "," << free << "," << range;

    process.close();
    return tmp_str_total;
}
