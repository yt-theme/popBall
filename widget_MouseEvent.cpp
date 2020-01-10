#include "widget.h"

void Widget::mouseReleaseEvent(QMouseEvent *event) {
    // 窗口当前坐标menu_action_exit
    cfg.POSITION_X = this->x();
    cfg.POSITION_Y = this->y();

    // 保存当前坐标
    deal_configFile(SET_MODE);

    // 确定窗口大小模式
    window_adsorb(false);

    Q_UNUSED(event)
    mouseIsPress = false;
}

void Widget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        mouseIsPress = true;
        curPoint = event->pos();
    }
    if (event->button() == Qt::RightButton) {
        rightBtnMenu->exec(event->globalPos()); // 右键菜单 (show right contextMenu)
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
    if (mouseIsPress) {
        move(event->pos() - curPoint + pos());
    }
}
