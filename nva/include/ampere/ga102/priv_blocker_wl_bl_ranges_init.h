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

/* ------------------------- System Includes -------------------------------- */
#ifdef LPWR_RM
    #include "ampere/ga102/dev_perf.h"
    #include "ampere/ga102/dev_nv_xve.h"
    #include "ampere/ga102/dev_master.h"
    #include "ampere/ga102/dev_therm.h"
    #include "ampere/ga102/dev_pbdma.h"
    #include "ampere/ga102/dev_nv_xve1.h"
    #include "ampere/ga102/dev_nv_xp.h"
    #include "ampere/ga102/dev_bus.h"
    #include "ampere/ga102/dev_ctrl.h"
    #include "ampere/ga102/dev_timer.h"
    #include "ampere/ga102/dev_top.h"
    #include "disp/v04_01/dev_disp.h"
    #include "ampere/ga102/dev_hdacodec.h"
    #include "ampere/ga102/dev_pwr_pri.h"
    #include "ampere/ga102/dev_fuse.h"
    #include "ampere/ga102/dev_pmgr.h"
    #include "ampere/ga102/dev_flush.h"
    #include "ampere/ga102/dev_ram.h"
    #include "ampere/ga102/dev_trim.h"
    #include "ampere/ga102/dev_xbar.h"
    #include "ampere/ga102/dev_graphics_nobundle.h"
    #include "ampere/ga102/dev_fifo.h"
    #include "ampere/ga102/dev_chiplet_pwr.h"
    #include "ampere/ga102/dev_runlist.h"
    #include "ampere/ga102/dev_chiplet_ism.h"
    #include "ampere/ga102/dev_pri_ringstation_gpc.h"
    #include "ampere/ga102/dev_smcarb.h"
#else
    #include "dev_perf.h"
    #include "dev_nv_xve.h"
    #include "dev_master.h"
    #include "dev_therm.h"
    #include "dev_pbdma.h"
    #include "dev_nv_xve1.h"
    #include "dev_nv_xp.h"
    #include "dev_bus.h"
    #include "dev_ctrl.h"
    #include "dev_timer.h"
    #include "dev_top.h"
    #include "dev_disp.h"
    #include "dev_hdacodec.h"
    #include "dev_pwr_pri.h"
    #include "dev_fuse.h"
    #include "dev_pmgr.h"
    #include "dev_flush.h"
    #include "dev_ram.h"
    #include "dev_trim.h"
    #include "dev_xbar.h"
    #include "dev_graphics_nobundle.h"
    #include "dev_fifo.h"
    #include "dev_chiplet_pwr.h"
    #include "dev_runlist.h"
    #include "dev_chiplet_ism.h"
    #include "dev_pri_ringstation_gpc.h"
    #include "dev_smcarb.h"
#endif

/* ======================================================================================= */
// Generic MS and GR Region BL/WL ranges which will be used by SEC2/GSP Priv Blocker
/* ======================================================================================= */

/* ============================================================== */
// MS Region White List Ranges for SEC2/GSP Blockers
/* ============================================================== */

