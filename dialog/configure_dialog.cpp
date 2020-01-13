#include "configure_dialog.h"
#include "ui_configuredialog.h"

ConfigureDialog::ConfigureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigureDialog)
{
    ui->setupUi(this);

    // tips
    ui->tips->setText(QString("tips: configure file at ~/.config/") + CONFIGURE_FILE_NAME);

    // set data to ui
    ui->refresh_interval->setText(QString::number(cfg->REFRESH_INTERVAL));
    ui->showCpu_checkbox->setCheckState(QString::number(cfg->SHOW_CPU_LABEL) == "1" ? Qt::Checked : Qt::Unchecked);
    ui->labelFont_size->  setText(QString::number(cfg->LABEL_FONT_SIZE));
    ui->main_opacity->    setText(QString::number(cfg->MAIN_OPACITY));
}

ConfigureDialog::~ConfigureDialog()
{
    delete ui;
}

void ConfigureDialog::on_refresh_interval_editingFinished()
{
    cfg->REFRESH_INTERVAL = ui->refresh_interval->text().toInt();
    saveToConfiureFile();
}

void ConfigureDialog::on_showCpu_checkbox_toggled(bool checked)
{
    cfg->SHOW_CPU_LABEL = checked ? 1 : 0;
    saveToConfiureFile();
}

void ConfigureDialog::on_labelFont_size_editingFinished()
{
    cfg->LABEL_FONT_SIZE = ui->labelFont_size->text().toInt();
    saveToConfiureFile();
}

void ConfigureDialog::on_main_opacity_editingFinished()
{
    cfg->MAIN_OPACITY = ui->main_opacity->text().toDouble();
    saveToConfiureFile();
}

// 即时修改功能
void ConfigureDialog::saveToConfiureFile() {
    // 写入配置文件
    QFile *config_file = new QFile;

    // 获取当前linux用户绝对路径 (current absolute path of linux)
    QString cur_user_fullpath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    QString configFile_fullPath = cur_user_fullpath + "/.config/" + CONFIGURE_FILE_NAME;

    config_file->setFileName(configFile_fullPath);

    // content
    QString tmp_config_content;
    tmp_config_content += "POSITION="         + QString::number(cfg->POSITION_X) + " " + QString::number(cfg->POSITION_Y) + "\n";
    tmp_config_content += "REFRESH_INTERVAL=" + QString::number(cfg->REFRESH_INTERVAL) + "\n";
    tmp_config_content += "SHOW_CPU_LABEL="   + QString::number(cfg->SHOW_CPU_LABEL) + "\n";
    tmp_config_content += "LABEL_FONT_SIZE="  + QString::number(cfg->LABEL_FONT_SIZE) + "\n";
    tmp_config_content += "MAIN_OPACITY="     + QString::number(cfg->MAIN_OPACITY) + "\n";

    config_file->open(QIODevice::WriteOnly);
    config_file->write(tmp_config_content.toUtf8() + "\n");
    config_file->close();

    delete config_file;
}
