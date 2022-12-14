/* _NVRM_COPYRIGHT_BEGIN_
 *
 * Copyright 2003-2016 by NVIDIA Corporation.  All rights reserved.  All
 * information contained herein is proprietary and confidential to NVIDIA
 * Corporation.  Any use, reproduction, or disclosure without the written
 * permission of NVIDIA Corporation is prohibited.
 *
 * _NVRM_COPYRIGHT_END_
 */

#ifndef __ga102_dev_ext_devices_h__
#define __ga102_dev_ext_devices_h__
/* This file is autogenerated.  Do not edit */
#define NV_PEXTDEV                            0x00101FFF:0x00101000 /* RW--D */
#define NV_PROM                               0x003FFFFF:0x00300000 /* R---D */
#define NV_PROM_2                             0x00109FFF:0x00109000 /* R---D */
#define NV_PEXTDEV_BOOT_0                                0x00101000 /* RW-4R */
#define NV_PEXTDEV_BOOT_0_STRAP_GV_WIDTH                        0:0 /* R-IVF */
#define NV_PEXTDEV_BOOT_0_STRAP_GV_WIDTH_WIDE            0x00000000 /* R-I-V */
#define NV_PEXTDEV_BOOT_0_STRAP_GV_WIDTH_NARROW          0x00000001 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_RAMCFG                          5:1 /* R-IVF */
#define NV_PEXTDEV_BOOT_0_STRAP_RAMCFG_INIT              0x00000000 /* R-I-V */
#define NV_PEXTDEV_BOOT_0_STRAP_CRYSTAL                         6:6 /* R-IVF */
#define NV_PEXTDEV_BOOT_0_STRAP_CRYSTAL_INIT             0x00000000 /* R-I-V */
#define NV_PEXTDEV_BOOT_0_STRAP_CRYSTAL_27000K           0x00000000 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_CRYSTAL_14318K           0x00000001 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_CRYSTAL_25000K           0x00000001 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE                          9:7 /* R-IVF */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE_NTSC_M            0x00000000 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE_NTSC_J            0x00000001 /* R-I-V */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE_PAL_M             0x00000002 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE_PAL_N             0x00000003 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE_PAL_CN            0x00000004 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE_PAL_BDGHI         0x00000005 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE_RESERVED0         0x00000006 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_TVMODE_RESERVED1         0x00000007 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_13_10                   13:10 /* C--VF */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_13_10_VAL          0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_17_14                   17:14 /* C--VF */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_17_14_VAL          0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_21_18                   21:18 /* C--VF */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_21_18_VAL          0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_0_STRAP_ROMTYPE                       23:22 /* R-IVF */
#define NV_PEXTDEV_BOOT_0_STRAP_ROMTYPE_PARALLEL         0x00000000 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_ROMTYPE_SERIAL_AT25F     0x00000001 /* R-I-V */
#define NV_PEXTDEV_BOOT_0_STRAP_ROMTYPE_SERIAL_SST45VF   0x00000002 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_ROMTYPE_RESERVED         0x00000003 /* R---V */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_27_24                   27:24 /* C--VF */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_27_24_VAL          0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_30_28                   30:28 /* C--VF */
#define NV_PEXTDEV_BOOT_0_STRAP_DUMMY_30_28_VAL          0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_0_STRAP_OVERWRITE                     31:31 /* RWIVF */
#define NV_PEXTDEV_BOOT_0_STRAP_OVERWRITE_DISABLED       0x00000000 /* RWI-V */
#define NV_PEXTDEV_BOOT_0_STRAP_OVERWRITE_ENABLED        0x00000001 /* RW--V */
#define NV_PEXTDEV_BOOT_0_STRAP                                30:0 /* R--VF */
#define NV_PEXTDEV_NEW_BOOT_0_STRAP                      0x00101000 /* RW-4R */
#define NV_PEXTDEV_NEW_BOOT_0_STRAP_VALUE                      30:0 /* RW-VF */
#define NV_PEXTDEV_NEW_BOOT_0_STRAP_OVERWRITE                 31:31 /* RWIVF */
#define NV_PEXTDEV_NEW_BOOT_0_STRAP_OVERWRITE_DISABLED   0x00000000 /* RWI-V */
#define NV_PEXTDEV_NEW_BOOT_0_STRAP_OVERWRITE_ENABLED    0x00000001 /* RW--V */
#define NV_PEXTDEV_BOOT_3                                0x0010100C /* RW-4R */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DUMMY_0_4                     4:0  /* C--VF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DUMMY_0_4_VAL          0x00000000  /* C---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DUMMY_5_7                    7:5  /* C--VF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DUMMY_5_7_VAL          0x00000000  /* C---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_SUBSYSTEM_USER                8:8 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_SUBSYSTEM_USER_DISABLED 0x00000000 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_SUBSYSTEM_USER_ENABLED 0x00000001 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BOARD                         9:9 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BOARD_0                0x00000000 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BOARD_1                0x00000001 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DUMMY_10_11                 11:10 /* C--VF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DUMMY_10_11_VAL        0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_MIO_EN_33V_0                12:12 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_MIO_EN_33V_0_DISABLED  0x00000000 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_MIO_EN_33V_0_ENABLED   0x00000001 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_MIO_EN_33V_1                13:13 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_MIO_EN_33V_1_DISABLED  0x00000000 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_MIO_EN_33V_1_ENABLED   0x00000001 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DUMMY_14_15                15:14 /* C--VF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DUMMY_14_15_VAL        0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_PCI_IOBAR                   16:16 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_PCI_IOBAR_DISABLE      0x00000000 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_PCI_IOBAR_ENABLE       0x00000001 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02                 19:17 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02_DISABLED   0x00000000 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02_2x         0x00000001 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02_4x         0x00000002 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02_8x         0x00000003 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02_16x        0x00000004 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02_32x        0x00000005 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02_64x        0x00000006 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR02_128x       0x00000007 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1                  22:20 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1_DISABLED    0x00000000 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1_2x          0x00000001 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1_4x          0x00000002 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1_8x          0x00000003 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1_16x         0x00000004 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1_32x         0x00000005 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1_64x         0x00000006 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BLOAT_BAR1_128x        0x00000007 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BAR2_SIZE                   23:23 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BAR2_SIZE_32MB         0x00000000 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_BAR2_SIZE_16MB         0x00000001 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_DUMMY_24_24                   24:24 /* C--VF */
#define NV_PEXTDEV_BOOT_3_STRAP_DUMMY_24_24_VAL          0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DP_PLL_VDD_33V              25:25 /* R-IVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DP_PLL_VDD_33V_USE18V  0x00000000 /* R---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_DP_PLL_VDD_33V_USE33V  0x00000001 /* R-I-V */
#define NV_PEXTDEV_BOOT_3_STRAP_DUMMY_30_26                   30:26 /* C--VF */
#define NV_PEXTDEV_BOOT_3_STRAP_DUMMY_30_26_VAL          0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_OVERWRITE                   31:31 /* RWIVF */
#define NV_PEXTDEV_BOOT_3_STRAP_1_OVERWRITE_DISABLED     0x00000000 /* RWI-V */
#define NV_PEXTDEV_BOOT_3_STRAP_1_OVERWRITE_ENABLED      0x00000001 /* RW--V */
#define NV_PEXTDEV_BOOT_3_STRAP_1                              30:0 /* R--VF */
#define NV_PEXTDEV_NEW_BOOT_3                            0x0010100C /* RW-4R */
#define NV_PEXTDEV_NEW_BOOT_3_STRAP_1_VALUE                    30:0 /* RWIVF */
#define NV_PEXTDEV_NEW_BOOT_3_STRAP_1_VALUE_ZERO         0x00000000 /* RWI-V */
#define NV_PEXTDEV_NEW_BOOT_3_STRAP_1_OVERWRITE               31:31 /* RWIVF */
#define NV_PEXTDEV_NEW_BOOT_3_STRAP_1_OVERWRITE_DISABLED 0x00000000 /* RWI-V */
#define NV_PEXTDEV_NEW_BOOT_3_STRAP_1_OVERWRITE_ENABLED  0x00000001 /* RW--V */
#define NV_PEXTDEV_BOOT_6                                0x00101034 /* RW-4R */
#define NV_PEXTDEV_BOOT_6_STRAP_2_DUMMY_0_30                   30:0 /* C--VF */
#define NV_PEXTDEV_BOOT_6_STRAP_2_DUMMY_0_30_VAL         0x00000000 /* C---V */
#define NV_PEXTDEV_BOOT_6_STRAP_2_OVERWRITE                   31:31 /* RWIVF */
#define NV_PEXTDEV_BOOT_6_STRAP_2_OVERWRITE_DISABLED     0x00000000 /* RWI-V */
#define NV_PEXTDEV_BOOT_6_STRAP_2_OVERWRITE_ENABLED      0x00000001 /* RW--V */
#define NV_PEXTDEV_BOOT_6_STRAP_2                              30:0 /* R--VF */
#define NV_PEXTDEV_NEW_BOOT_6                            0x00101034 /* RW-4R */
#define NV_PEXTDEV_NEW_BOOT_6_STRAP_2_VALUE                    30:0 /* RWIVF */
#define NV_PEXTDEV_NEW_BOOT_6_STRAP_2_VALUE_ZERO         0x00000000 /* RWI-V */
#define NV_PEXTDEV_NEW_BOOT_6_STRAP_2_OVERWRITE               31:31 /* RWIVF */
#define NV_PEXTDEV_NEW_BOOT_6_STRAP_2_OVERWRITE_DISABLED 0x00000000 /* RWI-V */
#define NV_PEXTDEV_NEW_BOOT_6_STRAP_2_OVERWRITE_ENABLED  0x00000001 /* RW--V */
#define NV_PROM_DATA(i)                            (0x00300000+(i)) /* R--1A */
#define NV_PROM_DATA__SIZE_1                                1048576 /*       */
#define NV_PROM_DATA_VALUE                                      7:0 /* R--VF */
#define NV_PROM_2_DATA(i)                          (0x00109000+(i)) /* R--1A */
#define NV_PROM_2_DATA__SIZE_1                                 4096 /*       */
#define NV_PROM_2_DATA_VALUE                                    7:0 /* R--VF */
#endif // __ga102_dev_ext_devices_h__
