#include "widget.h"

void Widget::right_contextMenu () {
    // right contextMenu


    // configure
    QAction *menu_action_configure = new QAction("configure", this);
    rightBtnMenu->addAction(menu_action_configure);


    // exit
    QAction *menu_action_exit = new QAction("exit", this);
    connect(menu_action_exit, &QAction::triggered,
        [=](){
            delete menu_action_exit;
            delete menu_action_configure;
            qDebug() << "exit =>";
            exit(0);
        }
    );
    rightBtnMenu->addAction(menu_action_exit);
}