// XVE & XP Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_0    DEVICE_BASE(NV_PCFG)
#define PRIV_BLOCKER_MS_WL_RANGE_END_0      DEVICE_EXTENT(NV_PCFG)
#define PRIV_BLOCKER_MS_WL_RANGE_START_1    DEVICE_BASE(NV_PCFG1)
#define PRIV_BLOCKER_MS_WL_RANGE_END_1      DEVICE_EXTENT(NV_PCFG1)
#define PRIV_BLOCKER_MS_WL_RANGE_START_2    DEVICE_BASE(NV_XP)
#define PRIV_BLOCKER_MS_WL_RANGE_END_2      DEVICE_EXTENT(NV_XP)
// Host Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_3    DEVICE_BASE(NV_PMC)
#define PRIV_BLOCKER_MS_WL_RANGE_END_3      DEVICE_EXTENT(NV_PMC)
#define PRIV_BLOCKER_MS_WL_RANGE_START_4    DEVICE_BASE(NV_PBUS)
#define PRIV_BLOCKER_MS_WL_RANGE_END_4      DEVICE_EXTENT(NV_PBUS)
#define PRIV_BLOCKER_MS_WL_RANGE_START_5    DEVICE_BASE(NV_PTIMER)
#define PRIV_BLOCKER_MS_WL_RANGE_END_5      DEVICE_EXTENT(NV_PTIMER)
#define PRIV_BLOCKER_MS_WL_RANGE_START_6    DEVICE_BASE(NV_PTOP)
#define PRIV_BLOCKER_MS_WL_RANGE_END_6      DEVICE_EXTENT(NV_PTOP)
#define PRIV_BLOCKER_MS_WL_RANGE_START_7    DEVICE_BASE(NV_CTRL)
#define PRIV_BLOCKER_MS_WL_RANGE_END_7      DEVICE_EXTENT(NV_CTRL)
// Perf Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_8    DEVICE_BASE(NV_PERF_PMMGPC)
#define PRIV_BLOCKER_MS_WL_RANGE_END_8      DEVICE_EXTENT(NV_PERF_PMMGPC)
#define PRIV_BLOCKER_MS_WL_RANGE_START_9    DEVICE_BASE(NV_PERF_PMMFBP)
#define PRIV_BLOCKER_MS_WL_RANGE_END_9      DEVICE_EXTENT(NV_PERF_PMMFBP)
#define PRIV_BLOCKER_MS_WL_RANGE_START_10   DEVICE_BASE(NV_PERF_PMMSYS)
#define PRIV_BLOCKER_MS_WL_RANGE_END_10     DEVICE_EXTENT(NV_PERF_PMMSYS)
#define PRIV_BLOCKER_MS_WL_RANGE_START_11   DEVICE_BASE(NV_PERF_PMMFBPROUTER)
#define PRIV_BLOCKER_MS_WL_RANGE_END_11     DEVICE_EXTENT(NV_PERF_PMMFBPROUTER)
#define PRIV_BLOCKER_MS_WL_RANGE_START_12   DEVICE_BASE(NV_PERF_PMMGPCROUTER)
#define PRIV_BLOCKER_MS_WL_RANGE_END_12     DEVICE_EXTENT(NV_PERF_PMMGPCROUTER)
#define PRIV_BLOCKER_MS_WL_RANGE_START_13   DEVICE_BASE(NV_PERF_PMMSYSROUTER)
#define PRIV_BLOCKER_MS_WL_RANGE_END_13     DEVICE_EXTENT(NV_PERF_PMMSYSROUTER)
// Audio Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_14   DEVICE_BASE(NV_HDACODEC)
#define PRIV_BLOCKER_MS_WL_RANGE_END_14     DEVICE_EXTENT(NV_HDACODEC)
// PMU Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_15   DEVICE_BASE(NV_PPWR)
#define PRIV_BLOCKER_MS_WL_RANGE_END_15     DEVICE_EXTENT(NV_PPWR)
// FUSE Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_16   DEVICE_BASE(NV_FUSE)
#define PRIV_BLOCKER_MS_WL_RANGE_END_16     DEVICE_EXTENT(NV_FUSE)
// PMGR Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_17   DEVICE_BASE(NV_PMGR)
#define PRIV_BLOCKER_MS_WL_RANGE_END_17     DEVICE_EXTENT(NV_PMGR)
// SEC & GSP Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_18   DEVICE_BASE(NV_PSEC)
#define PRIV_BLOCKER_MS_WL_RANGE_END_18     DEVICE_EXTENT(NV_PSEC)
#define PRIV_BLOCKER_MS_WL_RANGE_START_19   DEVICE_BASE(NV_PGSP)
#define PRIV_BLOCKER_MS_WL_RANGE_END_19     DEVICE_EXTENT(NV_PGSP)
// Display Registers
#define PRIV_BLOCKER_MS_WL_RANGE_START_20   DEVICE_BASE(NV_UDISP)
#define PRIV_BLOCKER_MS_WL_RANGE_END_20     DEVICE_EXTENT(NV_UDISP)
#define PRIV_BLOCKER_MS_WL_RANGE_START_21   DEVICE_BASE(NV_PDISP)
#define PRIV_BLOCKER_MS_WL_RANGE_END_21     DEVICE_EXTENT(NV_PDISP)

