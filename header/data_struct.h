// GPL-3.0

#ifndef DATASTRUCT_H
#define DATASTRUCT_H

#include <QString>

#include "define.h"

// mem
struct MemStruct {
    unsigned long long MemTotal;
    unsigned long long MemFree;
    unsigned long long MemAvailable;
    unsigned long long Buffers;
    unsigned long long Cached;
//    unsigned long long SwapCached;
//    unsigned long long Active;
//    unsigned long long Inactive;
//    unsigned long long Active_anon;
//    unsigned long long Inactive_anon;
//    unsigned long long Active_file;
//    unsigned long long Inactive_file;
//    unsigned long long Unevictable;
//    unsigned long long Mlocked;
    unsigned long long SwapTotal;
    unsigned long long SwapFree;
//    unsigned long long Dirty;
//    unsigned long long Writeback;
//    unsigned long long AnonPages;
//    unsigned long long Mapped;
//    unsigned long long Shmem;
//    unsigned long long KReclaimable;
//    unsigned long long Slab;
//    unsigned long long SReclaimable;
//    unsigned long long SUnreclaim;
//    unsigned long long KernelStack;
//    unsigned long long PageTables;
//    unsigned long long NFS_Unstable;
//    unsigned long long Bounce;
//    unsigned long long WritebackTmp;
//    unsigned long long CommitLimit;
//    unsigned long long Committed_AS;
//    unsigned long long VmallocTotal;
//    unsigned long long VmallocUsed;
//    unsigned long long VmallocChunk;
//    unsigned long long Percpu;
//    unsigned long long HardwareCorrupted;
//    unsigned long long AnonHugePages;
//    unsigned long long ShmemHugePages;
//    unsigned long long ShmemPmdMapped;
//    unsigned long long FileHugePages;
//    unsigned long long FilePmdMapped;
//    unsigned long long HugePages_Total;
//    unsigned long long HugePages_Free;
//    unsigned long long HugePages_Rsvd;
//    unsigned long long HugePages_Surp;
//    unsigned long long Hugepagesize;
//    unsigned long long Hugetlb;
//    unsigned long long DirectMap4k;
//    unsigned long long DirectMap2M;
};

// memory and swap rate
struct MemSwapRate {
    double mem;  // memory
    double swap; // swap
};


// configure item
struct ConfigItem {
    int     POSITION_X=0;          // x at window
    int     POSITION_Y=0;          // y at window
    int     REFRESH_INTERVAL=1000; // data refresh interval
    int     SHOW_CPU_LABEL=1;      // cpu label show or hide

    int     CHART_ROW      = 41;   // 图表最大列数 (max row)
    double  CPU_LINE_W     = 1.5;  // cpu line width
    int     WIDTH          = 100;  // window width;
    int     HEIGHT         = 100;  // window height;
    int     BORDER_WIDTH   = 3;    // border width
    int     OUTER_CIRCLE_X = 3;    // outer circle
    int     OUTER_CIRCLE_Y = 3;
    int     OUTER_CIRCLE_W = 94;
    int     OUTER_CIRCLE_H = 94;
    int     MAIN_CIRCLE_X  = 0;    // main circle
    int     MAIN_CIRCLE_Y  = 0;
    int     MAIN_CIRCLE_W  = 100;
    int     MAIN_CIRCLE_H  = 100;
    // font
    QString LABEL_FONT_TYPE     = "Microsoft YaHei";
    int     LABEL_FONT_SIZE     = 10;
    int     LABEL_FONT_WEIGHT   = 74;
    QString LABEL_STYLE         = "color:#fdfefd;";
    int     LABEL_FONT_SHADOW_R = 11;
    // color
    double  MAIN_OPACITY            = 0.89;
    int     MAIN_COLOR[4]           = {35,  38,  41,  255};
    int     OUTER_BORDER_COLOR[4]   = {249, 249, 249, 255};
    int     MEM_CHART_COLOR[4]      = {19,  187, 177, 233};
    int     SWAP_CHART_COLOR[4]     = {255, 136, 96,  233};
    int     CPU_LINE_COLOR[4]       = {121, 230, 203, 255};
    int     CPUUSAGE_CHART_COLOR[4] = {121, 230, 203, 233};
    // radio
    int     NET_CPU_OPTION_RADIO = RADIO_OPTION_0; // 用于切换 netspeed cpu主频 选项
};

// network speed
struct NetFlows {
    double receive;  // receive byte
    double transmit; // transmit byte
};

// cfg 全局变量
extern ConfigItem *cfg;

#endif // DATASTRUCT_H
