/* _NVRM_COPYRIGHT_BEGIN_
 *
 * Copyright 2003-2016 by NVIDIA Corporation.  All rights reserved.  All
 * information contained herein is proprietary and confidential to NVIDIA
 * Corporation.  Any use, reproduction, or disclosure without the written
 * permission of NVIDIA Corporation is prohibited.
 *
 * _NVRM_COPYRIGHT_END_
 */

#ifndef __ga102_nvlinkip_discovery_h__
#define __ga102_nvlinkip_discovery_h__
/* This file is autogenerated.  Do not edit */
#define NV_NVLINKIP_DISCOVERY_COMMON                     /* R--4P */
#define NV_NVLINKIP_DISCOVERY_COMMON_ENTRY                 1:0         /* R-EVF */
#define NV_NVLINKIP_DISCOVERY_COMMON_ENTRY_INVALID         0x00000000   /* R-E-V */
#define NV_NVLINKIP_DISCOVERY_COMMON_ENTRY_ENUM            0x00000001   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_ENTRY_DATA1           0x00000002   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_ENTRY_DATA2           0x00000003   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_CONTENTS              30:2         /* R-EVF */
#define NV_NVLINKIP_DISCOVERY_COMMON_CONTENTS_INIT         0x00000000   /* R-E-V */
#define NV_NVLINKIP_DISCOVERY_COMMON_CHAIN                 31:31        /* R-EVF */
#define NV_NVLINKIP_DISCOVERY_COMMON_CHAIN_DISABLE      0x00000000   /* R-E-V */
#define NV_NVLINKIP_DISCOVERY_COMMON_CHAIN_ENABLE       0x00000001   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE                       7:2   /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_INVALID                   0x0   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_IOCTRL                    0x1   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLTL                  0x2   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLINK                    0x3   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_MINION                    0x4   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLIPT                    0x5   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLTLC                    0x6   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_IOCTRLMIF                  0x7   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_DLPL_MULTICAST            0x8   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLTLC_MULTICAST          0x9   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_IOCTRLMIF_MULTICAST       0xA   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_DLPL              0xB   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_SIOCTRL                    0xC   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_TIOCTRL                    0xD   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_SIOCTRL_PERFMON            0xE   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLIPT_SYS_PERFMON        0xF   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_TX_PERFMON_MULTICAST      0x10  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_RX_PERFMON_MULTICAST      0x11  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_TX_PERFMON                0x12  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_RX_PERFMON                  0x13  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLW                    0x14  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLW_PERFMON            0x15  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLDL              0x16  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLDL_MULTICAST           0x17  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_SYS_PERFMON               0x18  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_SYS_PERFMON_MULTICAST     0x19  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLIPT_LNK            0x1A  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_NVLIPT_LNK_MULTICAST       0x1B  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DEVICE_PLL                    0x1C  /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_ID                      15:8  /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_RESERVED                  19:16 /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_VERSION                  30:20 /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_VERSION_NVLINK10              0x1   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_VERSION_NVLINK20              0x2   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_VERSION_3                      0x3   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_VERSION_NVLINK22              0x4   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_VERSION_NVLINK30              0x5   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_VERSION_NVLINK31              0x6   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_VERSION_NVLINK40              0x7   /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA1_RESERVED          30:12  /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA1_IOCTRL_LENGTH      30:12  /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA1_RESERVED2                  11:2  /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE                  30:26  /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_INVALID          0x0    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_PLLCONTROL      0x1    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_RESETREG      0x2    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_INTRREG          0x3    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_DISCOVERY      0x4    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_UNICAST          0x5    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_BROADCAST         0x6    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_MULTICAST0        0x7    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_MULTICAST1        0x8    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_TYPE_MULTICAST2        0x9    /* R---V */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_ADDR                  25:2   /* R--UF */
#define NV_NVLINKIP_DISCOVERY_COMMON_DATA2_ADDR_ALIGN                2   /*       */
#endif // __ga102_nvlinkip_discovery_h__
