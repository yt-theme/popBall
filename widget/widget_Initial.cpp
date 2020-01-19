// GPL-3.0

#include "header/widget.h"

void Widget::init() {

    // addon
    rightBtnMenu            = new QMenu(this);          // 右键菜单
    rightBtnMenu_actonGroup = new QActionGroup(this);   // 右键菜单 act
    cpuTemper_label         = new QLabel(this);         // cpu温度 QLabel
    cpu_label               = new QLabel(this);         // cpu频率 QLabel
    mem_label               = new QLabel(this);         // mem使用
    mem_chart               = new QLabel(this);         // mem图表
    mail_indic_button       = new QPushButton(this);    // mail指示器
    clock_indic_button      = new QPushButton(this);    // clock指示器

    // class
    Get_sys_info            = new GetSysInfo(); // 获取内容数据类

    // QVector init
    for (auto i=0; i<cfg->CHART_ROW; i++) {
        mem_data_history.push_back(0);
        swap_data_history.push_back(0);
        cpuUsage_data_history.push_back(0);
    }

    // thread
    sub_testThread = new QThread(this);
    testThread     = new Threads();
}
