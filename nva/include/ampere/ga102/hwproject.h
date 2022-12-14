/* _NVRM_COPYRIGHT_BEGIN_
 *
 * Copyright 2003-2016 by NVIDIA Corporation.  All rights reserved.  All
 * information contained herein is proprietary and confidential to NVIDIA
 * Corporation.  Any use, reproduction, or disclosure without the written
 * permission of NVIDIA Corporation is prohibited.
 *
 * _NVRM_COPYRIGHT_END_
 */

/* This file is autogenerated by ref2h.pl.  Do not edit */
#define NV_EGPC_IN_GR_BASE                    1572864
#define NV_EGPC_IN_GR_SHARED_BASE                      524288
#define NV_EGPC_PRI_SHARED_INDEX                          -32
#define NV_EGPC_PRI_STRIDE                      32768
#define NV_FBPA_PRI_STRIDE                      16384
#define NV_FBP_PRIV_BASE                          1212416
#define NV_FBP_PRIV_BC_BASE                   1183744
#define NV_FBP_PRIV_STRIDE                       2048
#define NV_GPC_IN_GR_BASE                         1048576
#define NV_GPC_IN_GR_SHARED_BASE                        98304
#define NV_GPC_PRIV_BASE                          1196032
#define NV_GPC_PRIV_BC_BASE                   1181696
#define NV_GPC_PRIV_STRIDE                       2048
#define NV_GPC_PRI_BASE                       5242880
#define NV_GPC_PRI_SHARED_BASE                    4292608
#define NV_GPC_PRI_SHARED_INDEX                       -29
#define NV_GPC_PRI_STRIDE                           32768
#define NV_LTC_PRI_BASE                       1310720
#define NV_LTC_PRI_STRIDE                            8192
#define NV_LTS_PRI_STRIDE                             512
#define NV_CHIP_EXTENDED_PHYSICAL_ADDRESS_BITS                 47
#define NV_CHIP_EXTENDED_SYSTEM_PHYSICAL_ADDRESS_BITS              47
#define NV_CHIP_EXTENDED_VIRTUAL_ADDRESS_BITS                  49
#define NV_CHIP_ISBE_SIZE                       49152
#define NV_CHIP_LOCAL_PHYSICAL_ADDRESS_BITS                37
#define NV_CHIP_LTC_LTS_BYTES_PER_LINE                    128
#define NV_CHIP_LTC_LTS_CBC_USE_HUB_BASE                1
#define NV_CHIP_LTC_LTS_ISO_RDAT_FIFO_DEPTH               192
#define NV_CHIP_LTC_LTS_NUM_SETS                       64
#define NV_CHIP_PES_ENABLED                     1
#define NV_CHIP_PHYSICAL_ADDRESS_BITS                      40
#define NV_CHIP_SYSTEM_PHYSICAL_ADDRESS_BITS                   40
#define NV_CHIP_TEX_PER_TPC                     2
#define NV_CHIP_VIRTUAL_ADDRESS_BITS                       40
#define NV_GR_FECS_FALCON_IMEM_SIZE                   128
#define NV_GR_GPCCS_FALCON_IMEM_SIZE                       64
#define NV_HOST_MAX_NUM_GRCE_PER_RUNLIST                2
#define NV_HOST_MAX_NUM_PBDMA                          16
#define NV_HOST_NEW_MEMOP                       1
#define NV_HOST_NUM_ENGINES                        11
#define NV_HOST_NUM_PBDMA                          10
#define NV_LITTER_SUPPORTS_PLC                      1
#define NV_MMU_FAULT_BUFFER_COUNT                   2
#define NV_MMU_NON_REPLAY_FAULT_BUFFER                  0
#define NV_MMU_PROTECTION_REGIONS                   1
#define NV_MMU_PROTECTION_REGION_ADDR_ALIGN                20
#define NV_MMU_PROTECTION_REGION_ADDR_WIDTH                17
#define NV_MMU_PROTECTION_REGION_CYA_WIDTH                 48
#define NV_MMU_REPLAY_FAULT_BUFFER                  1
#define NV_MMU_WRITE_PROTECTION_REGIONS                 2
#define NV_MMU_WRITE_PROTECTION_REGION_ADDR_ALIGN              17
#define NV_MMU_WRITE_PROTECTION_REGION_ADDR_WIDTH              20
#define NV_MMU_WRITE_PROTECTION_REGION_SECURE_LEVELS            4
#define NV_NVL_NVLIPT_NUM_LINKS                     4
#define NV_PGRAPH_ZCULL_ALIQUOTS_COVERED                 5120
#define NV_PGRAPH_ZCULL_BYTES_PER_ALIQUOT_PER_GPC              32
#define NV_PGRAPH_ZCULL_NUM_ZFAR                    4
#define NV_PGRAPH_ZCULL_NUM_ZNEAR                   4
#define NV_PGRAPH_ZCULL_PIXELS_COVERED               36700160
#define NV_PGRAPH_ZCULL_SAVE_RESTORE_HEADER_BYTES_PER_GPC          32
#define NV_PGRAPH_ZCULL_SAVE_RESTORE_SUBREGION_HEADER_BYTES_PER_GPC   192
#define NV_PGRAPH_ZCULL_SUBREGION_QTY                      16
#define NV_RAMRL_ENTRY_EXPANDED                     1
#define NV_SCAL_FAMILY_MAX_FBPS                        16
#define NV_SCAL_FAMILY_MAX_GPCS                        32
#define NV_SCAL_FAMILY_MAX_SYSS                     1
#define NV_SCAL_FAMILY_MAX_TPC_PER_GPC                  8
#define NV_SCAL_FAMILY_MAX_ZCULL_BANKS                  8
#define NV_SCAL_LITTER_MAX_NUM_COMP_SMC_ENGINES             0
#define NV_SCAL_LITTER_MAX_NUM_GFXC_SMC_ENGINES             1
#define NV_SCAL_LITTER_MAX_NUM_SMC_ENGINES              1
#define NV_SCAL_LITTER_NUM_FBHUB_PORTS                  2
#define NV_SCAL_LITTER_NUM_FBPAS                    6
#define NV_SCAL_LITTER_NUM_FBPA_PER_FBP                 1
#define NV_SCAL_LITTER_NUM_FBPS                     6
#define NV_SCAL_LITTER_NUM_GPCMMU_PER_GPC               1
#define NV_SCAL_LITTER_NUM_GPCS                     7
#define NV_SCAL_LITTER_NUM_IOCTRL                   1
#define NV_SCAL_LITTER_NUM_LTCS                        12
#define NV_SCAL_LITTER_NUM_LTC_LTS_SETS                    64
#define NV_SCAL_LITTER_NUM_LTC_LTS_WAYS                    16
#define NV_SCAL_LITTER_NUM_LTC_PER_FBP                  2
#define NV_SCAL_LITTER_NUM_LTC_SLICES                   8
#define NV_SCAL_LITTER_NUM_MIN_FBPS                 1
#define NV_SCAL_LITTER_NUM_MXBAR_FBP_PORTS              8
#define NV_SCAL_LITTER_NUM_MXBAR_HUB_PORTS              8
#define NV_SCAL_LITTER_NUM_NVLINK                   4
#define NV_SCAL_LITTER_NUM_PES_PER_GPC                  3
#define NV_SCAL_LITTER_NUM_ROP_PER_GPC                  2
#define NV_SCAL_LITTER_NUM_SLICES_PER_LTC               4
#define NV_SCAL_LITTER_NUM_SM_PER_TPC                   2
#define NV_SCAL_LITTER_NUM_SYSB                     0
#define NV_SCAL_LITTER_NUM_SYSC                     1
#define NV_SCAL_LITTER_NUM_SYSS                     1
#define NV_SCAL_LITTER_NUM_TPCS_PER_PES                 2
#define NV_SCAL_LITTER_NUM_TPC_PER_GPC                  6
#define NV_SCAL_LITTER_NUM_ZCULL_BANKS                  4
#define NV_SCAL_LITTER_SM_FMA32_PER_SM                    128
#define NV_UPPER_MEMORY_BIT                        36
#define NV_PGRAPH_BASE                        4194304
#define NV_PPC_IN_GPC_BASE                      12288
#define NV_PPC_IN_GPC_PRI_SHARED_INDEX                  7
#define NV_PPC_IN_GPC_SHARED_BASE                       15872
#define NV_PPC_IN_GPC_STRIDE                          512
#define NV_PRI_GPC_ADDR_WIDTH                          15
#define NV_PRI_TPC_ADDR_WIDTH                          11
#define NV_ROP_IN_GPC_BASE                      14336
#define NV_ROP_IN_GPC_PRI_SHARED_INDEX                  2
#define NV_ROP_IN_GPC_SHARED_BASE                       15360
#define NV_ROP_IN_GPC_STRIDE                          512
#define NV_ROP_PRI_BASE                       4259840
#define NV_ROP_PRI_SHARED_BASE                    4229120
#define NV_ROP_PRI_SHARED_INDEX                       -30
#define NV_ROP_PRI_STRIDE                            1024
#define NV_SMC_PRIV_BASE                         16777216
#define NV_SMC_PRIV_STRIDE                    2097152
#define NV_SMPC_PRI_BASE                              512
#define NV_SMPC_PRI_SHARED_BASE                       768
#define NV_SMPC_PRI_STRIDE                        256
#define NV_SMPC_PRI_UNIQUE_BASE                      1536
#define NV_SM_PRI_SHARED_BASE                        1664
#define NV_SM_PRI_STRIDE                              128
#define NV_SM_PRI_UNIQUE_BASE                        1792
#define NV_SYSB_PRIV_BASE                         1189888
#define NV_SYSB_PRIV_STRIDE                      2048
#define NV_SYSC_PRIV_BASE                         1191936
#define NV_SYSC_PRIV_STRIDE                      2048
#define NV_SYS_PRIV_BASE                          1187840
#define NV_SYS_PRIV_BC_BASE                   1185792
#define NV_SYS_PRIV_STRIDE                       2048
#define NV_TPC_IN_GPC_BASE                      16384
#define NV_TPC_IN_GPC_PRI_SHARED_INDEX                     -5
#define NV_TPC_IN_GPC_SHARED_BASE                        6144
#define NV_TPC_IN_GPC_STRIDE                         2048
