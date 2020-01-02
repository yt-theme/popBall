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

    double cpu_average;
    double num_of_cpu = 0.0;
    for (int i=0; i<tmp_str_arr.size(); i++) {

        if (tmp_str_arr[i].contains("cpu MHz")) {
           qDebug() << "getCpuInfo =>" << tmp_str_arr[i];
           double tmp_split = tmp_str_arr[i].split(":")[1].trimmed().toDouble();
           cpu_average += tmp_split;
           num_of_cpu += 1;
        }
    }


    process.close();
    return QString::number(cpu_average / num_of_cpu).split(".")[0];
}

QString GetSysInfo::getMemInfo() {
    QProcess process;
    process.start("cat /proc/meminfo");
    process.waitForStarted();
    QString tmp_str = process.readLine();
    qDebug() << "getMemInfo =>" << tmp_str;
    return tmp_str;
}
