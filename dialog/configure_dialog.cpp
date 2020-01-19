// GPL-3.0

#include "header/configure_dialog.h"
#include "ui_configure_dialog.h"

ConfigureDialog::ConfigureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigureDialog)
{
    ui->setupUi(this);

    // tips
    ui->tips->setText(QString("tips: configure file at ~/.config/") + CONFIGURE_FILE_NAME);

    // set data to ui
    ui->refresh_interval->   setText(QString::number(cfg->REFRESH_INTERVAL));
    ui->showCpu_checkbox->   setCheckState(QString::number(cfg->SHOW_CPU_LABEL) == "1" ? Qt::Checked : Qt::Unchecked);
    ui->labelFont_size->     setText(QString::number(cfg->LABEL_FONT_SIZE));
    ui->main_opacity->       setText(QString::number(cfg->MAIN_OPACITY));
    ui->main_color->         setText(QString::number(cfg->MAIN_COLOR[0]) + " " + QString::number(cfg->MAIN_COLOR[1]) + " " + QString::number(cfg->MAIN_COLOR[2]) + " " + QString::number(cfg->MAIN_COLOR[3]));
    ui->outer_border_color-> setText(QString::number(cfg->OUTER_BORDER_COLOR[0]) + " " + QString::number(cfg->OUTER_BORDER_COLOR[1]) + " " + QString::number(cfg->OUTER_BORDER_COLOR[2]) + " " + QString::number(cfg->OUTER_BORDER_COLOR[3]));
    ui->mem_chart_color->    setText(QString::number(cfg->MEM_CHART_COLOR[0]) + " " + QString::number(cfg->MEM_CHART_COLOR[1]) + " " + QString::number(cfg->MEM_CHART_COLOR[2]) + " " + QString::number(cfg->MEM_CHART_COLOR[3]));
    ui->swap_chart_color->   setText(QString::number(cfg->SWAP_CHART_COLOR[0]) + " " + QString::number(cfg->SWAP_CHART_COLOR[1]) + " " + QString::number(cfg->SWAP_CHART_COLOR[2]) + " " + QString::number(cfg->SWAP_CHART_COLOR[3]));
    ui->cpu_line_color->     setText(QString::number(cfg->CPU_LINE_COLOR[0]) + " " + QString::number(cfg->CPU_LINE_COLOR[1]) + " " + QString::number(cfg->CPU_LINE_COLOR[2]) + " " + QString::number(cfg->CPU_LINE_COLOR[3]));
    ui->cpu_usage_color->    setText(QString::number(cfg->CPUUSAGE_CHART_COLOR[0]) + " " + QString::number(cfg->CPUUSAGE_CHART_COLOR[1]) + " " + QString::number(cfg->CPUUSAGE_CHART_COLOR[2]) + " " + QString::number(cfg->CPUUSAGE_CHART_COLOR[3]));
}

ConfigureDialog::~ConfigureDialog()
{
    delete ui;
}

void ConfigureDialog::on_refresh_interval_editingFinished()
{
    cfg->REFRESH_INTERVAL = ui->refresh_interval->text().toInt();
    saveToConfigureFile();
}

void ConfigureDialog::on_showCpu_checkbox_toggled(bool checked)
{
    cfg->SHOW_CPU_LABEL = checked ? 1 : 0;
    saveToConfigureFile();
}

void ConfigureDialog::on_labelFont_size_editingFinished()
{
    cfg->LABEL_FONT_SIZE = ui->labelFont_size->text().toInt();
    saveToConfigureFile();
}

void ConfigureDialog::on_main_opacity_editingFinished()
{
    cfg->MAIN_OPACITY = ui->main_opacity->text().toDouble();
    saveToConfigureFile();
}

// color
void ConfigureDialog::on_select_color_main_released()
{
    // default color
    QColor default_color = Qt::green;

    // let input val set dialog color
    QStringList tmp_arr = ui->main_color->text().split(" ", QString::SkipEmptyParts);
    if (tmp_arr.size() == 4) { default_color = QColor::fromRgba(qRgba(tmp_arr[0].toInt(), tmp_arr[1].toInt(), tmp_arr[2].toInt(), tmp_arr[3].toInt())); }

    QColor color = QColorDialog::getColor(default_color, this, "main color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        cfg->MAIN_COLOR[0] = color.red();
        cfg->MAIN_COLOR[1] = color.green();
        cfg->MAIN_COLOR[2] = color.blue();
        cfg->MAIN_COLOR[3] = color.alpha();
        ui->main_color->setText(QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()) + " " + QString::number(color.alpha()));
    }
    saveToConfigureFile();
}


