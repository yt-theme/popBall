// GPL-3.0

#ifndef CONFIGUREDIALOG_H
#define CONFIGUREDIALOG_H

#include <QDialog>
#include <QString>
#include <QColor>
#include <QColorDialog>
#include <QStandardPaths>
#include <QFileInfo>
#include <QFile>
#include <QDebug>

#include "define.h"
#include "data_struct.h"
#include "header/widget.h"
#include "utils/dealtConfigFile.h"

namespace Ui {
class ConfigureDialog;
}

class ConfigureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigureDialog(QWidget *parent = nullptr);
    ~ConfigureDialog();

    void init_setting_item();

    // global data to store
    // cfg

    void saveToConfigureFile(QString content="");


private slots:
    void on_refresh_interval_editingFinished();

    void on_showCpu_checkbox_toggled(bool checked);

    void on_labelFont_size_editingFinished();

    void on_main_opacity_editingFinished();

    void on_select_color_main_released();

    void on_select_color_outer_border_released();

    void on_select_color_mem_released();

    void on_select_color_swap_released();

    void on_select_color_cpu_line_released();

    void on_select_color_cpu_usage_released();

    void on_restore_configure_released();

    void on_radioButton_net_toggled(bool checked);

    void on_radioButton_cpu_toggled(bool checked);

private:
    Ui::ConfigureDialog *ui;
};

#endif // CONFIGUREDIALOG_H
