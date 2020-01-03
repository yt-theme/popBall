#include "getsysinfo.h"

GetSysInfo::GetSysInfo()
{

}


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

           qDebug() << "getCpuInfo =>" << tmp_str_arr[i];
           double tmp_split = tmp_str_arr[i].split(":")[1].trimmed().toDouble();

//           get max
           if (tmp_split > max_freq) {
               max_freq = tmp_split;
           }
//           get min
           if (tmp_split < min_freq) {
               min_freq = tmp_split;
           }

//           sum freq
           sum_freq += tmp_split;

//           num cpu
           num_of_cpu += 1;
        }
    }

//    get average
    ave_freq = sum_freq / num_of_cpu;

    cpu_struct.max_freq = max_freq;
    cpu_struct.min_freq = min_freq;
    cpu_struct.ave_freq = ave_freq;

//    mhz -> ghz
    max_freq = (max_freq/1000);

    process.close();
    return QString::number(max_freq, 'f', 2);
}

QString GetSysInfo::getMemInfo() {
    QProcess process;
    process.start("cat /proc/meminfo");
    process.waitForStarted();
    QString tmp_str = process.readLine();
    qDebug() << "getMemInfo =>" << tmp_str;
    return tmp_str;
}
