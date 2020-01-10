#include "widget.h"

void Widget::deal_configFile(int mode) { // USE_MODE:use conf, SET_MODE: set conf
    QDir dot_config_dir;
    QFileInfo config_file_path;
    QFile *config_file = new QFile; // 配置文件对象
    config_file->setFileName(CONF_FILE_NAME);

    // 获取当前linux用户绝对路径 (current absolute path of linux)
    QString cur_user_fullpath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    // 检测.config目录是否存在 (check .config is exist)
    dot_config_dir.setPath(cur_user_fullpath + "/.config");
    // 不存在则创建 (not exist then create it)
    if (!dot_config_dir.exists()) {
        bool isOk = dot_config_dir.mkdir(cur_user_fullpath + "/.config");
        if (!isOk) { qDebug() << "mkdir .config FAIL =>" << isOk; throw "mkdir .config FAIL"; }
    }

    // 检测 CONF_FILE_NAME 是否存在 不存在则创建
    config_file_path.setFile(cur_user_fullpath + "/.config/" + CONF_FILE_NAME);
    // 不存在则创建 (not exist them create it)
    if (!config_file_path.exists()) {
        config_file->setFileName(cur_user_fullpath + "/.config/" + CONF_FILE_NAME);
        config_file->open(QIODevice::WriteOnly);
        // 添加默认配置
        config_file->write(CONF_FILE_DEFAULT_CONTENT);
        config_file->close();
    }

    // 读配置文件 (use conf)
    config_file->setFileName(cur_user_fullpath + "/.config/" + CONF_FILE_NAME);
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
                    cfg.POSITION_X = item[1].trimmed().split(" ")[0].toInt();
                    cfg.POSITION_Y = item[1].trimmed().split(" ")[1].toInt();
                    // 设置窗口位置
                    this->setGeometry(cfg.POSITION_X, cfg.POSITION_Y, cfg.WIDTH, cfg.HEIGHT);
                    window_adsorb(true);
                break;
                case SET_MODE: // set conf
                    config_items[i] = "POSITION=" + QString::number(cfg.POSITION_X) + " " + QString::number(cfg.POSITION_Y);
                    tmp_config_content = config_items.join("\n");
                break;
                default: break;
            }
        }
        // REFRESH_INTERVAL
        if (item[0].trimmed() == "REFRESH_INTERVAL") {
            switch (mode) {
                case USE_MODE:
                    cfg.REFRESH_INTERVAL = item[1].trimmed().toInt();
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
                    cfg.SHOW_CPU_LABEL = item[1].trimmed().toInt();
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
                    cfg.MAIN_OPACITY = item[1].trimmed().toDouble();
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
