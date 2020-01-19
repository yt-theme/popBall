// GPL-3.0

#include "dealtConfigFile.h"

void ReadConfigFile::read(int mode) {
    QFile *config_file = new QFile; // 配置文件对象
    config_file->setFileName(CONFIGURE_FILE_NAME);
    // 获取当前linux用户绝对路径 (current absolute path of linux)
    QString cur_user_fullpath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    // 读配置文件 (use conf)
    config_file->setFileName(cur_user_fullpath + "/.config/" + CONFIGURE_FILE_NAME);
    bool openOk = config_file->open(QIODevice::ReadWrite|QIODevice::Text);
    if (!openOk) { qDebug() << "read conf file err =>"; throw "read conf file err"; }
    QString conf_file_content = config_file->readAll();
    // 以\n划分配置项
    QStringList config_items = conf_file_content.split("\n", QString::SkipEmptyParts);
    // 每个配置项用=划分键和值 (= split key and v)
    QString tmp_config_content; // 临时配置文件内容
    for (int i=0; i<config_items.size(); i++) {
        QStringList item = config_items[i].split("=", QString::SkipEmptyParts);
        // POSITOIN
        if(item[0].trimmed() == "POSITION") {
            // mode
            switch (mode) {
                case USE_MODE: // use conf
                    cfg->POSITION_X = item[1].trimmed().split(" ")[0].toInt();
                    cfg->POSITION_Y = item[1].trimmed().split(" ")[1].toInt();

                break;
                case SET_MODE: // set conf
                    config_items[i] = "POSITION=" + QString::number(cfg->POSITION_X) + " " + QString::number(cfg->POSITION_Y);
                    tmp_config_content = config_items.join("\n");
                break;
                default: break;
            }
        }
        // REFRESH_INTERVAL
        if (item[0].trimmed() == "REFRESH_INTERVAL") {
            switch (mode) {
                case USE_MODE:
                    cfg->REFRESH_INTERVAL = item[1].trimmed().toInt();
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // show cpu label
        if (item[0].trimmed() == "SHOW_CPU_LABEL") {
            switch (mode) {
                case USE_MODE:
                    cfg->SHOW_CPU_LABEL = item[1].trimmed().toInt();
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // MAIN_OPACITY
        if (item[0].trimmed() == "MAIN_OPACITY") {
            switch (mode) {
                case USE_MODE:
                    cfg->MAIN_OPACITY = item[1].trimmed().toDouble();
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // LABEL_FONT_SIZE
        if (item[0].trimmed() == "LABEL_FONT_SIZE") {
            switch (mode) {
                case USE_MODE:
                    cfg->LABEL_FONT_SIZE = item[1].trimmed().toInt();
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // every color
        // MAIN_COLOR
        if (item[0].trimmed() == "MAIN_COLOR") {
            switch (mode) {
                case USE_MODE:
                {
                    auto tmp = item[1].split(" ", QString::SkipEmptyParts);
                    cfg->MAIN_COLOR[0] = tmp[0].toInt();
                    cfg->MAIN_COLOR[1] = tmp[1].toInt();
                    cfg->MAIN_COLOR[2] = tmp[2].toInt();
                    cfg->MAIN_COLOR[3] = tmp[3].toInt();
                }
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // OUTER_BORDER_COLOR
        if (item[0].trimmed() == "OUTER_BORDER_COLOR") {
            switch (mode) {
                case USE_MODE:
                {
                    auto tmp = item[1].split(" ", QString::SkipEmptyParts);
                    cfg->OUTER_BORDER_COLOR[0] = tmp[0].toInt();
                    cfg->OUTER_BORDER_COLOR[1] = tmp[1].toInt();
                    cfg->OUTER_BORDER_COLOR[2] = tmp[2].toInt();
                    cfg->OUTER_BORDER_COLOR[3] = tmp[3].toInt();
                }
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // MEM_CHART_COLOR
        if (item[0].trimmed() == "MEM_CHART_COLOR") {
            switch (mode) {
                case USE_MODE:
                {
                    auto tmp = item[1].split(" ", QString::SkipEmptyParts);
                    cfg->MEM_CHART_COLOR[0] = tmp[0].toInt();
                    cfg->MEM_CHART_COLOR[1] = tmp[1].toInt();
                    cfg->MEM_CHART_COLOR[2] = tmp[2].toInt();
                    cfg->MEM_CHART_COLOR[3] = tmp[3].toInt();
                }
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // SWAP_CHART_COLOR
        if (item[0].trimmed() == "SWAP_CHART_COLOR") {
            switch (mode) {
                case USE_MODE:
                {
                    auto tmp = item[1].split(" ", QString::SkipEmptyParts);
                    cfg->SWAP_CHART_COLOR[0] = tmp[0].toInt();
                    cfg->SWAP_CHART_COLOR[1] = tmp[1].toInt();
                    cfg->SWAP_CHART_COLOR[2] = tmp[2].toInt();
                    cfg->SWAP_CHART_COLOR[3] = tmp[3].toInt();
                }
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // SWAP_CHART_COLOR
        if (item[0].trimmed() == "CPU_LINE_COLOR") {
            switch (mode) {
                case USE_MODE:
                {
                    auto tmp = item[1].split(" ", QString::SkipEmptyParts);
                    cfg->CPU_LINE_COLOR[0] = tmp[0].toInt();
                    cfg->CPU_LINE_COLOR[1] = tmp[1].toInt();
                    cfg->CPU_LINE_COLOR[2] = tmp[2].toInt();
                    cfg->CPU_LINE_COLOR[3] = tmp[3].toInt();
                }
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
        // CPUUSAGE_CHART_COLOR
        if (item[0].trimmed() == "CPUUSAGE_CHART_COLOR") {
            switch (mode) {
                case USE_MODE:
                {
                    auto tmp = item[1].split(" ", QString::SkipEmptyParts);
                    cfg->CPUUSAGE_CHART_COLOR[0] = tmp[0].toInt();
                    cfg->CPUUSAGE_CHART_COLOR[1] = tmp[1].toInt();
                    cfg->CPUUSAGE_CHART_COLOR[2] = tmp[2].toInt();
                    cfg->CPUUSAGE_CHART_COLOR[3] = tmp[3].toInt();
                }
                break;
                case SET_MODE:

                break;
                default: break;
            }
        }
    }
    config_file->close();

    // 写入配置文件
    if (mode==SET_MODE && tmp_config_content.size()>0) {
        config_file->open(QIODevice::WriteOnly);
        config_file->write(tmp_config_content.toUtf8() + "\n");
        config_file->close();
    }

    delete config_file;
}