void ConfigureDialog::on_select_color_outer_border_released()
{
    // default color
    QColor default_color = Qt::green;

    // let input val set dialog color
    QStringList tmp_arr = ui->outer_border_color->text().split(" ", QString::SkipEmptyParts);
    if (tmp_arr.size() == 4) { default_color = QColor::fromRgba(qRgba(tmp_arr[0].toInt(), tmp_arr[1].toInt(), tmp_arr[2].toInt(), tmp_arr[3].toInt())); }

    QColor color = QColorDialog::getColor(default_color, this, "main color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        cfg->OUTER_BORDER_COLOR[0] = color.red();
        cfg->OUTER_BORDER_COLOR[1] = color.green();
        cfg->OUTER_BORDER_COLOR[2] = color.blue();
        cfg->OUTER_BORDER_COLOR[3] = color.alpha();
        ui->outer_border_color->setText(QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()) + " " + QString::number(color.alpha()));
    }
    saveToConfigureFile();
}

void ConfigureDialog::on_select_color_mem_released()
{
    // default color
    QColor default_color = Qt::green;

    // let input val set dialog color
    QStringList tmp_arr = ui->mem_chart_color->text().split(" ", QString::SkipEmptyParts);
    if (tmp_arr.size() == 4) { default_color = QColor::fromRgba(qRgba(tmp_arr[0].toInt(), tmp_arr[1].toInt(), tmp_arr[2].toInt(), tmp_arr[3].toInt())); }

    QColor color = QColorDialog::getColor(default_color, this, "main color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        cfg->MEM_CHART_COLOR[0] = color.red();
        cfg->MEM_CHART_COLOR[1] = color.green();
        cfg->MEM_CHART_COLOR[2] = color.blue();
        cfg->MEM_CHART_COLOR[3] = color.alpha();
        ui->mem_chart_color->setText(QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()) + " " + QString::number(color.alpha()));
    }
    saveToConfigureFile();
}

void ConfigureDialog::on_select_color_swap_released()
{
    // default color
    QColor default_color = Qt::green;

    // let input val set dialog color
    QStringList tmp_arr = ui->swap_chart_color->text().split(" ", QString::SkipEmptyParts);
    if (tmp_arr.size() == 4) { default_color = QColor::fromRgba(qRgba(tmp_arr[0].toInt(), tmp_arr[1].toInt(), tmp_arr[2].toInt(), tmp_arr[3].toInt())); }

    QColor color = QColorDialog::getColor(default_color, this, "main color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        cfg->SWAP_CHART_COLOR[0] = color.red();
        cfg->SWAP_CHART_COLOR[1] = color.green();
        cfg->SWAP_CHART_COLOR[2] = color.blue();
        cfg->SWAP_CHART_COLOR[3] = color.alpha();
        ui->swap_chart_color->setText(QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()) + " " + QString::number(color.alpha()));
    }
    saveToConfigureFile();
}

void ConfigureDialog::on_select_color_cpu_line_released()
{
    // default color
    QColor default_color = Qt::green;

    // let input val set dialog color
    QStringList tmp_arr = ui->cpu_line_color->text().split(" ", QString::SkipEmptyParts);
    if (tmp_arr.size() == 4) { default_color = QColor::fromRgba(qRgba(tmp_arr[0].toInt(), tmp_arr[1].toInt(), tmp_arr[2].toInt(), tmp_arr[3].toInt())); }

    QColor color = QColorDialog::getColor(default_color, this, "main color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        cfg->CPU_LINE_COLOR[0] = color.red();
        cfg->CPU_LINE_COLOR[1] = color.green();
        cfg->CPU_LINE_COLOR[2] = color.blue();
        cfg->CPU_LINE_COLOR[3] = color.alpha();
        ui->cpu_line_color->setText(QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()) + " " + QString::number(color.alpha()));
    }
    saveToConfigureFile();
}

