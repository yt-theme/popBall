#include "header/widget.h"

void Widget::window_adsorb(bool isInit) {

    // 判断模式
    int mode = NORMAL_MODE;

    // 判断窗口坐标是否超过屏幕边缘
    const int screen_w = QApplication::desktop()->width();
    const int screen_h = QApplication::desktop()->height();

    // 窗口吸附左边
    if (cfg->POSITION_X < 0) { mode = LEFT_MODE; }
    // 窗口吸附到右边
    if (cfg->POSITION_X > (screen_w - cfg->WIDTH)) { mode = RIGHT_MODE; }
    // 窗口拖上下边判断
    if (cfg->POSITION_Y<0 || cfg->POSITION_Y>(screen_h - cfg->HEIGHT)) {
        if (cfg->POSITION_X <  ((screen_w - cfg->WIDTH)/2)) { mode = LEFT_MODE;  }
        if (cfg->POSITION_X >  ((screen_w - cfg->WIDTH)/2)) { mode = RIGHT_MODE; }
        if (cfg->POSITION_X == ((screen_w - cfg->WIDTH)/2)) { mode = RIGHT_MODE; }
    }
    // 窗口正常
    if ( cfg->POSITION_X>=0 && cfg->POSITION_X<=(screen_w - cfg->WIDTH) && cfg->POSITION_Y>=0 && cfg->POSITION_Y<=(screen_h - cfg->HEIGHT) ) { mode = NORMAL_MODE; }

    switch (mode) {
        case LEFT_MODE:
        {
            WINDOW_SIZE_LOOK     = MINI_MODE;
            WINDOW_SET_DIRECTION = LEFT_MODE;
            // 窗口位置
            int pos_y = cfg->POSITION_Y;
            if (cfg->POSITION_Y<0) { pos_y = 0; }
            if (cfg->POSITION_Y > QApplication::desktop()->height()-cfg->HEIGHT) { pos_y = QApplication::desktop()->height()-cfg->HEIGHT; }
            this->setGeometry(0, pos_y, cfg->WIDTH/6+1, cfg->HEIGHT);
            // set size and content
            this->setFixedSize(cfg->MAIN_CIRCLE_W/6, cfg->HEIGHT);
            // hide item
            cpu_label->clear();
        }
        break;
        case RIGHT_MODE:
        {
            WINDOW_SIZE_LOOK     = MINI_MODE;
            WINDOW_SET_DIRECTION = RIGHT_MODE;
            // 窗口位置
            int pos_y = cfg->POSITION_Y;
            if (cfg->POSITION_Y<0) { pos_y = 0; }
            if (cfg->POSITION_Y > QApplication::desktop()->height()-cfg->HEIGHT) { pos_y = QApplication::desktop()->height()-cfg->HEIGHT; }
            this->setGeometry(QApplication::desktop()->width()-cfg->MAIN_CIRCLE_W/6, pos_y, cfg->WIDTH/6+1, cfg->HEIGHT);
            // set size and content
            this->setFixedSize(cfg->MAIN_CIRCLE_W/6, cfg->HEIGHT);
            cpu_label->clear();
        }
        break;
        case NORMAL_MODE: WINDOW_SIZE_LOOK = NORMAL_MODE; WINDOW_SET_DIRECTION = NOTEDGE_MODE; break;
        default:          WINDOW_SIZE_LOOK = NORMAL_MODE; WINDOW_SET_DIRECTION = NOTEDGE_MODE; break;
    }

    // 重绘
    if (isInit) {

    } else {
        update(); // or use update()
    }
}
