#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(MAIN_OPACITY);
    this->setFixedSize(WIDTH, HEIGHT);
    this->setStyleSheet("QWidget{border-top-left-radius:100px;border-top-right-radius:100px;}");

    rightBtnMenu = new QMenu(this);     // 右键菜单
    cpu_label = new QLabel(this);       // cpu频率 QLabel
    cpuUsage_label = new QLabel(this);  // cpu使用率 QLabel
    mem_label = new QLabel(this);       // mem使用

    Get_sys_info = new GetSysInfo(); // 获取内容数据类

    content();  // 内容 第一次获取
    global_timer = new QTimer(this); // 全局唯一计时器
    connect(global_timer, &QTimer::timeout, this, &Widget::timer_setInterval); // 计时器事件
    global_timer->start(TIMER_INTERVAL); // 开始计时
}

Widget::~Widget()
{
    delete rightBtnMenu;
    delete cpu_label;
    delete cpuUsage_label;
    delete mem_label;
    delete Get_sys_info;
}

void Widget::timer_setInterval() {
    content();
}


void Widget::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event)
    mouseIsPress = false;
}

void Widget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        mouseIsPress = true;
        curPoint = event->pos();
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
    if (mouseIsPress) {
        move(event->pos() - curPoint + pos());
    }
}

void Widget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor::fromRgb(
                                MAIN_COLOR[0], MAIN_COLOR[1], MAIN_COLOR[2]
                            )));

    // main circle
    painter.setPen(Qt::transparent);
    painter.drawEllipse(MAIN_CIRCLE_X, MAIN_CIRCLE_Y, MAIN_CIRCLE_W, MAIN_CIRCLE_H);
    // outer circle
    QPen outercircle_pen(QColor::fromRgb(
                             OUTER_BORDER_COLOR[0], OUTER_BORDER_COLOR[1], OUTER_BORDER_COLOR[2]
                        ), BORDER_WIDTH, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    painter.setPen(outercircle_pen);
    painter.drawEllipse(OUTER_CIRCLE_X, OUTER_CIRCLE_Y, OUTER_CIRCLE_W, OUTER_CIRCLE_H);
    QWidget::paintEvent(event);
}

//内容
void Widget::content() {

    // ######## cpu #############
    // 获取cpu信息
    QString cpu_txt = Get_sys_info->getCpuInfo();
    // set txt
    cpu_label->setText(cpu_txt);
    // style
    cpu_label->setAlignment(Qt::AlignHCenter);
    cpu_label->setGeometry(3, 3, 94, 94);
    cpu_label->setStyleSheet("color:#eeeeee;");

    // ######## cpu usage #######
    // 获取cpu使用率
    QString cpuUsage_txt = Get_sys_info->getCpuUsageInfo();
    // set txt
    cpuUsage_label->setText(cpuUsage_txt);

    // ######## mem #############
    // 获取内存占用
    QString mem_txt = Get_sys_info->getMemInfo();
    // set txt
    mem_label->setText(mem_txt);

}
