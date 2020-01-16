// GPL-3.0

#include "header/widget.h"

void Widget::right_contextMenu () {

    // ############### configure ##############
    QAction *menu_action_configure = new QAction("configure", this);
    connect(menu_action_configure, &QAction::triggered, [=](){ setting_panel(); } );
    rightBtnMenu->addAction(menu_action_configure);

    // ############### exit ###################
    QAction *menu_action_exit = new QAction("exit", this);
    connect(menu_action_exit, &QAction::triggered, [=](){ exit(0); } );
    rightBtnMenu->addAction(menu_action_exit);
}

void Widget::setting_panel () {
    QDialog *dialog = new ConfigureDialog(this);

    dialog->setGeometry(QApplication::desktop()->width()/2 - (300/2), QApplication::desktop()->height()/2 - (500/2), 300, 500);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->setWindowTitle("configure");
    dialog->exec();
}
