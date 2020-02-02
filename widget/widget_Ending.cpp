// GPL-3.0

#include "header/widget.h"

void Widget::ending() {
    delete rightBtnMenu;
    delete rightBtnMenu_actonGroup;
    delete cpuTemper_label;
    delete cpu_label;
    delete mem_label;
    delete text_shadowEffect;
    delete global_timer;
    delete Get_sys_info;
    delete mem_chart;
    delete netspeed_label;
    delete mail_indic_button;
    delete clock_indic_button;
    delete cfg;

    // test
    delete sub_testThread;
    delete testThread;

    qDebug() << "Widget析构 =>";
}
