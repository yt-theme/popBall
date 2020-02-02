// GPL-3.0

#include "header/widget.h"

void Widget::right_contextMenu () {

    // ############### system monitor #########
    QAction *menu_action_sysMonitor = new QAction("system monitor", this);
    connect(menu_action_sysMonitor, &QAction::triggered, [=](){ system_monitor(); } );
    rightBtnMenu->addAction(menu_action_sysMonitor);

    // ############### separator ##############
    QAction *sep1 = new QAction("", this);
    sep1->setSeparator(true);
    rightBtnMenu->addAction(sep1);

    // ############### configure ##############
    QAction *menu_action_configure = new QAction("configure", this);
    connect(menu_action_configure, &QAction::triggered, [=](){ setting_panel(); } );
    rightBtnMenu->addAction(menu_action_configure);

    // ############### exit ###################
    QAction *menu_action_exit = new QAction("exit", this);
    connect(menu_action_exit, &QAction::triggered, [=](){ exit(0); } );
    rightBtnMenu->addAction(menu_action_exit);
}

/* realization */

void Widget::system_monitor () {
    QProcess *process = new QProcess;
    process->startDetached(cfg->SYSTEM_MONITOR_PATH);
    process->waitForStarted();
    delete process;
}

void Widget::setting_panel () {
    QDialog *dialog = new ConfigureDialog(this);

    dialog->setGeometry(QApplication::desktop()->width()/2 - (300/2), QApplication::desktop()->height()/2 - (500/2), 300, 500);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->setWindowTitle("configure");
    dialog->exec();
}