/* #define PRIV_BLOCKER_MS_WL_RANGE_START(22-31)      WHITE CYA START ADDRESS */
/* #define PRIV_BLOCKER_MS_WL_RANGE_END(22-31)        WHITE CYA END ADDRESS */

/* ============================================================== */
// Macro to init the MS Profile WL ranges in SW
/* ==============================================================  */
#define PRIV_BLOCKER_MS_PROFILE_WL_RANGES_INIT(_op_) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_0, PRIV_BLOCKER_MS_WL_RANGE_END_0) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_1, PRIV_BLOCKER_MS_WL_RANGE_END_1) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_2, PRIV_BLOCKER_MS_WL_RANGE_END_2) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_3, PRIV_BLOCKER_MS_WL_RANGE_END_3) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_4, PRIV_BLOCKER_MS_WL_RANGE_END_4) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_5, PRIV_BLOCKER_MS_WL_RANGE_END_5) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_6, PRIV_BLOCKER_MS_WL_RANGE_END_6) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_7, PRIV_BLOCKER_MS_WL_RANGE_END_7) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_8, PRIV_BLOCKER_MS_WL_RANGE_END_8) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_9, PRIV_BLOCKER_MS_WL_RANGE_END_9) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_10, PRIV_BLOCKER_MS_WL_RANGE_END_10) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_11, PRIV_BLOCKER_MS_WL_RANGE_END_11) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_12, PRIV_BLOCKER_MS_WL_RANGE_END_12) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_13, PRIV_BLOCKER_MS_WL_RANGE_END_13) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_14, PRIV_BLOCKER_MS_WL_RANGE_END_14) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_15, PRIV_BLOCKER_MS_WL_RANGE_END_15) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_16, PRIV_BLOCKER_MS_WL_RANGE_END_16) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_17, PRIV_BLOCKER_MS_WL_RANGE_END_17) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_18, PRIV_BLOCKER_MS_WL_RANGE_END_18) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_19, PRIV_BLOCKER_MS_WL_RANGE_END_19) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_20, PRIV_BLOCKER_MS_WL_RANGE_END_20) \
_op_(PRIV_BLOCKER_MS_WL_RANGE_START_21, PRIV_BLOCKER_MS_WL_RANGE_END_21)
//_op_(PRIV_BLOCKER_MS_WL_RANGE_START_22, PRIV_BLOCKER_MS_WL_RANGE_END_22)


