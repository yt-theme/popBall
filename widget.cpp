    // GPL-3.0

#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // addon
    rightBtnMenu = new QMenu(this);     // 右键菜单
    cpu_label    = new QLabel(this);    // cpu频率 QLabel
    mem_label    = new QLabel(this);    // mem使用
    mem_chart    = new QLabel(this);    // mem图表
    mail_indic_label = new QLabel(this);    // main指示器

    deal_configFile(1); // 处理配置文件
    set_init_data();    // 设置初始数据
    set_ui_style();     // 设置 main ui

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
    delete mem_label;
    delete text_shadowEffect;
    delete global_timer;
    delete Get_sys_info;
    delete mem_chart;
    delete mail_indic_label;
}

void Widget::deal_configFile(int mode) { // mode=1:use conf, mode=2: set conf
    QDir dot_config_dir;
    QFileInfo config_file_path;
    QFile *config_file = new QFile; // 配置文件对象
    config_file->setFileName(CONF_FILE_NAME);

    // 获取当前linux用户绝对路径 (current absolute path of linux)
    QString cur_user_fullpath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    // 检测.config目录是否存在 (check .config is exist)
    dot_config_dir.setPath(cur_user_fullpath + "/.config");
    // 不存在则创建 (not exist then create it)
    if (!dot_config_dir.exists()) {
        bool isOk = dot_config_dir.mkdir(cur_user_fullpath + "/.config");
        if (!isOk) { qDebug() << "mkdir .config FAIL =>" << isOk; throw "mkdir .config FAIL"; }
    }

    // 检测 CONF_FILE_NAME 是否存在 不存在则创建
    config_file_path.setFile(cur_user_fullpath + "/.config/" + CONF_FILE_NAME);
    // 不存在则创建 (not exist them create it)
    if (!config_file_path.exists()) {
        // dot_config_dir.cd(cur_user_fullpath + "/.config");
        config_file->setFileName(cur_user_fullpath + "/.config/" + CONF_FILE_NAME);
        config_file->open(QIODevice::WriteOnly);
        // 添加默认配置
        config_file->write(CONF_FILE_DEFAULT_CONTENT);
        config_file->close();
    }

    // 读配置文件 (use conf)
    config_file->setFileName(cur_user_fullpath + "/.config/" + CONF_FILE_NAME);
    bool openOk = config_file->open(QIODevice::ReadWrite|QIODevice::Text);
    if (!openOk) { qDebug() << "read conf file err =>"; throw "read conf file err"; }
    QString conf_file_content = config_file->readAll();
    // 以\n划分配置项
    QStringList config_items = conf_file_content.split("\n", QString::SkipEmptyParts);
    qDebug() << "config_items =>" << config_items;
    // 每个配置项用=划分键和值 (= split key and v)
    QString tmp_config_content; // 临时配置文件内容
    for (int i=0; i<config_items.size(); i++) {
        QStringList item = config_items[i].split("=", QString::SkipEmptyParts);
        // POSITOIN
        if(item[0].trimmed() == "POSITION") {
            // mode
            switch (mode) {
                case 1: // use conf
                    configItem.POSITION_X = item[1].trimmed().split(" ")[0].toInt();
                    configItem.POSITION_Y = item[1].trimmed().split(" ")[1].toInt();
                    POSITION_X = configItem.POSITION_X;
                    POSITION_Y = configItem.POSITION_Y;
                    // 设置窗口位置
                    this->setGeometry(POSITION_X, POSITION_Y, OUTER_CIRCLE_W, OUTER_CIRCLE_H);
                break;
                case 2: // set conf
                    config_items[i] = "POSITION=" + QString::number(POSITION_X) + " " + QString::number(POSITION_Y);
                    tmp_config_content = config_items.join("\n");
                break;
                default: break;
            }

        }
    }
    config_file->close();

    // 写入配置文件
    if (mode==2 && tmp_config_content.size()>0) {
        config_file->open(QIODevice::WriteOnly);
        config_file->write(tmp_config_content.toUtf8() + "\n");
        config_file->close();
    }

    qDebug() << "item =>" << configItem.POSITION_X << configItem.POSITION_Y;

    delete config_file;
}

void Widget::set_init_data() {
    // QVector init
    for (auto i=0; i<CHART_ROW; i++) {
        mem_data_history.push_back(0);
        cpuUsage_data_history.push_back(0);
    }
}

void Widget::set_ui_style() {
    // main styleSheet
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(MAIN_OPACITY);
    this->setWindowFlags(windowFlags()|Qt::BypassWindowManagerHint);
    this->setFixedSize(WIDTH, HEIGHT);

    // cpu_label
    cpu_label->setAlignment(Qt::AlignCenter);
    cpu_label->setGeometry(OUTER_CIRCLE_X, OUTER_CIRCLE_Y+1, OUTER_CIRCLE_W, OUTER_CIRCLE_H);
    cpu_label->setFont(QFont(LABEL_FONT_TYPE, LABEL_FONT_SIZE, LABEL_FONT_WEIGHT));
    cpu_label->setStyleSheet(LABEL_STYLE);

    // mail indicating
//    mail_indic_label->setAlignment(Qt::AlignCenter);
//    mail_indic_label->setGeometry(WIDTH-16, HEIGHT-16, 16, 16);
//    mail_indic_label->setPixmap(QPixmap(":/new/prefix1/mail.svg"));
//    mail_indic_label->setScaledContents(true);

    // set qlabel text shadow
    text_shadowEffect = new QGraphicsDropShadowEffect(cpu_label);
    text_shadowEffect->setOffset(0, 0);
    text_shadowEffect->setColor(Qt::black);
    text_shadowEffect->setBlurRadius(LABEL_FONT_SHADOW_R);
    cpu_label->setGraphicsEffect(text_shadowEffect);
}

void Widget::timer_setInterval() {
    content();
}


void Widget::mouseReleaseEvent(QMouseEvent *event) {
    // 保存当前坐标
    POSITION_X = this->x();
    POSITION_Y = this->y();
    deal_configFile(2);

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

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPainterPath path;

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
    QPen chart_pen;
    chart_pen.setColor(QColor::fromRgb(CPU_LINE_COLOR[0], CPU_LINE_COLOR[1], CPU_LINE_COLOR[2]));
    chart_pen.setStyle(Qt::SolidLine);
    chart_pen.setWidthF(CPU_LINE_W);
    painter.setPen(chart_pen);
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
    cpu_label->setText(QString::number(cpu_data, 'f', 2) + "GHz");

    // ######## cpu usage #######
    // 获取cpu使用率
    cpu_usageData = Get_sys_info->getCpuUsageInfo();
    cpuUsage_data_history.push_back(cpu_usageData);
    if (cpuUsage_data_history.size() > CHART_ROW) { cpuUsage_data_history.pop_front(); }


    // ######## mem #############
    // 获取内存占用
    mem_data = Get_sys_info->getMemInfo();
    mem_data_history.push_back(mem_data);
    if (mem_data_history.size() > CHART_ROW) { mem_data_history.pop_front(); }

    update();
}
