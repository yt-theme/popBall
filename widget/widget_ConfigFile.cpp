// GPL-3.0

#include "header/widget.h"

void Widget::deal_configFile(int mode) { // USE_MODE:use conf, SET_MODE: set conf
    QDir dot_config_dir;
    QFileInfo config_file_path;
    QFile *config_file = new QFile; // 配置文件对象
    config_file->setFileName(CONFIGURE_FILE_NAME);

    // 获取当前linux用户绝对路径 (current absolute path of linux)
    QString cur_user_fullpath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    // 检测.config目录是否存在 (check .config is exist)
    dot_config_dir.setPath(cur_user_fullpath + "/.config");
    // 不存在则创建 (not exist then create it)
    if (!dot_config_dir.exists()) {
        bool isOk = dot_config_dir.mkdir(cur_user_fullpath + "/.config");
        if (!isOk) { qDebug() << "mkdir .config FAIL =>" << isOk; throw "mkdir .config FAIL"; }
    }

    // 检测 CONFIGURE_FILE_NAME 是否存在 不存在则创建
    config_file_path.setFile(cur_user_fullpath + "/.config/" + CONFIGURE_FILE_NAME);
    // 不存在则创建 (not exist them create it)
    if (!config_file_path.exists()) {
        config_file->setFileName(cur_user_fullpath + "/.config/" + CONFIGURE_FILE_NAME);
        config_file->open(QIODevice::WriteOnly);
        // 添加默认配置
        config_file->write(DEFAULT_CONFIGURE_CONTENT);
        config_file->close();
    }

    read_configFile(mode); // read configurefile to cfg var
}

void Widget::read_configFile(int mode) {
    ReadConfigFile::read(mode);
}
