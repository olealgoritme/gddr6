


#ifndef ACCESS_MAP_REGISTER_RANGE
#define ACCESS_MAP_REGISTER_RANGE(start, end) 
#endif
#ifdef SMC_UNICAST
    ACCESS_MAP_REGISTER_RANGE(0x40415c, 0x40415c)  // (NV_PGRAPH_PRI_FE_PERFMON, NV_PGRAPH_PRI_FE_PERFMON)
    ACCESS_MAP_REGISTER_RANGE(0x405b50, 0x405b50)  // (NV_PGRAPH_PRI_CWD_PM, NV_PGRAPH_PRI_CWD_PM)
    ACCESS_MAP_REGISTER_RANGE(0x407010, 0x407010)  // (NV_PGRAPH_PRI_SKED_PM, NV_PGRAPH_PRI_SKED_PM)
    ACCESS_MAP_REGISTER_RANGE(0x4090a8, 0x4090a8)  // (NV_PGRAPH_PRI_FECS_FALCON_PMM, NV_PGRAPH_PRI_FECS_FALCON_PMM)
    ACCESS_MAP_REGISTER_RANGE(0x4098a0, 0x4098a0)  // (NV_PGRAPH_PRI_FECS_PERFMON, NV_PGRAPH_PRI_FECS_PERFMON)
    ACCESS_MAP_REGISTER_RANGE(0x40a270, 0x40a274)  // (NV_PGRAPH_PRI_FE_PERFMON_SYS2A, NV_PGRAPH_PRI_FE_PERFMON_SYS2B)
#endif

