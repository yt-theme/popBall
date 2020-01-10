#include "widget.h"

void Widget::set_init_data() {
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