void ConfigureDialog::on_select_color_cpu_usage_released()
{
    // default color
    QColor default_color = Qt::green;

    // let input val set dialog color
    QStringList tmp_arr = ui->cpu_usage_color->text().split(" ", QString::SkipEmptyParts);
    if (tmp_arr.size() == 4) { default_color = QColor::fromRgba(qRgba(tmp_arr[0].toInt(), tmp_arr[1].toInt(), tmp_arr[2].toInt(), tmp_arr[3].toInt())); }

    QColor color = QColorDialog::getColor(default_color, this, "main color", QColorDialog::ShowAlphaChannel);
    if (color.isValid()) {
        cfg->CPUUSAGE_CHART_COLOR[0] = color.red();
        cfg->CPUUSAGE_CHART_COLOR[1] = color.green();
        cfg->CPUUSAGE_CHART_COLOR[2] = color.blue();
        cfg->CPUUSAGE_CHART_COLOR[3] = color.alpha();
        ui->cpu_usage_color->setText(QString::number(color.red()) + " " + QString::number(color.green()) + " " + QString::number(color.blue()) + " " + QString::number(color.alpha()));
    }
    saveToConfigureFile();
}

// 即时修改功能
void ConfigureDialog::saveToConfigureFile() {
    // 写入配置文件
    QFile *config_file = new QFile;

    // 获取当前linux用户绝对路径 (current absolute path of linux)
    QString cur_user_fullpath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    QString configFile_fullPath = cur_user_fullpath + "/.config/" + CONFIGURE_FILE_NAME;

    config_file->setFileName(configFile_fullPath);

    // content
    QString tmp_config_content;
    tmp_config_content += "POSITION="             + QString::number(cfg->POSITION_X) + " " + QString::number(cfg->POSITION_Y) + "\n";
    tmp_config_content += "REFRESH_INTERVAL="     + QString::number(cfg->REFRESH_INTERVAL) + "\n";
    tmp_config_content += "SHOW_CPU_LABEL="       + QString::number(cfg->SHOW_CPU_LABEL) + "\n";
    tmp_config_content += "LABEL_FONT_SIZE="      + QString::number(cfg->LABEL_FONT_SIZE) + "\n";
    tmp_config_content += "MAIN_OPACITY="         + (cfg->MAIN_OPACITY<=0 ? QString::number(0.1) : QString::number(cfg->MAIN_OPACITY)) + "\n";
    tmp_config_content += "MAIN_COLOR="           + QString::number(cfg->MAIN_COLOR[0])           + " " + QString::number(cfg->MAIN_COLOR[1])           + " " + QString::number(cfg->MAIN_COLOR[2])           + " " + QString::number(cfg->MAIN_COLOR[3]) + "\n";
    tmp_config_content += "OUTER_BORDER_COLOR="   + QString::number(cfg->OUTER_BORDER_COLOR[0])   + " " + QString::number(cfg->OUTER_BORDER_COLOR[1])   + " " + QString::number(cfg->OUTER_BORDER_COLOR[2])   + " " + QString::number(cfg->OUTER_BORDER_COLOR[3]) + "\n";
    tmp_config_content += "MEM_CHART_COLOR="      + QString::number(cfg->MEM_CHART_COLOR[0])      + " " + QString::number(cfg->MEM_CHART_COLOR[1])      + " " + QString::number(cfg->MEM_CHART_COLOR[2])      + " " + QString::number(cfg->MEM_CHART_COLOR[3]) + "\n";
    tmp_config_content += "SWAP_CHART_COLOR="     + QString::number(cfg->SWAP_CHART_COLOR[0])     + " " + QString::number(cfg->SWAP_CHART_COLOR[1])     + " " + QString::number(cfg->SWAP_CHART_COLOR[2])     + " " + QString::number(cfg->SWAP_CHART_COLOR[3]) + "\n";
    tmp_config_content += "CPU_LINE_COLOR="       + QString::number(cfg->CPU_LINE_COLOR[0])       + " " + QString::number(cfg->CPU_LINE_COLOR[1])       + " " + QString::number(cfg->CPU_LINE_COLOR[2])       + " " + QString::number(cfg->CPU_LINE_COLOR[3]) + "\n";
    tmp_config_content += "CPUUSAGE_CHART_COLOR=" + QString::number(cfg->CPUUSAGE_CHART_COLOR[0]) + " " + QString::number(cfg->CPUUSAGE_CHART_COLOR[1]) + " " + QString::number(cfg->CPUUSAGE_CHART_COLOR[2]) + " " + QString::number(cfg->CPUUSAGE_CHART_COLOR[3]) + "\n";

    config_file->open(QIODevice::WriteOnly);
    config_file->write(tmp_config_content.toUtf8() + "\n");
    config_file->close();

    delete config_file;
}
