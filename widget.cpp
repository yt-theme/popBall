// GPL-3.0

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // QVector init
    for (auto i=0; i<CHART_ROW; i++) {
        mem_data_history.push_back(0);
        cpuUsage_data_history.push_back(0);
    }

    // main styleSheet
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(MAIN_OPACITY);
    this->setWindowFlags(windowFlags()|Qt::BypassWindowManagerHint);
    this->setFixedSize(WIDTH, HEIGHT);
    this->setStyleSheet("QWidget{border-top-left-radius:100px;border-top-right-radius:100px;}");

    rightBtnMenu = new QMenu(this);     // 右键菜单
    cpu_label = new QLabel(this);       // cpu频率 QLabel
    cpuUsage_label = new QLabel(this);  // cpu使用率 QLabel
    mem_label = new QLabel(this);       // mem使用
    mem_chart = new QLabel(this);       // mem图表

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
    delete mem_chart;
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
    QPainterPath path;
    QPainterPath path2;

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColor::fromRgb( MAIN_COLOR[0], MAIN_COLOR[1], MAIN_COLOR[2] )));

    // main circle
    painter.setPen(Qt::transparent);
    painter.drawEllipse(MAIN_CIRCLE_X, MAIN_CIRCLE_Y, MAIN_CIRCLE_W, MAIN_CIRCLE_H);

    // outer circle
    QPen outercircle_pen(QColor::fromRgb( OUTER_BORDER_COLOR[0], OUTER_BORDER_COLOR[1], OUTER_BORDER_COLOR[2] ), BORDER_WIDTH, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
    painter.setPen(outercircle_pen);
    painter.drawEllipse(OUTER_CIRCLE_X, OUTER_CIRCLE_Y, OUTER_CIRCLE_W, OUTER_CIRCLE_H);

    // clip
    // 裁剪
    QPainterPath clip_path;
    clip_path.moveTo(OUTER_CIRCLE_X, OUTER_CIRCLE_Y);
    clip_path.arcTo(OUTER_CIRCLE_X+BORDER_WIDTH, OUTER_CIRCLE_Y+BORDER_WIDTH, OUTER_CIRCLE_W-(BORDER_WIDTH*2), OUTER_CIRCLE_H-(BORDER_WIDTH*2), 0, 360);
    painter.setClipPath(clip_path);

    // mem chart
    QPen mem_pen;
    mem_pen.setColor(QColor::fromRgb(225, 255, 187));
    mem_pen.setStyle(Qt::SolidLine);
    mem_pen.setWidthF(1);
    painter.setPen(mem_pen);
//    painter.setViewport(OUTER_CIRCLE_X, HEIGHT/2 - OUTER_CIRCLE_Y, WIDTH, HEIGHT/2);
    path.moveTo(OUTER_CIRCLE_X, HEIGHT);
    for (auto i=0; i<mem_data_history.size(); i++) {
        path.lineTo(i*WIDTH/CHART_ROW, 100 - mem_data_history[i]);
    }
    path.lineTo(WIDTH, 100 - mem_data_history[ mem_data_history.size()-1 ]);
    path.lineTo(WIDTH, HEIGHT);
    painter.fillPath(path, QColor::fromRgba(qRgba(MEM_CHART_COLOR[0],MEM_CHART_COLOR[1],MEM_CHART_COLOR[2],MEM_CHART_COLOR[3])));

    // cpuUsage chart
    QLineF cpuUsage_pen[cpuUsage_data_history.size()];
    QPointF cpuUsage_prevPoint[1] = { QPointF(OUTER_CIRCLE_X, HEIGHT) }; // prev
    for (int i=0; i<cpuUsage_data_history.size(); i++) {
        cpuUsage_pen[i].setPoints(
                    cpuUsage_prevPoint[0],
                    QPointF(i*WIDTH/CHART_ROW, 100 - cpuUsage_data_history[i])
                );
        cpuUsage_prevPoint[0] = { QPointF(i*WIDTH/CHART_ROW, 100 - cpuUsage_data_history[i]) };
        // qDebug() << cpuUsage_prevPoint[0] << i*WIDTH/CHART_ROW << 100 - cpuUsage_data_history[i];
    }
    painter.drawLines(cpuUsage_pen, cpuUsage_data_history.size());
}

//内容
void Widget::content() {

    // ######## cpu #############
    // 获取cpu信息
    cpu_data = Get_sys_info->getCpuInfo();
    // set txt
    cpu_label->setText(QString::number(cpu_data, 'f', 2) + "GHz");
    // style
    cpu_label->setAlignment(Qt::AlignHCenter);
    cpu_label->setGeometry(3, 3, 94, 94);
    cpu_label->setFont(QFont("Microsoft YaHei", 9, 25));
    cpu_label->setStyleSheet("color:#eeeeee;");


    // ######## cpu usage #######
    // 获取cpu使用率
    cpu_usageData = Get_sys_info->getCpuUsageInfo();
    cpuUsage_data_history.push_back(cpu_usageData);
    if (cpuUsage_data_history.size() > CHART_ROW) { cpuUsage_data_history.pop_front(); }
    // set txt
    // cpuUsage_label->setText(QString::number(cpu_usageData, 'f', 2));


    // ######## mem #############
    // 获取内存占用
    mem_data = Get_sys_info->getMemInfo();
    mem_data_history.push_back(mem_data);
    if (mem_data_history.size() > CHART_ROW) { mem_data_history.pop_front(); }
    // set txt
    mem_label->setText("mem " + QString::number(mem_data, 'f', 0) + '%');
    // style
    mem_label->setAlignment(Qt::AlignHCenter);
    mem_label->setGeometry(3, 47, 94, 47);
    mem_label->setFont(QFont("Microsoft YaHei", 8, 45));
    mem_label->setStyleSheet("color:#eeeeee;");


    // ######## mem chart #######
    mem_chart->setGeometry(3, 47, 94, 47);
    // 绘制

    update();
}
