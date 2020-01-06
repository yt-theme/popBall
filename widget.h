// GPL-3.0

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QMenu>
#include <QPainter>
#include <QPen>
#include <QLineF>
#include <QPainterPath>
#include <QPixmap>
#include <QRegion>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QStyleOption>
#include <QBrush>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QVector>

#include "getsysinfo.h"
#include "datastruct.h"

class Widget : public QWidget, public GetSysInfo
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


    bool mouseIsPress = false; // 鼠标是否按下

    QPoint curPoint; // 当前坐标

    void paintEvent(QPaintEvent *event); // 绘制界面

    QMenu *rightBtnMenu; // 右键菜单

    // 内容
    void content();
    QLabel *cpu_label;      // cpu标签
    QLabel *cpuUsage_label; // cpu usage
    QLabel *mem_label;      // mem标签
    QLabel *mem_chart;      // mem图表

    // 获取内容方法
    GetSysInfo *Get_sys_info;

    // 全局唯一计时器对象
    QTimer *global_timer;
private:

    double cpu_data;
    double cpu_usageData;
    double mem_data;
    QVector<double> mem_data_history; // data of mem
    QVector<double> cpuUsage_data_history; // data of cpuUsage

    QGraphicsDropShadowEffect *text_shadowEffect; // text shadow effect


    // 图表最大列数
    int CHART_ROW = 41;
    // timer
    int TIMER_INTERVAL = 1000;
    // size
    int WIDTH          = 100; // window width;
    int HEIGHT         = 100; // wineow height;
    int BORDER_WIDTH   = 3;   // border width
    int OUTER_CIRCLE_X = 3;   // outer circle
    int OUTER_CIRCLE_Y = 3;
    int OUTER_CIRCLE_W = 94;
    int OUTER_CIRCLE_H = 94;
    int MAIN_CIRCLE_X  = 0;   // main circle
    int MAIN_CIRCLE_Y  = 0;
    int MAIN_CIRCLE_W  = 100;
    int MAIN_CIRCLE_H  = 100;
    // color
    double MAIN_OPACITY         = 0.89;
    int MAIN_COLOR[3]           = {35, 38, 41};
    int OUTER_BORDER_COLOR[3]   = {249, 249, 249};
    int MEM_CHART_COLOR[4]      = {19, 187, 177, 191};
    int CPUUSAGE_CHART_COLOR[4] = {17, 109, 200, 191};

private slots:
//    全局唯一计时器
    void timer_setInterval();

};
#endif // WIDGET_H
