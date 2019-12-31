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

//    获取内容方法
    Get_sys_info = new GetSysInfo();
//    内容
    content();

}

Widget::~Widget()
{
    delete rightBtnMenu;
    delete cpu_label;
    delete Get_sys_info;
}


void Widget::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
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
//    QLabel
    cpu_label = new QLabel(this);
    QString cpu_txt = Get_sys_info->getCpuInfo();
    cpu_label->setText(cpu_txt);
    cpu_label->setGeometry(0, 0, 100, 100);
    cpu_label->setStyleSheet("color:gray;");
}
