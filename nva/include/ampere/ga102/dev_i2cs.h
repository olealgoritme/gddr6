/* _NVRM_COPYRIGHT_BEGIN_
 *
 * Copyright 2003-2016 by NVIDIA Corporation.  All rights reserved.  All
 * information contained herein is proprietary and confidential to NVIDIA
 * Corporation.  Any use, reproduction, or disclosure without the written
 * permission of NVIDIA Corporation is prohibited.
 *
 * _NVRM_COPYRIGHT_END_
 */

#ifndef __ga102_dev_i2cs_h__
#define __ga102_dev_i2cs_h__
/* This file is autogenerated.  Do not edit */
#define NV_NVI2CS_SENSOR_00                                   0x00000000 /* R-I1R */
#define NV_NVI2CS_SENSOR_00_RLTS                                     7:0 /* R-IUF */
#define NV_NVI2CS_SENSOR_00_RLTS_MIN                          0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_00_RLTS_MAX                          0x000000ff /* R---V */
#define NV_NVI2CS_SENSOR_01                                   0x00000001 /* R-I1R */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_0                            0:0 /* R-IVF */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_0_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_0_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_1                            1:1 /* R-IVF */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_1_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_1_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_2                            2:2 /* R-IVF */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_2_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_2_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_3                            3:3 /* R-IVF */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_3_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_3_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_4                            4:4 /* R-IVF */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_4_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_4_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_5                            5:5 /* R-IVF */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_5_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_5_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_6                            6:6 /* R-IVF */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_6_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_6_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_7                            7:7 /* R-IVF */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_7_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_01_RSL_THERMAL_7_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_02                                   0x00000002 /* R-I1R */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_8                            0:0 /* R-IVF */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_8_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_8_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_9                            1:1 /* R-IVF */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_9_NOT_PENDING         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_9_PENDING             0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_10                           2:2 /* R-IVF */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_10_NOT_PENDING        0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_10_PENDING            0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_11                           3:3 /* R-IVF */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_11_NOT_PENDING        0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_02_RSL_THERMAL_11_PENDING            0x00000001 /* R---V */
#define NV_NVI2CS_SENSOR_03                                   0x00000003 /* RWI1R */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_0_EN                         0:0 /* RWIVF */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_0_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_0_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_1_EN                         1:1 /* RWIVF */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_1_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_1_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_2_EN                         2:2 /* RWIVF */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_2_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_2_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_3_EN                         3:3 /* RWIVF */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_3_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_3_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_4_EN                         4:4 /* RWIVF */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_4_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_4_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_5_EN                         5:5 /* RWIVF */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_5_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_5_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_6_EN                         6:6 /* RWIVF */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_6_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_6_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_7_EN                         7:7 /* RWIVF */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_7_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_03_RCL_THERMAL_7_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_04                                   0x00000004 /* RWI1R */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_8_EN                         0:0 /* RWIVF */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_8_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_8_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_9_EN                         1:1 /* RWIVF */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_9_EN_NO               0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_9_EN_YES              0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_10_EN                        2:2 /* RWIVF */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_10_EN_NO              0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_10_EN_YES             0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_11_EN                        3:3 /* RWIVF */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_11_EN_NO              0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_04_RCL_THERMAL_11_EN_YES             0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_05                                   0x00000005 /* RWI1R */
#define NV_NVI2CS_SENSOR_05_THERMAL_0                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_05_THERMAL_0_INIT                    0x0000006e /* RWI-V */
#define NV_NVI2CS_SENSOR_06                                   0x00000006 /* RWI1R */
#define NV_NVI2CS_SENSOR_06_THERMAL_1                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_06_THERMAL_1_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_07                                   0x00000007 /* RWI1R */
#define NV_NVI2CS_SENSOR_07_THERMAL_2                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_07_THERMAL_2_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_08                                   0x00000008 /* RWI1R */
#define NV_NVI2CS_SENSOR_08_THERMAL_3                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_08_THERMAL_3_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_09                                   0x00000009 /* RWI1R */
#define NV_NVI2CS_SENSOR_09_THERMAL_4                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_09_THERMAL_4_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_0A                                   0x0000000A /* RWI1R */
#define NV_NVI2CS_SENSOR_0A_THERMAL_5                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_0A_THERMAL_5_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_0B                                   0x0000000B /* RWI1R */
#define NV_NVI2CS_SENSOR_0B_THERMAL_6                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_0B_THERMAL_6_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_0C                                   0x0000000C /* RWI1R */
#define NV_NVI2CS_SENSOR_0C_THERMAL_7                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_0C_THERMAL_7_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_0D                                   0x0000000D /* RWI1R */
#define NV_NVI2CS_SENSOR_0D_THERMAL_8                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_0D_THERMAL_8_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_0E                                   0x0000000E /* RWI1R */
#define NV_NVI2CS_SENSOR_0E_THERMAL_9                                7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_0E_THERMAL_9_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_0F                                   0x0000000F /* RWI1R */
#define NV_NVI2CS_SENSOR_0F_THERMAL_10                               7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_0F_THERMAL_10_INIT                   0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_10                                   0x00000010 /* RWI1R */
#define NV_NVI2CS_SENSOR_10_THERMAL_11                               7:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_10_THERMAL_11_INIT                   0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_11                                   0x00000011 /* R-I1R */
#define NV_NVI2CS_SENSOR_11_RIET                                     7:7 /* R-IUF */
#define NV_NVI2CS_SENSOR_11_RIET_INIT                         0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_13                                   0x00000013 /* R-I1R */
#define NV_NVI2CS_SENSOR_13_UNCLAMPED_TEMP                           7:0 /* R-IUF */
#define NV_NVI2CS_SENSOR_13_UNCLAMPED_TEMP_INIT               0x00000000 /* R-I-V */
#define NV_NVI2CS_SENSOR_14                                   0x00000014 /* C--1R */
#define NV_NVI2CS_SENSOR_14_NEG_TEMP_OFFSET                          7:0 /* C--UF */
#define NV_NVI2CS_SENSOR_14_NEG_TEMP_OFFSET_INIT              0x00000040 /* C---V */
#define NV_NVI2CS_SENSOR_22                                   0x00000022 /* RWI1R */
#define NV_NVI2CS_SENSOR_22_SLEEP_CTRL                               0:0 /* RWIUF */
#define NV_NVI2CS_SENSOR_22_SLEEP_CTRL_ALLOW_SLEEP            0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_22_SLEEP_CTRL_FORCE_WAKE             0x00000001 /* RW--V */
#define NV_NVI2CS_SENSOR_32                                   0x00000032 /* RWI1R */
#define NV_NVI2CS_SENSOR_32_TSCFG0                                   7:0 /* RWIVF */
#define NV_NVI2CS_SENSOR_32_TSCFG0_INIT                       0x0000009D /* RWI-V */
#define NV_NVI2CS_SENSOR_33                                   0x00000033 /* RWI1R */
#define NV_NVI2CS_SENSOR_33_TSCFG1                                   7:0 /* RWIVF */
#define NV_NVI2CS_SENSOR_33_TSCFG1_INIT                       0x0000005D /* RWI-V */
#define NV_NVI2CS_SENSOR_34                                   0x00000034 /* RWI1R */
#define NV_NVI2CS_SENSOR_34_TSCFG2                                   7:0 /* RWIVF */
#define NV_NVI2CS_SENSOR_34_TSCFG2_INIT                       0x00000000 /* RWI-V */
#define NV_NVI2CS_SENSOR_35                                   0x00000035 /* RWI1R */
#define NV_NVI2CS_SENSOR_35_TSCFG3                                   7:0 /* RWIVF */
#define NV_NVI2CS_SENSOR_35_TSCFG3_INIT                       0x00000000 /* RWI-V */
#define NV_NVI2CS_GPUID_INT_REV                               0x00000060 /* R--1R */
#define NV_NVI2CS_GPUID_INT_REV_MINOR_REV                            3:0 /* R-XVF */
#define NV_NVI2CS_GPUID_INT_REV_MAJOR_REV                            7:4 /* R-XVF */
#define NV_NVI2CS_GPUID_EXT_REV                               0x00000061 /* R--1R */
#define NV_NVI2CS_GPUID_EXT_REV_FIB_REV                              3:0 /* R-XVF */
#define NV_NVI2CS_GPUID_EXT_REV_MASK_REV                             7:4 /* R-XVF */
#define NV_NVI2CS_GPUID_VENDOR_ID_L                           0x00000062 /* R-I1R */
#define NV_NVI2CS_GPUID_VENDOR_ID_L_VENDOR_ID                        7:0 /* R-IVF */
#define NV_NVI2CS_GPUID_VENDOR_ID_L_VENDOR_ID_INIT            0x000000DE /* R-I-V */
#define NV_NVI2CS_GPUID_VENDOR_ID_H                           0x00000063 /* R-I1R */
#define NV_NVI2CS_GPUID_VENDOR_ID_H_VENDOR_ID                        7:0 /* R-IVF */
#define NV_NVI2CS_GPUID_VENDOR_ID_H_VENDOR_ID_INIT            0x00000010 /* R-I-V */
#define NV_NVI2CS_GPUID_DEVICE_ID(i)                  (0x00000064+(i)*1) /* R--1A */
#define NV_NVI2CS_GPUID_DEVICE_ID__SIZE_1                              2 /*       */
#define NV_NVI2CS_GPUID_DEVICE_ID_DATA_BYTE0                         7:0 /* R-XVF */
#define NV_NVI2CS_GPUID_DEVICE_ID_DATA_BYTE1                         7:0 /* R-XVF */
#define NV_NVI2CS_GPUID_SUB_VENDOR_ID(i)              (0x00000066+(i)*1) /* R--1A */
#define NV_NVI2CS_GPUID_SUB_VENDOR_ID__SIZE_1                          2 /*       */
#define NV_NVI2CS_GPUID_SUB_VENDOR_ID_DATA_BYTE0                     7:0 /* R-XVF */
#define NV_NVI2CS_GPUID_SUB_VENDOR_ID_DATA_BYTE1                     7:0 /* R-XVF */
#define NV_NVI2CS_GPUID_SUB_DEVICE_ID(i)              (0x00000068+(i)*1) /* R--1A */
#define NV_NVI2CS_GPUID_SUB_DEVICE_ID__SIZE_1                          2 /*       */
#define NV_NVI2CS_GPUID_SUB_DEVICE_ID_DATA_BYTE0                     7:0 /* R-XVF */
#define NV_NVI2CS_GPUID_SUB_DEVICE_ID_DATA_BYTE1                     7:0 /* R-XVF */
#define NV_NVI2CS_GPUID_FOUNDRY_ID                            0x0000006A /* R-I1R */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID                        2:0 /* C-IVF */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_INIT        5/* C-I-V */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_TSMC            0x00000000 /* C---V */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_UMC             0x00000001 /* C---V */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_IBM             0x00000002 /* C---V */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_SMIC            0x00000003 /* C---V */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_CHARTERED       0x00000004 /* C---V */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_SAMSUNG         0x00000005 /* C---V */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_SONY            0x00000006 /* C---V */
#define NV_NVI2CS_GPUID_FOUNDRY_ID_FOUNDRY_ID_TOSHIBA         0x00000007 /* C---V */
#define NV_NVI2CS_GPUID_FAB_ID                                0x0000006B /* R--1R */
#define NV_NVI2CS_GPUID_FAB_ID_FAB_ID                                1:0 /* R-XVF */
#define NV_NVI2CS_GPUID_MINOR_EXT_REV_ID                      0x0000006C /* R--1R */
#define NV_NVI2CS_GPUID_MINOR_EXT_REV_ID_MINOR_EXT_REV_ID            3:0 /* R-XVF */
#define NV_NVI2CS_SENSOR_FD                                   0x000000FD /* R-I1R */
#define NV_NVI2CS_SENSOR_FD_VENDOR_ID                                7:0 /* R-IVF */
#define NV_NVI2CS_SENSOR_FD_VENDOR_ID_INIT                    0x00000010 /* R-I-V */
#define NV_NVI2CS_SENSOR_FE                                   0x000000FE /* R-I1R */
#define NV_NVI2CS_SENSOR_FE_VENDOR_ID                                7:0 /* R-IVF */
#define NV_NVI2CS_SENSOR_FE_VENDOR_ID_INIT                    0x000000DE /* R-I-V */
#define NV_NVI2CS_SENSOR_FF                                   0x000000FF /* R-I1R */
#define NV_NVI2CS_SENSOR_FF_REV_ID                                   7:0 /* R-IVF */
#define NV_NVI2CS_SENSOR_FF_REV_ID_INIT                       0x00000001 /* R-I-V */
#define NV_NVI2CS_BAR0_ADDR_BYTE(i)                   (0x00000040+(i)*1) /* RWI1A */
#define NV_NVI2CS_BAR0_ADDR_BYTE__SIZE_1                               4 /*       */
#define NV_NVI2CS_BAR0_ADDR_BYTE_ADDR                                7:0 /* RWIUF */
#define NV_NVI2CS_BAR0_ADDR_BYTE_ADDR_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_BAR0_ADDR_WORD                              0x00000050 /* RWI4R */
#define NV_NVI2CS_BAR0_ADDR_WORD_ADDR                               31:0 /* RWIUF */
#define NV_NVI2CS_BAR0_ADDR_WORD_ADDR_INIT                    0x00000000 /* RWI-V */
#define NV_NVI2CS_BAR0_WDAT_BYTE(i)                   (0x00000044+(i)*1) /* -WI1A */
#define NV_NVI2CS_BAR0_WDAT_BYTE__SIZE_1                               4 /*       */
#define NV_NVI2CS_BAR0_WDAT_BYTE_WDATA                               7:0 /* -WIUF */
#define NV_NVI2CS_BAR0_WDAT_BYTE_WDATA_INIT                   0x00000000 /* -WI-V */
#define NV_NVI2CS_BAR0_WDAT_WORD                              0x00000054 /* -WI4R */
#define NV_NVI2CS_BAR0_WDAT_WORD_WDATA                              31:0 /* -WIUF */
#define NV_NVI2CS_BAR0_WDAT_WORD_WDATA_INIT                   0x00000000 /* -WI-V */
#define NV_NVI2CS_BAR0_RDAT_BYTE(i)                   (0x00000044+(i)*1) /* R-I1A */
#define NV_NVI2CS_BAR0_RDAT_BYTE__SIZE_1                               4 /*       */
#define NV_NVI2CS_BAR0_RDAT_BYTE_RDATA                               7:0 /* R-IUF */
#define NV_NVI2CS_BAR0_RDAT_BYTE_RDATA_INIT                   0x00000000 /* R-I-V */
#define NV_NVI2CS_BAR0_RDAT_WORD                              0x00000054 /* R-I4R */
#define NV_NVI2CS_BAR0_RDAT_WORD_RDATA                              31:0 /* R-IUF */
#define NV_NVI2CS_BAR0_RDAT_WORD_RDATA_INIT                   0x00000000 /* R-I-V */
#define NV_NVI2CS_BAR0_CSR                                    0x00000048 /* RWI1R */
#define NV_NVI2CS_BAR0_CSR_WRBE                                      3:0 /* RWIVF */
#define NV_NVI2CS_BAR0_CSR_WRBE_NO_BYTES                      0x00000000 /* RWI-V */
#define NV_NVI2CS_BAR0_CSR_WRBE_ALL_BYTES                     0x0000000f /* RW--V */
#define NV_NVI2CS_BAR0_CSR_TYPE                                      4:4 /* RWIVF */
#define NV_NVI2CS_BAR0_CSR_TYPE_WRITE                         0x00000000 /* RWI-V */
#define NV_NVI2CS_BAR0_CSR_TYPE_READ                          0x00000001 /* RW--V */
#define NV_NVI2CS_BAR0_CSR_REQ                                       7:7 /* R-IVF */
#define NV_NVI2CS_BAR0_CSR_REQ_IN_PROG                        0x00000000 /* R---V */
#define NV_NVI2CS_BAR0_CSR_REQ_DONE                           0x00000001 /* R-I-V */
#define NV_NVI2CS_BAR0_PASSWORD(i)                    (0x0000004c+(i)*1) /* -W-1A */
#define NV_NVI2CS_BAR0_PASSWORD__SIZE_1                                4 /*       */
#define NV_NVI2CS_BAR0_PASSWORD_ENABLE                               7:0 /* -W-VF */
#define NV_NVI2CS_BAR0_PASSWORD_ENABLE_LOCK                   0x00000000 /* -W--V */
#define NV_NVI2CS_BAR0_PASSWORD_ENABLE_UNLOCK_BYTE0           0x00000068 /* -W--V */
#define NV_NVI2CS_BAR0_PASSWORD_ENABLE_UNLOCK_BYTE1           0x00000074 /* -W--V */
#define NV_NVI2CS_BAR0_PASSWORD_ENABLE_UNLOCK_BYTE2           0x00000076 /* -W--V */
#define NV_NVI2CS_BAR0_PASSWORD_ENABLE_UNLOCK_BYTE3           0x0000006e /* -W--V */
#define NV_NVI2CS_SCRATCH_BYTE(i)                     (0x000000F8+(i)*1) /* RWI1A */
#define NV_NVI2CS_SCRATCH_BYTE__SIZE_1                                 4 /*       */
#define NV_NVI2CS_SCRATCH_BYTE_DATA                                  7:0 /* RWIVF */
#define NV_NVI2CS_SCRATCH_BYTE_DATA_INIT                      0x00000000 /* RWI-V */
#define NV_NVI2CS_SCRATCH_WORD                                0x0000005B /* RWI4R */
#define NV_NVI2CS_SCRATCH_WORD_DATA                                 31:0 /* RWIVF */
#define NV_NVI2CS_SCRATCH_WORD_DATA_INIT                      0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_COMMAND_BYTE(i)              (0x00000070+(i)*1) /* RWI1A */
#define NV_NVI2CS_MSGBOX_COMMAND_BYTE__SIZE_1                          4 /*       */
#define NV_NVI2CS_MSGBOX_COMMAND_BYTE_DATA                           7:0 /* RWIVF */
#define NV_NVI2CS_MSGBOX_COMMAND_BYTE_DATA_INIT               0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_COMMAND_BYTE_INTR                           7:7 /* RWIVF */
#define NV_NVI2CS_MSGBOX_COMMAND_BYTE_INTR_NOT_PENDING        0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_COMMAND_BYTE_INTR_PENDING            0x00000001 /* RW--V */
#define NV_NVI2CS_MSGBOX_COMMAND_WORD                         0x0000005C /* RWI4R */
#define NV_NVI2CS_MSGBOX_COMMAND_WORD_DATA                          30:0 /* RWIVF */
#define NV_NVI2CS_MSGBOX_COMMAND_WORD_DATA_INIT               0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_COMMAND_WORD_INTR                         31:31 /* RWIVF */
#define NV_NVI2CS_MSGBOX_COMMAND_WORD_INTR_NOT_PENDING        0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_COMMAND_WORD_INTR_PENDING            0x00000001 /* RW--V */
#define NV_NVI2CS_MSGBOX_DATA_IN_BYTE(i)              (0x00000074+(i)*1) /* RWI1A */
#define NV_NVI2CS_MSGBOX_DATA_IN_BYTE__SIZE_1                          4 /*       */
#define NV_NVI2CS_MSGBOX_DATA_IN_BYTE_DATA                           7:0 /* RWIVF */
#define NV_NVI2CS_MSGBOX_DATA_IN_BYTE_DATA_INIT               0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_DATA_IN_WORD                         0x0000005D /* RWI4R */
#define NV_NVI2CS_MSGBOX_DATA_IN_WORD_DATA                          31:0 /* RWIVF */
#define NV_NVI2CS_MSGBOX_DATA_IN_WORD_DATA_INIT               0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_DATA_OUT_BYTE(i)             (0x00000078+(i)*1) /* RWI1A */
#define NV_NVI2CS_MSGBOX_DATA_OUT_BYTE__SIZE_1                         4 /*       */
#define NV_NVI2CS_MSGBOX_DATA_OUT_BYTE_DATA                          7:0 /* RWIVF */
#define NV_NVI2CS_MSGBOX_DATA_OUT_BYTE_DATA_INIT              0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_DATA_OUT_WORD                        0x0000005E /* RWI4R */
#define NV_NVI2CS_MSGBOX_DATA_OUT_WORD_DATA                         31:0 /* RWIVF */
#define NV_NVI2CS_MSGBOX_DATA_OUT_WORD_DATA_INIT              0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_MUTEX_BYTE                           0x0000007C /* RWI1R */
#define NV_NVI2CS_MSGBOX_MUTEX_BYTE_CLIENT                           7:0 /* RWIVF */
#define NV_NVI2CS_MSGBOX_MUTEX_BYTE_CLIENT_NONE               0x00000000 /* RWI-V */
#define NV_NVI2CS_MSGBOX_MUTEX_WORD                           0x0000005F /* RWI4R */
#define NV_NVI2CS_MSGBOX_MUTEX_WORD_CLIENT                           7:0 /* RWIVF */
#define NV_NVI2CS_MSGBOX_MUTEX_WORD_CLIENT_NONE               0x00000000 /* RWI-V */
#endif // __ga102_dev_i2cs_h__
