#include "getsysinfo.h"

GetSysInfo::GetSysInfo()
{

}

QString GetSysInfo::getCpuInfo() {
    QProcess process;
    process.start("cat /proc/stat");
    process.waitForFinished();
    QString tmp_str = process.readLine();
    tmp_str.replace("\n", " ");
    return tmp_str;
}
