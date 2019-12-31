#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(0.799);
    this->setFixedSize(100, 100);
    this->setStyleSheet("QWidget{border-top-left-radius:100px;border-top-right-radius:100px;}");

//    右键菜单
    rightBtnMenu = new QMenu(this);

//    QLabel
    cpu_label = new QLabel(this);

//    获取内容方法
    Get_sys_info = new GetSysInfo();
//    内容
//    content();

//    全局唯一计时器
    global_timer = new QTimer(this);

    connect(global_timer, &QTimer::timeout, this, &Widget::timer_setInterval);

//    开始计时
    global_timer->start(900);
}

Widget::~Widget()
{
    delete rightBtnMenu;
    delete cpu_label;
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
    painter.setBrush(QBrush(Qt::black));
    painter.setPen(Qt::transparent);
    painter.drawEllipse(0, 0, 100, 100);
    QWidget::paintEvent(event);
}

//内容
void Widget::content() {
//    获取cpu
    QString cpu_txt = Get_sys_info->getCpuInfo();
//    显示
    cpu_label->setText(cpu_txt);
//    样式
    cpu_label->setGeometry(0, 0, 100, 100);
    cpu_label->setStyleSheet("color:gray;");
}
