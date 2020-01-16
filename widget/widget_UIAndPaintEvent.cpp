// GPL-3.0

#include "header/widget.h"

void Widget::main_ui_style() {
    // main styleSheet
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowOpacity(cfg->MAIN_OPACITY);
    this->setWindowFlags(windowFlags()|Qt::BypassWindowManagerHint);
    this->setFixedSize(cfg->WIDTH, cfg->HEIGHT);


    // cpuTemper_label
    cpuTemper_label->setAlignment(Qt::AlignCenter);
    cpuTemper_label->setGeometry(cfg->OUTER_CIRCLE_X, cfg->OUTER_CIRCLE_Y+1, cfg->OUTER_CIRCLE_W, cfg->OUTER_CIRCLE_H/2);
    cpuTemper_label->setFont(QFont(cfg->LABEL_FONT_TYPE, static_cast<int>(cfg->LABEL_FONT_SIZE*0.79), cfg->LABEL_FONT_WEIGHT));
    cpuTemper_label->setStyleSheet(cfg->LABEL_STYLE);


    // cpu_label
    cpu_label->setAlignment(Qt::AlignCenter);
    cpu_label->setGeometry(cfg->OUTER_CIRCLE_X, cfg->OUTER_CIRCLE_Y+1, cfg->OUTER_CIRCLE_W, cfg->OUTER_CIRCLE_H);
    cpu_label->setFont(QFont(cfg->LABEL_FONT_TYPE, cfg->LABEL_FONT_SIZE, cfg->LABEL_FONT_WEIGHT));
    cpu_label->setStyleSheet(cfg->LABEL_STYLE);


    // indicating
    // mail icon
    QIcon mail_indic_button_icon;
    mail_indic_button_icon.addFile(":/new/prefix1/mail.svg");
    mail_indic_button->setIcon(mail_indic_button_icon);
    mail_indic_button->setStyleSheet("background:#2F3439;border:1.5px solid #E4E4E4;border-radius:12px;margin:0;");
    mail_indic_button->setGeometry(cfg->WIDTH-24, 0, 24, 24);

    // clock icon
    QIcon clock_indic_button_icon;
    clock_indic_button_icon.addFile(":/new/prefix2/clock.svg");
    clock_indic_button->setIcon(clock_indic_button_icon);
    clock_indic_button->setStyleSheet("background:#2F3439;border:1.5px solid #E4E4E4;border-radius:12px;margin:0;");
    clock_indic_button->setGeometry(0, 0, 24, 24);


    // set qlabel text shadow
    // cpu_label
    text_shadowEffect = new QGraphicsDropShadowEffect(cpu_label);
    text_shadowEffect->setOffset(0, 0);
    text_shadowEffect->setColor(Qt::black);
    text_shadowEffect->setBlurRadius(cfg->LABEL_FONT_SHADOW_R);
    cpu_label->setGraphicsEffect(text_shadowEffect);

    // cpuTemper_label
    text_shadowEffect = new QGraphicsDropShadowEffect(cpuTemper_label);
    text_shadowEffect->setOffset(0, 0);
    text_shadowEffect->setColor(Qt::black);
    text_shadowEffect->setBlurRadius(cfg->LABEL_FONT_SHADOW_R);
    cpuTemper_label->setGraphicsEffect(text_shadowEffect);
}

