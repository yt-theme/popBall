// GPL-3.0

#include "header/widget.h"

//内容
void Widget::content() {

    // ######## cpu temper ######
    if (WINDOW_SIZE_LOOK==NORMAL_MODE && cfg->SHOW_CPU_LABEL==SHOW_MODE) {
        cpu_temperData = Get_sys_info->getCpuTemperature();
        cpuTemper_label->setText(QString::number(cpu_temperData, 'f', 0) + "℃");
    } else {
        cpuTemper_label->clear();
    }

    // ######## cpu #############
    // 获取cpu信息
    if (WINDOW_SIZE_LOOK==NORMAL_MODE && cfg->SHOW_CPU_LABEL==SHOW_MODE) {
        cpu_data = Get_sys_info->getCpuInfo();
        cpu_label->setText(QString::number(cpu_data, 'f', 2) + "GHz");
    } else {
        cpu_label->clear();
    }

    // ######## cpu usage #######
    // 获取cpu使用率
    cpu_usageData = Get_sys_info->getCpuUsageInfo();
    cpuUsage_data_history.push_back(cpu_usageData);
    if (cpuUsage_data_history.size() > cfg->CHART_ROW) { cpuUsage_data_history.pop_front(); }


    // ######## mem swap ########
    MemSwapRate memswaprate = Get_sys_info->getMemInfo();
    // 获取内存占用
    mem_data = memswaprate.mem;
    mem_data_history.push_back(mem_data);
    if (mem_data_history.size() > cfg->CHART_ROW) { mem_data_history.pop_front(); }
    // 获取交换占用
    swap_data = memswaprate.swap == 0 ? 0.01 : memswaprate.swap;
    swap_data_history.push_back(swap_data);
    if (swap_data_history.size() > cfg->CHART_ROW) { swap_data_history.pop_front(); }


    // ####### net speed ########
    NetFlows netflows = Get_sys_info->getNetFlows();
    double receive_speed  = netflows.receive  / cfg->REFRESH_INTERVAL / 1024;  // receive
    double transmit_speed = netflows.transmit / cfg->REFRESH_INTERVAL / 1024; // transmit
    netspeed_label->setText("↓ " +QString::number(receive_speed, 'f', 2) + " MiB/s\n↑ " + QString::number(transmit_speed, 'f', 2) + " MiB/s");

    update();
}
