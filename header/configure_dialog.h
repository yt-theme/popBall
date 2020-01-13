// GPL-3.0

#ifndef CONFIGUREDIALOG_H
#define CONFIGUREDIALOG_H

#include <QDialog>
#include <QString>
#include <QStandardPaths>
#include <QFileInfo>
#include <QFile>
#include <QDebug>

#include "define.h"
#include "data_struct.h"

namespace Ui {
class ConfigureDialog;
}

class ConfigureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigureDialog(QWidget *parent = nullptr);
    ~ConfigureDialog();

    // global data to store
    // cfg

    void saveToConfiureFile();


private slots:
    void on_refresh_interval_editingFinished();

    void on_showCpu_checkbox_toggled(bool checked);

    void on_labelFont_size_editingFinished();

    void on_main_opacity_editingFinished();

private:
    Ui::ConfigureDialog *ui;
};

#endif // CONFIGUREDIALOG_H