/* ============================================================== */
// MS Region Black List Ranges for SEC2/GSP Blockers
/* ==============================================================  */
#define PRIV_BLOCKER_MS_BL_RANGE_START_0    NV_PBUS_BAR0_WINDOW
#define PRIV_BLOCKER_MS_BL_RANGE_END_0      NV_PBUS_BAR0_WINDOW
#define PRIV_BLOCKER_MS_BL_RANGE_START_1    NV_PBUS_BAR1_BLOCK
#define PRIV_BLOCKER_MS_BL_RANGE_END_1      NV_PBUS_BAR1_BLOCK
#define PRIV_BLOCKER_MS_BL_RANGE_START_2    NV_PBUS_BAR2_BLOCK
#define PRIV_BLOCKER_MS_BL_RANGE_END_2      NV_PBUS_BAR2_BLOCK
#define PRIV_BLOCKER_MS_BL_RANGE_START_3    NV_PBUS_FLUSH_BIND_CTL
#define PRIV_BLOCKER_MS_BL_RANGE_END_3      NV_PBUS_FLUSH_BIND_CTL
#define PRIV_BLOCKER_MS_BL_RANGE_START_4    DEVICE_BASE(NV_RUNLIST_GLOBAL_PRI_RANGE_0)
#define PRIV_BLOCKER_MS_BL_RANGE_END_4      DEVICE_EXTENT(NV_RUNLIST_GLOBAL_PRI_RANGE_0)
#define PRIV_BLOCKER_MS_BL_RANGE_START_5    DEVICE_BASE(NV_CHRAM_GLOBAL_PRI_RANGE_0)
#define PRIV_BLOCKER_MS_BL_RANGE_END_5      DEVICE_EXTENT(NV_CHRAM_GLOBAL_PRI_RANGE_0)
/* Note: NV_PPBDMA will need to be replaced with NV_PBDMA_GLOBAL_PRI_RANGE_0 */
/* (this will need to happen when NV_PPBDMA is replaced with 0-based NV_PBDMA) */
#define PRIV_BLOCKER_MS_BL_RANGE_START_6    DEVICE_BASE(NV_PPBDMA)
#define PRIV_BLOCKER_MS_BL_RANGE_END_6      DEVICE_EXTENT(NV_PPBDMA)
#define PRIV_BLOCKER_MS_BL_RANGE_START_7    DEVICE_BASE(NV_UFLUSH)
#define PRIV_BLOCKER_MS_BL_RANGE_END_7      DEVICE_EXTENT(NV_UFLUSH)
#define PRIV_BLOCKER_MS_BL_RANGE_START_8    DEVICE_BASE(NV_PRAMIN)
#define PRIV_BLOCKER_MS_BL_RANGE_END_8      DEVICE_EXTENT(NV_PRAMIN)
#define PRIV_BLOCKER_MS_BL_RANGE_START_9    DEVICE_BASE(NV_PDISP_VGA)
#define PRIV_BLOCKER_MS_BL_RANGE_END_9      DEVICE_EXTENT(NV_PDISP_VGA)
/* #define PRIV_BLOCKER_MS_BL_RANGE_START(10-31)      BLACKLIST CYA START ADDRESS */
/* #define PRIV_BLOCKER_MS_BL_RANGE_END(10-31)        BLACKLIST CYA END ADDRESS */
/* SW needs code to program  NV_PPWR_PMU_MUTEX(RM_PMU_MUTEX_ID_GPIO) to PRIV_BLOCKER_MS_BL_RANGE_END(24) if PSI enabled */

/* ============================================================== */
// Macro to init the MS Profile BL ranges in SW
/* ==============================================================  */
#define PRIV_BLOCKER_MS_PROFILE_BL_RANGES_INIT(_op_) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_0, PRIV_BLOCKER_MS_BL_RANGE_END_0) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_1, PRIV_BLOCKER_MS_BL_RANGE_END_1) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_2, PRIV_BLOCKER_MS_BL_RANGE_END_2) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_3, PRIV_BLOCKER_MS_BL_RANGE_END_3) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_4, PRIV_BLOCKER_MS_BL_RANGE_END_4) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_5, PRIV_BLOCKER_MS_BL_RANGE_END_5) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_6, PRIV_BLOCKER_MS_BL_RANGE_END_6) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_7, PRIV_BLOCKER_MS_BL_RANGE_END_7) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_8, PRIV_BLOCKER_MS_BL_RANGE_END_8) \
_op_(PRIV_BLOCKER_MS_BL_RANGE_START_9, PRIV_BLOCKER_MS_BL_RANGE_END_9)


/* ============================================================== */
// GR Region White List Ranges for SEC2/GSP Blockers
/* ==============================================================  */
#define PRIV_BLOCKER_GR_WL_RANGE_START_0    0x00000000
#define PRIV_BLOCKER_GR_WL_RANGE_END_0      0xffffffff

/* ============================================================== */
// Macro to init the GR Profile WL ranges in SW
/* ==============================================================  */
#define PRIV_BLOCKER_GR_PROFILE_WL_RANGES_INIT(_op_) \
_op_(PRIV_BLOCKER_GR_WL_RANGE_START_0, PRIV_BLOCKER_GR_WL_RANGE_END_0)

