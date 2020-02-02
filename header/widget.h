// GPL-3.0

#ifndef WIDGET_H
#define WIDGET_H

#include <unistd.h>

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QDesktopWidget>
#include <QGuiApplication>
#include <QListWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QActionGroup>
#include <QAction>
#include <QPainter>
#include <QPen>
#include <QLineF>
#include <QPainterPath>
#include <QPixmap>
#include <QRegion>
#include <QLineEdit>
#include <QLabel>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QStyleOption>
#include <QBrush>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QRect>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QProcess>
#include <QString>
#include <QStringList>
#include <QVector>
#include <QColorDialog>
#include <QIODevice>
#include <QDir>
#include <QStandardPaths>
#include <QFileInfo>
#include <QFile>
#include <QThread>

#include "define.h"
#include "get_sys_info.h"
#include "data_struct.h"
#include "configure_dialog.h"
#include "utils/threads.h"
#include "utils/dealtConfigFile.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr, int mode=EXEC_CONSTRUCTOR);
    ~Widget();

    // addon
    QLabel *cpuTemper_label;  // cpu温度 (cpu temper)
    QLabel *cpu_label;        // cpu标签 (cpu tag)
    QLabel *mem_label;        // mem标签 (mem tag)
    QLabel *mem_chart;        // mem图表 (mem chart)
    QLabel *netspeed_label;   // netspeed标签 (netspeed tag)
    QPushButton *mail_indic_button;     // mail指示器 (mail indicating)
    QPushButton *clock_indic_button;    // clock指示器 (mail indicating)
    QMenu *rightBtnMenu;                   // 右键菜单 (right menu)
    QActionGroup *rightBtnMenu_actonGroup; // 右键菜单 act


    // methods
    void deal_configFile(int mode);  // 检测和生成配置文件SET_MODE:use SET_MODE:set (test and create configure) at ~/.config/PopBall
    void read_configFile(int mode);  // 读配置文件
    void init();                     // 设置初始数据 (set initial data)
    void ending();                   // 析构
    void right_contextMenu();        // 右键菜单 (right context menu)
    void setting_panel();            // 设置面板
    void system_monitor();             // 系统监视器 (system monitor)
    void main_ui_style();            // 设置主要样式 (set main style)
    void timer_setInterval();        // 用于全局唯一计时器执行 (only timer func)
    void content();                  // 内容 (content func)
    void window_adsorb(bool isInit); // 窗口吸附位置
    GetSysInfo *Get_sys_info = new GetSysInfo;        // 获取内容方法 (get content func)

    // event cor
    bool mouseIsPress = false; // 鼠标是否按下 (mouse is press)
    QPoint curPoint;           // 当前坐标 (current coordinate)
    QTimer *global_timer;      // 全局唯一计时器对象 (only timer obj)

    // data
    double cpu_temperData;
    double cpu_data;
    double cpu_usageData;
    double mem_data;
    double swap_data;
    QVector<double> mem_data_history;      // data of mem
    QVector<double> swap_data_history;     // data of swap
    QVector<double> cpuUsage_data_history; // data of cpuUsage

    // configure data
    // cfg

    // effect
    QGraphicsDropShadowEffect *text_shadowEffect; // text shadow effect

    // 窗口模式外观 (MINI and NORMAL) (window look)
    int WINDOW_SIZE_LOOK     = NORMAL_MODE;  // default normal mode
    int WINDOW_SET_DIRECTION = NOTEDGE_MODE; // window on edge (left or right or other)

private:
    Threads *testThread;
    QThread *sub_testThread;

private slots:
    // event
    void mousePressEvent(QMouseEvent *event);   // mouse event
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);        // 绘制界面 (paint interface)
    void on_mail_indic_button_pressed();        // action button event
    void on_clock_indic_button_pressed();
};
#endif // WIDGET_H
