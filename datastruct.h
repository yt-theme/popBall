#ifndef DATASTRUCT_H
#define DATASTRUCT_H


class DataStruct
{
public:
    DataStruct();

    struct CpuStruct {
        double max_freq;
        double min_freq;
        double ave_freq;
    };

    struct SysInfo {
        long uptime;
        unsigned long loads[3];
        unsigned long totalram;
        unsigned long freeram;
        unsigned long sharedram;
        unsigned long bufferram;
        unsigned long totalswap;
        unsigned long freeswap;
        unsigned short procs;
        unsigned long totalhigh;
        unsigned long freehigh;
        unsigned int mem_unit;
    };
};

#endif // DATASTRUCT_H