/* ============================================================== */
// GR Region Black List Ranges for SEC2/GSP Blockers
/* ==============================================================  */
#define PRIV_BLOCKER_GR_BL_RANGE_START_0    DEVICE_BASE(NV_PGRAPH)
#define PRIV_BLOCKER_GR_BL_RANGE_END_0      DEVICE_EXTENT(NV_PGRAPH)
#define PRIV_BLOCKER_GR_BL_RANGE_START_1    DEVICE_BASE(NV_PTRIM_GPC)
#define PRIV_BLOCKER_GR_BL_RANGE_END_1      DEVICE_EXTENT(NV_PTRIM_GPC)
#define PRIV_BLOCKER_GR_BL_RANGE_START_2    DEVICE_BASE(NV_PTRIM_GPC_BCAST)
#define PRIV_BLOCKER_GR_BL_RANGE_END_2      DEVICE_EXTENT(NV_PTRIM_GPC_BCAST)
#define PRIV_BLOCKER_GR_BL_RANGE_START_3    DEVICE_BASE(NV_PCHIPLET_PWR)
#define PRIV_BLOCKER_GR_BL_RANGE_END_3      DEVICE_EXTENT(NV_PCHIPLET_PWR)
#define PRIV_BLOCKER_GR_BL_RANGE_START_4    DEVICE_BASE(NV_PERF_PMMGPC)
#define PRIV_BLOCKER_GR_BL_RANGE_END_4      DEVICE_EXTENT(NV_PERF_PMMGPC) //Repeated
#define PRIV_BLOCKER_GR_BL_RANGE_START_5    DEVICE_BASE(NV_PERF_PMMGPC)
#define PRIV_BLOCKER_GR_BL_RANGE_END_5      DEVICE_EXTENT(NV_PERF_PMMGPC)
#define PRIV_BLOCKER_GR_BL_RANGE_START_6    DEVICE_BASE(NV_XBAR_MXBAR_PRI_GPCS_GNIC)
#define PRIV_BLOCKER_GR_BL_RANGE_END_6      DEVICE_EXTENT(NV_XBAR_MXBAR_PRI_GPCS_GNIC)
#define PRIV_BLOCKER_GR_BL_RANGE_START_7    DEVICE_BASE(NV_XBAR_MXBAR_PRI_GPC0_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_7      DEVICE_EXTENT(NV_XBAR_MXBAR_PRI_GPC0_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_8    DEVICE_BASE(NV_XBAR_MXBAR_PRI_GPC1_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_8      DEVICE_EXTENT(NV_XBAR_MXBAR_PRI_GPC1_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_9    DEVICE_BASE(NV_XBAR_MXBAR_PRI_GPC2_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_9      DEVICE_EXTENT(NV_XBAR_MXBAR_PRI_GPC2_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_10   DEVICE_BASE(NV_XBAR_MXBAR_PRI_GPC3_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_10     DEVICE_EXTENT(NV_XBAR_MXBAR_PRI_GPC3_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_11   DEVICE_BASE(NV_XBAR_MXBAR_PRI_GPC4_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_11     DEVICE_EXTENT(NV_XBAR_MXBAR_PRI_GPC4_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_12   DEVICE_BASE(NV_XBAR_MXBAR_PRI_GPC5_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_12     DEVICE_EXTENT(NV_XBAR_MXBAR_PRI_GPC5_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_13   DEVICE_BASE(NV_XBAR_MXBAR_PRI_GPC6_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_13     DEVICE_EXTENT(NV_XBAR_MXBAR_PRI_GPC6_GNIC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_14   DEVICE_BASE(NV_PCHIPLET_ISM_GPC)
#define PRIV_BLOCKER_GR_BL_RANGE_END_14     DEVICE_EXTENT(NV_PCHIPLET_ISM_GPC)
#define PRIV_BLOCKER_GR_BL_RANGE_START_15   DEVICE_BASE(NV_PCHIPLET_ISM_GPCS)
#define PRIV_BLOCKER_GR_BL_RANGE_END_15     DEVICE_EXTENT(NV_PCHIPLET_ISM_GPCS)
#define PRIV_BLOCKER_GR_BL_RANGE_START_16   DEVICE_BASE(NV_PPRIV_GPC_GPC)
#define PRIV_BLOCKER_GR_BL_RANGE_END_16     DEVICE_EXTENT(NV_PPRIV_GPC_GPC)
#define PRIV_BLOCKER_GR_BL_RANGE_START_17   DEVICE_BASE(NV_PPRIV_GPC_GPCS)
#define PRIV_BLOCKER_GR_BL_RANGE_END_17     DEVICE_EXTENT(NV_PPRIV_GPC_GPCS)
#define PRIV_BLOCKER_GR_BL_RANGE_START_18   DEVICE_BASE(NV_PERF_PMMGPC_GPC0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_18     DEVICE_EXTENT(NV_PERF_PMMGPC_GPC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_19   DEVICE_BASE(NV_PERF_PMMGPC_GPC0) //Repeated
#define PRIV_BLOCKER_GR_BL_RANGE_END_19     DEVICE_EXTENT(NV_PERF_PMMGPC_GPC0)
#define PRIV_BLOCKER_GR_BL_RANGE_START_20   DEVICE_BASE(NV_PERF_PMMGPC_GPC1)
#define PRIV_BLOCKER_GR_BL_RANGE_END_20     DEVICE_EXTENT(NV_PERF_PMMGPC_GPC1)
#define PRIV_BLOCKER_GR_BL_RANGE_START_21   DEVICE_BASE(NV_PERF_PMMGPC_GPC2)
#define PRIV_BLOCKER_GR_BL_RANGE_END_21     DEVICE_EXTENT(NV_PERF_PMMGPC_GPC2)
#define PRIV_BLOCKER_GR_BL_RANGE_START_22   DEVICE_BASE(NV_PERF_PMMGPC_GPC3)
#define PRIV_BLOCKER_GR_BL_RANGE_END_22     DEVICE_EXTENT(NV_PERF_PMMGPC_GPC3)
#define PRIV_BLOCKER_GR_BL_RANGE_START_23   DEVICE_BASE(NV_PERF_PMMGPC_GPC4)
#define PRIV_BLOCKER_GR_BL_RANGE_END_23     DEVICE_EXTENT(NV_PERF_PMMGPC_GPC4)
#define PRIV_BLOCKER_GR_BL_RANGE_START_24   DEVICE_BASE(NV_PERF_PMMGPC_GPC5)
#define PRIV_BLOCKER_GR_BL_RANGE_END_24     DEVICE_EXTENT(NV_PERF_PMMGPC_GPC5)
#define PRIV_BLOCKER_GR_BL_RANGE_START_25   DEVICE_BASE(NV_PERF_PMMGPC_GPC6)
#define PRIV_BLOCKER_GR_BL_RANGE_END_25     DEVICE_EXTENT(NV_PERF_PMMGPC_GPC6)
#define PRIV_BLOCKER_GR_BL_RANGE_START_26   DEVICE_BASE(NV_PERF_PMMGPC_GPCS)
#define PRIV_BLOCKER_GR_BL_RANGE_END_26     DEVICE_EXTENT(NV_PERF_PMMGPC_GPCS)
#define PRIV_BLOCKER_GR_BL_RANGE_START_27   NV_PSMCARB_SMC_PARTITION_GPC_MAP(0)
#define PRIV_BLOCKER_GR_BL_RANGE_END_27     NV_PSMCARB_SMC_PARTITION_GPC_MAP(6)

