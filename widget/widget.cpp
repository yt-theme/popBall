// GPL-3.0

#include "header/widget.h"

Widget::Widget(QWidget *parent, int mode)
    : QWidget(parent)
{
    if (mode == EXEC_CONSTRUCTOR) {
        deal_configFile(USE_MODE); // 处理配置文件 (func at widget_ConfigFile.cpp)
        init();                    // 设置初始数据 (func at widget_Initial.cpp)
        right_contextMenu();       // 右键菜单 (func at widget_RightContextMenu)
        main_ui_style();           // 设置 main ui (func at widget_UIAndPaintEvent.cpp)

        window_adsorb(true);       // 窗口位置与形态 (func at widget_WindowPositionStyle.cpp)
        timer_setInterval();       // 内容 第一次获取
        global_timer = new QTimer(this); // 全局唯一计时器
        global_timer->start(cfg->REFRESH_INTERVAL); // 开始计时

        connect(global_timer, &QTimer::timeout, this, &Widget::timer_setInterval); // 计时器事件
        // action button event
        connect(mail_indic_button, &QPushButton::pressed, this, &Widget::on_mail_indic_button_pressed);
        connect(clock_indic_button, &QPushButton::pressed, this, &Widget::on_clock_indic_button_pressed);
        // mail thread event
    }
}

Widget::~Widget()
{
    ending(); // 析构 (func at widget_Ending.cpp)
}

void Widget::timer_setInterval() {
    content();
}
