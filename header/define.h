// GPL-3.0

#ifndef DEFINE_H
#define DEFINE_H

#define DEFAULT_CONFIGURE_CONTENT \
    "POSITION=0 0\n" \
    "REFRESH_INTERVAL=1300\n" \
    "SHOW_CPU_LABEL=1\n" \
    "LABEL_FONT_SIZE=10\n" \
    "MAIN_OPACITY=0.89\n" \
    "MAIN_COLOR=35 38 41 255\n" \
    "OUTER_BORDER_COLOR=249 249 249 255\n" \
    "MEM_CHART_COLOR=48 98 213 233\n" \
    "SWAP_CHART_COLOR=230 117 52 233\n" \
    "CPU_LINE_COLOR=206 231 255 255\n" \
    "CPUUSAGE_CHART_COLOR=121 230 203 233\n" \
    "NET_CPU_OPTION_RADIO=0\n" \
    "SYSTEM_MONITOR_PATH="// 默认配置文件内容

#define CONFIGURE_FILE_NAME "yt-popball.conf" // 配置文件名



#define USE_MODE 1     // 使用模式
#define SET_MODE 2     // 设置模式

#define LEFT_MODE 3    // 左模式
#define RIGHT_MODE 4   // 右模式
#define TOP_MODE 5     // 上模式
#define BOTTOM_MODE 6  // 下模式
#define NOTEDGE_MODE 7 // 非边缘模式

#define HIDE_MODE 0    // 隐藏模式
#define SHOW_MODE 1    // 展示模式

#define MINI_MODE 10   // 微小模式
#define SMALL_MODE 11  // 小模式
#define NORMAL_MODE 12 // 正常模式
#define BIG_MODE 13    // 大模式
#define BIGGER_MODE 14 // 巨大模式

#define EXEC_CONSTRUCTOR 15    // 执行构造函数
#define NO_EXEC_CONSTRUCTOR 16 // 不执行构造函数

#define RADIO_OPTION_0 0 // radio 选项
#define RADIO_OPTION_1 1
#define RADIO_OPTION_2 2

#endif // DEFINE_H