/* ============================================================== */
// Macro to init the GR Profile BL ranges in SW
/* ==============================================================  */
#define PRIV_BLOCKER_GR_PROFILE_BL_RANGES_INIT(_op_) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_0, PRIV_BLOCKER_GR_BL_RANGE_END_0) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_1, PRIV_BLOCKER_GR_BL_RANGE_END_1) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_2, PRIV_BLOCKER_GR_BL_RANGE_END_2) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_3, PRIV_BLOCKER_GR_BL_RANGE_END_3) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_4, PRIV_BLOCKER_GR_BL_RANGE_END_4) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_5, PRIV_BLOCKER_GR_BL_RANGE_END_5) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_6, PRIV_BLOCKER_GR_BL_RANGE_END_6) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_7, PRIV_BLOCKER_GR_BL_RANGE_END_7) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_8, PRIV_BLOCKER_GR_BL_RANGE_END_8) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_9, PRIV_BLOCKER_GR_BL_RANGE_END_9) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_10, PRIV_BLOCKER_GR_BL_RANGE_END_10) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_11, PRIV_BLOCKER_GR_BL_RANGE_END_11) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_12, PRIV_BLOCKER_GR_BL_RANGE_END_12) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_13, PRIV_BLOCKER_GR_BL_RANGE_END_13) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_14, PRIV_BLOCKER_GR_BL_RANGE_END_14) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_15, PRIV_BLOCKER_GR_BL_RANGE_END_15) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_16, PRIV_BLOCKER_GR_BL_RANGE_END_16) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_17, PRIV_BLOCKER_GR_BL_RANGE_END_17) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_18, PRIV_BLOCKER_GR_BL_RANGE_END_18) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_19, PRIV_BLOCKER_GR_BL_RANGE_END_19) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_20, PRIV_BLOCKER_GR_BL_RANGE_END_20) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_21, PRIV_BLOCKER_GR_BL_RANGE_END_21) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_22, PRIV_BLOCKER_GR_BL_RANGE_END_22) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_23, PRIV_BLOCKER_GR_BL_RANGE_END_23) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_24, PRIV_BLOCKER_GR_BL_RANGE_END_24) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_25, PRIV_BLOCKER_GR_BL_RANGE_END_25) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_26, PRIV_BLOCKER_GR_BL_RANGE_END_26) \
_op_(PRIV_BLOCKER_GR_BL_RANGE_START_27, PRIV_BLOCKER_GR_BL_RANGE_END_27)


