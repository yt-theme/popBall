#include "header/widget.h"

//内容
void Widget::content() {

    // ######## cpu #############
    // 获取cpu信息
    if (WINDOW_SIZE_LOOK==NORMAL_MODE && cfg->SHOW_CPU_LABEL==SHOW_MODE) {
        cpu_data = Get_sys_info->getCpuInfo();
        cpu_label->setText(QString::number(cpu_data, 'f', 2) + "GHz");
    }

    // ######## cpu usage #######
    // 获取cpu使用率
    cpu_usageData = Get_sys_info->getCpuUsageInfo();
    cpuUsage_data_history.push_back(cpu_usageData);
    if (cpuUsage_data_history.size() > cfg->CHART_ROW) { cpuUsage_data_history.pop_front(); }


    // ######## mem #############
    // 获取内存占用
    mem_data = Get_sys_info->getMemInfo();
    mem_data_history.push_back(mem_data);
    if (mem_data_history.size() > cfg->CHART_ROW) { mem_data_history.pop_front(); }

    update();
}
