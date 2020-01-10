    // GPL-3.0

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    deal_configFile(USE_MODE); // 处理配置文件 (func at widget_ConfigFile.cpp)
    init();                    // 设置初始数据 (func at widget_Initial.cpp)
    right_contextMenu();       // 右键菜单 (func at widget_RightContextMenu)
    main_ui_style();           // 设置 main ui (func at widget_UIAndPaintEvent.cpp)

    window_adsorb(true);       // 窗口位置与形态 (func at widget_WindowPositionStyle.cpp)
    timer_setInterval(); // 内容 第一次获取
    global_timer = new QTimer(this); // 全局唯一计时器
    connect(global_timer, &QTimer::timeout, this, &Widget::timer_setInterval); // 计时器事件
    global_timer->start(cfg.REFRESH_INTERVAL); // 开始计时
}

Widget::~Widget()
{
    ending(); // 析构 (func at widget_Ending.cpp)
}

void Widget::timer_setInterval() {
    content();
}

//内容
void Widget::content() {

    // ######## cpu #############
    // 获取cpu信息
    if (WINDOW_SIZE_LOOK==NORMAL_MODE && cfg.SHOW_CPU_LABEL==SHOW_MODE) {
        cpu_data = Get_sys_info->getCpuInfo();
        cpu_label->setText(QString::number(cpu_data, 'f', 2) + "GHz");
    }

    // ######## cpu usage #######
    // 获取cpu使用率
    cpu_usageData = Get_sys_info->getCpuUsageInfo();
    cpuUsage_data_history.push_back(cpu_usageData);
    if (cpuUsage_data_history.size() > cfg.CHART_ROW) { cpuUsage_data_history.pop_front(); }


    // ######## mem #############
    // 获取内存占用
    mem_data = Get_sys_info->getMemInfo();
    mem_data_history.push_back(mem_data);
    if (mem_data_history.size() > cfg.CHART_ROW) { mem_data_history.pop_front(); }

    update();
}