/* ======================================================================================= */
// MS and GR Region BL/WL ranges which will be used by XVE BAR Blocker
/* ======================================================================================= */

/* ============================================================== */
// MS Region White List Ranges for XVE BAR Blocker
/* ==============================================================  */
/* #define PRIV_BLOCKER_XVE_MS_WL_RANGE_START(9-31)      WHITELIST CYA START ADDRESS */
/* #define PRIV_BLOCKER_XVE_MS_WL_RANGE_END(9-31)        WHITELIST CYA END ADDRESS */

/* ============================================================== */
// Macro to init the MS Profile WL ranges in SW for XVE BAR Blocker
/* ==============================================================  */
#define PRIV_BLOCKER_XVE_MS_PROFILE_WL_RANGES_INIT(_op_) \
_op_(PRIV_BLOCKER_XVE_MS_WL_RANGE_START_0, PRIV_BLOCKER_XVE_MS_WL_RANGE_END_0)

/* ============================================================== */
// MS Region Black List Ranges for XVE Bar Blocker
/* ==============================================================  */
#define PRIV_BLOCKER_XVE_MS_BL_RANGE_START_0    NV_PPWR_PMU_MUTEX(MUTEX_LOG_TO_PHY_ID(NV_MUTEX_ID_GPIO))
#define PRIV_BLOCKER_XVE_MS_BL_RANGE_END_0      NV_PPWR_PMU_MUTEX(MUTEX_LOG_TO_PHY_ID(NV_MUTEX_ID_GPIO))

/* ============================================================== */
// Macro to init the MS Profile BL ranges in SW for XVE BAR Blocker
/* ==============================================================  */
#define PRIV_BLOCKER_XVE_MS_PROFILE_BL_RANGES_INIT(_op_) \
_op_(PRIV_BLOCKER_XVE_MS_BL_RANGE_START_0, PRIV_BLOCKER_XVE_MS_BL_RANGE_END_0)

/* ============================================================== */
// GR Region Black List Ranges for XVE Bar Blocker
/* ==============================================================  */
#define PRIV_BLOCKER_XVE_GR_BL_RANGE_START_0    NV_PSMCARB_SMC_PARTITION_GPC_MAP(0)
#define PRIV_BLOCKER_XVE_GR_BL_RANGE_END_0      NV_PSMCARB_SMC_PARTITION_GPC_MAP(6)

/* ============================================================== */
// Macro to init the GR Profile BL ranges in SW for XVE BAR Blocker
/* ==============================================================  */
#define PRIV_BLOCKER_XVE_GR_PROFILE_BL_RANGES_INIT(_op_) \
_op_(PRIV_BLOCKER_XVE_GR_BL_RANGE_START_0, PRIV_BLOCKER_XVE_GR_BL_RANGE_END_0)


