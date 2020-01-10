#include "widget.h"

void Widget::init() {

    // addon
    rightBtnMenu            = new QMenu(this);     // 右键菜单
    rightBtnMenu_actonGroup = new QActionGroup(this); // 右键菜单 act
    cpu_label               = new QLabel(this);    // cpu频率 QLabel
    mem_label               = new QLabel(this);    // mem使用
    mem_chart               = new QLabel(this);    // mem图表
    mail_indic_label        = new QLabel(this);    // mail指示器
    // class
    Get_sys_info            = new GetSysInfo(); // 获取内容数据类



    // QVector init
    for (auto i=0; i<cfg.CHART_ROW; i++) {
        mem_data_history.push_back(0);
        cpuUsage_data_history.push_back(0);
    }



    // right contextMenu
    // configure
    QAction *menu_action_configure = new QAction("configure", this);
    rightBtnMenu->addAction(menu_action_configure);
    // exit
    QAction *menu_action_exit = new QAction("exit", this);
    connect(menu_action_exit, &QAction::triggered, [=](){ qDebug() << "exit =>"; exit(0); });
    rightBtnMenu->addAction(menu_action_exit);
}