void Widget::paintEvent(QPaintEvent *) {

    QPainter painter(this);
    QPainterPath path;

    // 窗口样式
    switch (WINDOW_SIZE_LOOK) {
        case NORMAL_MODE: // WINDOW_SET_DIRECTION = NOTEDGE_MODE;
        {
            // action button look
            mail_indic_button->show();
            clock_indic_button->show();

            // set size and content
            this->setFixedSize(cfg->WIDTH, cfg->HEIGHT);

            painter.setRenderHint(QPainter::Antialiasing);
            painter.setBrush(QBrush(QColor::fromRgb( cfg->MAIN_COLOR[0], cfg->MAIN_COLOR[1], cfg->MAIN_COLOR[2] )));

            // main circle
            painter.setPen(Qt::transparent);
            painter.drawEllipse(cfg->MAIN_CIRCLE_X, cfg->MAIN_CIRCLE_Y, cfg->MAIN_CIRCLE_W, cfg->MAIN_CIRCLE_H);

            // outer circle
            QPen outercircle_pen(QColor::fromRgb( cfg->OUTER_BORDER_COLOR[0], cfg->OUTER_BORDER_COLOR[1], cfg->OUTER_BORDER_COLOR[2] ), cfg->BORDER_WIDTH, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin);
            painter.setPen(outercircle_pen);
            painter.drawEllipse(cfg->OUTER_CIRCLE_X, cfg->OUTER_CIRCLE_Y, cfg->OUTER_CIRCLE_W, cfg->OUTER_CIRCLE_H);

            // clip
            // 裁剪
            QPainterPath clip_path;
            clip_path.moveTo(cfg->OUTER_CIRCLE_X, cfg->OUTER_CIRCLE_Y);
            clip_path.arcTo(cfg->OUTER_CIRCLE_X+cfg->BORDER_WIDTH, cfg->OUTER_CIRCLE_Y+cfg->BORDER_WIDTH, cfg->OUTER_CIRCLE_W-(cfg->BORDER_WIDTH*2), cfg->OUTER_CIRCLE_H-(cfg->BORDER_WIDTH*2), 0, 360);
            painter.setClipPath(clip_path);

            // pen used to draw chart
            QPen chart_pen;
            chart_pen.setColor(QColor::fromRgb(cfg->CPU_LINE_COLOR[0], cfg->CPU_LINE_COLOR[1], cfg->CPU_LINE_COLOR[2]));
            chart_pen.setStyle(Qt::SolidLine);

            // mem chart
            chart_pen.setWidthF(cfg->CPU_LINE_W);
            painter.setPen(chart_pen);
//            painter.setViewport(cfg->OUTER_CIRCLE_X, cfg->HEIGHT/2 - cfg->OUTER_CIRCLE_Y, cfg->WIDTH, cfg->HEIGHT/2);
            path.moveTo(cfg->OUTER_CIRCLE_X, cfg->HEIGHT);
            for (auto i=0; i<mem_data_history.size(); i++) {
                path.lineTo(i*cfg->WIDTH/cfg->CHART_ROW, 100 - mem_data_history[i]);
            }
            path.lineTo(cfg->WIDTH, 100 - mem_data_history[ mem_data_history.size()-1 ]);
            path.lineTo(cfg->WIDTH, cfg->HEIGHT);
            painter.fillPath(path, QColor::fromRgba(qRgba(cfg->MEM_CHART_COLOR[0],cfg->MEM_CHART_COLOR[1],cfg->MEM_CHART_COLOR[2],cfg->MEM_CHART_COLOR[3])));

            // cpuUsage chart
            QLineF cpuUsage_pen[cpuUsage_data_history.size()];
            QPointF cpuUsage_prevPoint[1] = { QPointF(cfg->OUTER_CIRCLE_X, cfg->HEIGHT) }; // prev
            for (int i=0; i<cpuUsage_data_history.size(); i++) {
                cpuUsage_pen[i].setPoints(
                            cpuUsage_prevPoint[0],
                            QPointF(i*cfg->WIDTH/cfg->CHART_ROW, 100 - cpuUsage_data_history[i])
                        );
                cpuUsage_prevPoint[0] = { QPointF(i*cfg->WIDTH/cfg->CHART_ROW, 100 - cpuUsage_data_history[i]) };
            }
            painter.drawLines(cpuUsage_pen, cpuUsage_data_history.size());
        }
        break;
        case MINI_MODE:
        {
            // action button look
            mail_indic_button->hide();
            clock_indic_button->hide();

            // draw a round rect
            painter.setRenderHint(QPainter::Antialiasing);
            painter.setBrush(QBrush(QColor::fromRgb( cfg->MAIN_COLOR[0], cfg->MAIN_COLOR[1], cfg->MAIN_COLOR[2] )));

            // main round rect
            painter.setPen(Qt::transparent);
            painter.drawRoundedRect(cfg->MAIN_CIRCLE_X, cfg->MAIN_CIRCLE_Y, cfg->MAIN_CIRCLE_W/6, cfg->MAIN_CIRCLE_H, 1, 1);

            // mem chart
            QPen mem_pen;
            mem_pen.setColor(QColor::fromRgb(cfg->MAIN_COLOR[0], cfg->MAIN_COLOR[1], cfg->MAIN_COLOR[2]));
            mem_pen.setStyle(Qt::SolidLine);
            mem_pen.setWidthF(cfg->CPU_LINE_W);
            painter.setBrush(QBrush(QColor::fromRgb( cfg->MEM_CHART_COLOR[0], cfg->MEM_CHART_COLOR[1], cfg->MEM_CHART_COLOR[2] )));
            painter.setPen(mem_pen);
            painter.drawRoundedRect(1, 100-(static_cast<int>(mem_data)), cfg->MAIN_CIRCLE_W/6-2, (static_cast<int>(mem_data)), 0, 0);

            // cpu chart
            QPen cpu_pen;
            cpu_pen.setColor(QColor::fromRgb(cfg->MAIN_COLOR[0], cfg->MAIN_COLOR[1], cfg->MAIN_COLOR[2]));
            cpu_pen.setStyle(Qt::SolidLine);
            cpu_pen.setWidthF(cfg->CPU_LINE_W);
            painter.setBrush(QBrush(QColor::fromRgb( cfg->CPU_LINE_COLOR[0], cfg->CPU_LINE_COLOR[1], cfg->CPU_LINE_COLOR[2] )));
            painter.setPen(cpu_pen);
            painter.drawRoundedRect(cfg->MAIN_CIRCLE_W/6/2-1, 100-(static_cast<int>(cpu_usageData)), cfg->MAIN_CIRCLE_W/6/2, (static_cast<int>(cpu_usageData)), 0, 0);

            switch (WINDOW_SET_DIRECTION) {
                case LEFT_MODE:
                {

                }
                break;
                case RIGHT_MODE:
                {

                }
                break;
                default: break;
            }
        }
        break;
        default: break;
    }
}