/* ============================================================== */
// PRIV BLOCKER RANGES for SW BLOCKER - Bug 2500177
/* ==============================================================  */
#define PRIV_SW_BLOCKER_GR_BL_RANGE_START_0 	DEVICE_BASE(NV_PCHIPLET_PWR_GPC)                    //1. 0x0010C000
#define PRIV_SW_BLOCKER_GR_BL_RANGE_END_0 		DEVICE_EXTENT(NV_PCHIPLET_PWR_GPCS)                 //1. 0x0010e0ff
#define PRIV_SW_BLOCKER_GR_BL_RANGE_START_1 	DEVICE_BASE(NV_PPRIV_GPC_GPCS)                      //2. 0x00120800
#define PRIV_SW_BLOCKER_GR_BL_RANGE_END_1 		DEVICE_EXTENT(NV_PPRIV_GPC)                         //2. 0x00127fff
#define PRIV_SW_BLOCKER_GR_BL_RANGE_START_2 	DEVICE_BASE(NV_PTRIM_GPC_BCAST)                     //3. 0x00132800
#define PRIV_SW_BLOCKER_GR_BL_RANGE_END_2 		DEVICE_EXTENT(NV_PCHIPLET_ISM_GPCS)                 //3. 0x001ff1ff
#define PRIV_SW_BLOCKER_GR_BL_RANGE_START_3 	DEVICE_BASE(NV_PERF_PMMGPC_GPC0ROUTER)              //4. 0x00244000
#define PRIV_SW_BLOCKER_GR_BL_RANGE_END_3 		DEVICE_EXTENT(NV_PERF_PMMGPC_GPCS)                  //4. 0x0027BFFF
#define PRIV_SW_BLOCKER_GR_BL_RANGE_START_4 	DEVICE_BASE(NV_PGRAPH)                              //5. 0x00400000
#define PRIV_SW_BLOCKER_GR_BL_RANGE_END_4 		DEVICE_EXTENT(NV_PGRAPH)                            //5. 0x005FFFFF
#define PRIV_SW_BLOCKER_GR_BL_RANGE_START_5 	0x01018300                                          //6. Placeholder for 0x01018300
#define PRIV_SW_BLOCKER_GR_BL_RANGE_END_5 		0x011BEFFF                                          //6. Placeholder for 0x011BEFFF
#define PRIV_SW_BLOCKER_GR_BL_RANGE_START_6 	NV_PSMCARB_SMC_PARTITION_GPC_MAP(0)                 //7. bug 200673478
#define PRIV_SW_BLOCKER_GR_BL_RANGE_END_6 		NV_PSMCARB_SMC_PARTITION_GPC_MAP(6)


/* ============================================================== */
// Macro to init PRIV BLOCKER RANGES for SW BLOCKER - Bug 2500177
/* ============================================================== */
#define PRIV_SW_BLOCKER_GR_PROFILE_BL_RANGES_INIT(_op_) \
_op_(PRIV_SW_BLOCKER_GR_BL_RANGE_START_0, PRIV_SW_BLOCKER_GR_BL_RANGE_END_0) \
_op_(PRIV_SW_BLOCKER_GR_BL_RANGE_START_1, PRIV_SW_BLOCKER_GR_BL_RANGE_END_1) \
_op_(PRIV_SW_BLOCKER_GR_BL_RANGE_START_2, PRIV_SW_BLOCKER_GR_BL_RANGE_END_2) \
_op_(PRIV_SW_BLOCKER_GR_BL_RANGE_START_3, PRIV_SW_BLOCKER_GR_BL_RANGE_END_3) \
_op_(PRIV_SW_BLOCKER_GR_BL_RANGE_START_4, PRIV_SW_BLOCKER_GR_BL_RANGE_END_4) \
_op_(PRIV_SW_BLOCKER_GR_BL_RANGE_START_5, PRIV_SW_BLOCKER_GR_BL_RANGE_END_5) \
_op_(PRIV_SW_BLOCKER_GR_BL_RANGE_START_6, PRIV_SW_BLOCKER_GR_BL_RANGE_END_6)
