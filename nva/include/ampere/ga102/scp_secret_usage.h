/* _NVRM_COPYRIGHT_BEGIN_
 *
 * Copyright 2018-2020 by NVIDIA Corporation.  All rights reserved.  All
 * information contained herein is proprietary and confidential to NVIDIA
 * Corporation.  Any use, reproduction, or disclosure without the written
 * permission of NVIDIA Corporation is prohibited.
 *
 * _NVRM_COPYRIGHT_END_
 */
#ifndef __ga102_scp_secret_usage_h__
#define __ga102_scp_secret_usage_h__

/*!
 * Regarding HW usage of SCP Secrets Keys:
 *      HW usecases of SCP secret keys are tagged as "HW usecase" with inline comments.
 *      Information is pulled from //hw/doc/mmplex/peregrine/2.0/arch/IAS/GA10x_falcon_6_arch.doc
 *
 * Regarding SW usage of SCP Secret Keys:
 *      All assigned keys apart from the ones tagged as "HW usecase" are SW usecases
 *      Ideally, none of the SW usecase should overlap with HW usecase or other SW usecase
 */
typedef enum {
    SCP_SECRET_KEY_INDEX_VIDEO_DBG_0            = 0,
    SCP_SECRET_KEY_INDEX_GFW_DBG_0              = 0,
    SCP_SECRET_KEY_INDEX_HS_SIGNING             = 1,    // HW usecase - [AES] Signing key generation
    SCP_SECRET_KEY_INDEX_2                      = 2,
    SCP_SECRET_KEY_INDEX_VIDEO_PROD_4           = 3,
    SCP_SECRET_KEY_INDEX_VIDEO_PROD_2           = 4,
    SCP_SECRET_KEY_INDEX_5_DO_NOT_USE           = 5,
    SCP_SECRET_KEY_INDEX_VIDEO_DBG_1            = 5,
    SCP_SECRET_KEY_INDEX_HS_ENCR_AFTER_AES_AUTH = 6,    // HW usecase - [AES] decryption key generation for CODE decryption
    SCP_SECRET_KEY_MIXIN_HS_SIGNING             = 7,    // HW usecase - [AES] IV generation
    SCP_SECRET_KEY_INDEX_8                      = 8,
    SCP_SECRET_KEY_INDEX_9                      = 9,
    SCP_SECRET_KEY_INDEX_HDCP22                 = 10,
    SCP_SECRET_KEY_INDEX_VIDEO_PROD_5           = 11,
    SCP_SECRET_KEY_INDEX_VIDEO_PROD_1           = 12,
    SCP_SECRET_KEY_INDEX_GFE_KEY                = 13,
    SCP_SECRET_KEY_INDEX_PLAYREADY_MPK          = 14,
    SCP_SECRET_KEY_INDEX_15                     = 15,
    SCP_SECRET_KEY_INDEX_HUB_ENC_KEY            = 16,
    SCP_SECRET_KEY_INDEX_17                     = 17,
    SCP_SECRET_KEY_INDEX_18                     = 18,
    SCP_SECRET_KEY_INDEX_VIDEO_PROD_0           = 19,
    SCP_SECRET_KEY_INDEX_20                     = 20,
    SCP_SECRET_KEY_INDEX_21                     = 21,
    SCP_SECRET_KEY_INDEX_PLAYREADY_PDUB         = 22,
    SCP_SECRET_KEY_INDEX_23                     = 23,
    SCP_SECRET_KEY_INDEX_24                     = 24,
    SCP_SECRET_KEY_INDEX_PLAYREADY              = 25,
    SCP_SECRET_KEY_INDEX_26                     = 26,
    SCP_SECRET_KEY_INDEX_27                     = 27,
    SCP_SECRET_KEY_INDEX_28                     = 28,
    SCP_SECRET_KEY_INDEX_29                     = 29,
    SCP_SECRET_KEY_INDEX_30                     = 30,
    SCP_SECRET_KEY_INDEX_RM_LS_ENCRYPTION       = 31,
    SCP_SECRET_KEY_INDEX_32                     = 32,
    SCP_SECRET_KEY_INDEX_33                     = 33,
    SCP_SECRET_KEY_BROM_FUSE_1                  = 34,   // HW usecase - [FALCON_PKC][RISCV_PKC] IV generation of decryptFuseKeys
    SCP_SECRET_KEY_BROM_FUSE_2                  = 35,   // HW usecase - [FALCON_PKC][RISCV_PKC] SigKey generation of decryptFuseKeys
    SCP_SECRET_KEY_INDEX_36                     = 36,
    SCP_SECRET_KEY_INDEX_HS_ENCRYPTION          = 37,   // HW usecase - [FALCON_PKC]  Code decryption
    SCP_SECRET_KEY_BROM_FUSE_3                  = 38,   // HW usecase - [FALCON_PKC][RISCV_PKC] keyglob decryption of decryptFuseKeys
    SCP_SECRET_KEY_INDEX_39                     = 39,
    SCP_SECRET_KEY_INDEX_GFW_PROD_40            = 40,   // GFW LS signing
    SCP_SECRET_KEY_BOOT_TIME_KDF_1              = 41,   // HW usecase - [RISCV_PKC] root key of KDF
    SCP_SECRET_KEY_INDEX_42                     = 42,
    SCP_SECRET_KEY_INDEX_RM_LS_SIGNING          = 43,   // RM LS signing
    SCP_SECRET_KEY_BOOT_TIME_KDF_2              = 44,   // HW usecase - [RISCV_PKC] root key of KDF
    SCP_SECRET_KEY_INDEX_45                     = 45,
    SCP_SECRET_KEY_MANIFEST_DECRYPTION          = 46,   // HW usecase - [RISCV_PKC] manifest decryption
    SCP_SECRET_KEY_BOOT_TIME_KDF_3              = 47,   // HW usecase - [RISCV_PKC] root key of KDF
    SCP_SECRET_KEY_INDEX_48                     = 48,
    SCP_SECRET_KEY_FMC_DECRYPTION               = 49,   // HW usecase - [RISCV_PKC] FMC decryption
    SCP_SECRET_KEY_INDEX_50                     = 50,
    SCP_SECRET_KEY_INDEX_51                     = 51,
    SCP_SECRET_KEY_INDEX_52                     = 52,
    SCP_SECRET_KEY_INDEX_53                     = 53,
    SCP_SECRET_KEY_INDEX_54                     = 54,
    SCP_SECRET_KEY_INDEX_55                     = 55,
    SCP_SECRET_KEY_INDEX_56                     = 56,
    SCP_SECRET_KEY_INDEX_57                     = 57,
    SCP_SECRET_KEY_INDEX_58                     = 58,
    SCP_SECRET_KEY_INDEX_59                     = 59,
    SCP_SECRET_KEY_INDEX_60                     = 60,
    SCP_SECRET_KEY_INDEX_61                     = 61,
    SCP_SECRET_KEY_INDEX_62                     = 62,
    SCP_SECRET_KEY_INDEX_VIDEO_PROD_3           = 63,
    SCP_SECRET_KEY_INDEX_INVALID                = 64,
} SCP_SECRET_KEY_INDEX;

/**********************************************************************/
/************** BELOW ARE SECRETS AND KDF USED IN RM ******************/
/**********************************************************************/
//
// NV_SCP_SECRET_IDX_PLAYREADY is the SCP secret index used for deriving keys within SEC2/NVDEC Playready app. The derived keys are used for
// a) Generating per device unique TK (Tee Key)
// b) Encrypting OEM blob playload
// c) Signing OEM blob
//
// For a), TK = ENC(NV_SCP_SECRET_IDX_PLAYREADY, N) where N = Concatenation(64bits PDI | 32 bits Constant | 32 bits TKID)
//         The PDI is retrieved from NV_FUSE_OPT_PRIV_PDI_0 and NV_FUSE_OPT_PRIV_PDI_1
//         The Constant is generated by (NV_SCP_SECRET_KDF_SALT_PLAYREADY ^ NV_SCP_SECRET_KDF_MODE_PLAYREADY_GEN_TK)
//         The TKID (Tee Key ID) will be provided by the player
//
// For b), Encryption key = ENC(NV_SCP_SECRET_KDF_SALT_PLAYREADY, N), where N = Concatenation(64bits PDI | 32 bits Constant | 32 bits CTKID)
//         The PDI is retrieved from NV_FUSE_OPT_PRIV_PDI_0 and NV_FUSE_OPT_PRIV_PDI_1
//         The Constant is generated by (NV_SCP_SECRET_KDF_SALT_PLAYREADY ^ NV_SCP_SECRET_KDF_MODE_PLAYREADY_GEN_OEM_BLOB_ENC_KEY)
//         The CTKID (Current TKID which is a constant defined in Playready source code)
//
// For c), Signing key = ENC(NV_SCP_SECRET_KDF_SALT_PLAYREADY, N), where N = Concatenation(64bits PDI | 32 bits Constant | 32 bits CTKID)
//         The PDI is retrieved from NV_FUSE_OPT_PRIV_PDI_0 and NV_FUSE_OPT_PRIV_PDI_1
//         The Constant is generated by (NV_SCP_SECRET_KDF_SALT_PLAYREADY ^ NV_SCP_SECRET_KDF_MODE_PLAYREADY_GEN_OEM_BLOB_SIGN_KEY)
//         The CTKID (Current TKID which is a constant defined in Playready source code)
//
#define NV_SCP_SECRET_IDX_PLAYREADY                             (SCP_SECRET_KEY_INDEX_PLAYREADY)
#define NV_SCP_SECRET_KDF_SALT_PLAYREADY                        (0x50524459)
#define NV_SCP_SECRET_KDF_MODE_PLAYREADY_GEN_TK                 (0x00000001)
#define NV_SCP_SECRET_KDF_MODE_PLAYREADY_GEN_OEM_BLOB_ENC_KEY   (0x00000002)
#define NV_SCP_SECRET_KDF_MODE_PLAYREADY_GEN_OEM_BLOB_SIGN_KEY  (0x00000003)

//
// NV_SCP_SECRET_IDX_ENC_HUB_ENC_KEY is the SCP secret index used for encrypting hub encryption keys for restoration across GC6 cycle.
// Encrypted key = ENC(NV_SCP_SECRET_IDX_ENC_HUB_ENC_KEY, Hub Encryption Key)
// Encrypted key is saved in BSI_SECURE_SCRATCH registers. See <wiki link> for exact scratch index
//
#define NV_SCP_SECRET_IDX_ENC_HUB_ENC_KEY                       (SCP_SECRET_KEY_INDEX_HUB_ENC_KEY)

//
// NV_SCP_SECRET_IDX_GFE_KEK is the SCP secret index used for GFE task.
// The salt is generated by computing the SHA2 of these constants
// SALT = SHA2(ucodeVersion | GFE_SALT)
//
#define NV_SCP_SECRET_IDX_GFE_KEK                               (SCP_SECRET_KEY_INDEX_GFE_KEY)
#define NV_SCP_SECRET_KDF_SALT_GFE_PART_1                       (0x04030201)
#define NV_SCP_SECRET_KDF_SALT_GFE_PART_2                       (0x08070605)
#define NV_SCP_SECRET_KDF_SALT_GFE_PART_3                       (0x0d0e0f09)
#define NV_SCP_SECRET_KDF_SALT_GFE_PART_4                       (0x000a0b0c)

//
// NV_SCP_SECRET_IDX_HDCP22_KEY is the SCP secret index used for HDCP22 task.
// Dkey = Enc(salt, NV_SCP_SECRET_IDX_HDCP22_KEK)
// ESecret = Enc(secret, Dkey, Iv)
//   where Dkey    = derived AES key that encrypting salt with HW secret.
//         Esecret = encrypted confidential secret with CbcCrypt.
//         Iv      = input vector that random number generated at runtime.
//
#define NV_SCP_SECRET_IDX_10                                    (SCP_SECRET_KEY_INDEX_HDCP22)
#define NV_SCP_SECRET_IDX_HDCP22_KEY                            (NV_SCP_SECRET_IDX_10)
#define NV_SCP_SECRET_KDF_SALT_HDCP22_PART_1                    (0x36a6c10e)
#define NV_SCP_SECRET_KDF_SALT_HDCP22_PART_2                    (0xa9f3b45b)
#define NV_SCP_SECRET_KDF_SALT_HDCP22_PART_3                    (0x2196366e)
#define NV_SCP_SECRET_KDF_SALT_HDCP22_PART_4                    (0x3db471a9)

//
// NV_SCP_SECRET_IDX_PR_MPK_ENCRYPT is the SCP secret index used for Playready MPK encryption.
//
// Fkey = Enc(sig, NV_SCP_SECRET_IDX_PR_MPK_ENCRYPT)
// Dkey = Enc(Fkey, KDF(SALT, Ucodeversion | position))
// Key  = Dec(Ekey, Dkey)
//   where Fkey = First key derived
//         Dkey = Key used for decryption
//         Key  = Actual MPK
//
#define NV_SCP_SECRET_IDX_PR_MPK_ENCRYPT                        (SCP_SECRET_KEY_INDEX_PLAYREADY_MPK)
#define NV_SCP_SECRET_KDF_SALT_PR_MPK_ENCRYPT_0                 (0x73934871)
#define NV_SCP_SECRET_KDF_SALT_PR_MPK_ENCRYPT_1                 (0x962534ab)
#define NV_SCP_SECRET_KDF_SALT_PR_MPK_ENCRYPT_2                 (0xfd237854)
#define NV_SCP_SECRET_KDF_SALT_PR_MPK_ENCRYPT_3                 (0xecf61209)

/**********************************************************************/
/************** BELOW ARE SECRETS AND KDF USED IN NVDEC ***************/
/**********************************************************************/
//
// Description of NVDEC encrypted Content Playback & CTR-64 App
//
#define NV_SCP_SECRET_IDX_ENC_CONTENT_PLAYBACK_PROD_0           (SCP_SECRET_KEY_INDEX_VIDEO_PROD_0)
#define NV_SCP_SECRET_IDX_ENC_CONTENT_PLAYBACK_PROD_1           (SCP_SECRET_KEY_INDEX_VIDEO_PROD_1)
#define NV_SCP_SECRET_IDX_ENC_CONTENT_PLAYBACK_PROD_2           (SCP_SECRET_KEY_INDEX_VIDEO_PROD_2)
#define NV_SCP_SECRET_IDX_ENC_CONTENT_PLAYBACK_PROD_3           (SCP_SECRET_KEY_INDEX_VIDEO_PROD_3)
#define NV_SCP_SECRET_IDX_ENC_CONTENT_PLAYBACK_PROD_4           (SCP_SECRET_KEY_INDEX_VIDEO_PROD_4)
#define NV_SCP_SECRET_IDX_ENC_CONTENT_PLAYBACK_PROD_5           (SCP_SECRET_KEY_INDEX_VIDEO_PROD_5)
#define NV_SCP_SECRET_IDX_ENC_CONTENT_PLAYBACK_DBG_0            (SCP_SECRET_KEY_INDEX_VIDEO_DBG_0)
#define NV_SCP_SECRET_IDX_ENC_CONTENT_PLAYBACK_DBG_1            (SCP_SECRET_KEY_INDEX_VIDEO_DBG_1)

//
// Description of NVDEC DH
//
#define NV_SCP_SECRET_IDX_DH_PROD_0                             (SCP_SECRET_KEY_INDEX_VIDEO_PROD_0)
#define NV_SCP_SECRET_IDX_DH_PROD_1                             (SCP_SECRET_KEY_INDEX_VIDEO_PROD_2)
#define NV_SCP_SECRET_IDX_DH_PROD_2                             (SCP_SECRET_KEY_INDEX_VIDEO_PROD_3)
#define NV_SCP_SECRET_IDX_DH_PROD_3                             (SCP_SECRET_KEY_INDEX_VIDEO_PROD_4)
#define NV_SCP_SECRET_IDX_DH_PROD_4                             (SCP_SECRET_KEY_INDEX_VIDEO_PROD_5)
#define NV_SCP_SECRET_IDX_DH_DBG_0                              (SCP_SECRET_KEY_INDEX_VIDEO_DBG_1)
#define NV_SCP_SECRET_IDX_DH_DBG_1                              (SCP_SECRET_KEY_INDEX_VIDEO_DBG_0)


/**********************************************************************/
/************ BELOW ARE SECRETS AND KDF USED IN VBIOS/GFW *************/
/**********************************************************************/

//
// DEVINIT - Ek = AES-ECB( Seed1, SCP_SECRET_KEY_INDEX_GFW_<> )
// VBIOS_CERT - Ek = 3-AES-CBC (Seed2, IV, SCP_SECRET_KEY_INDEX_GFW_<> )
// HULK - Ek = 3-AES-CBC (Seed3, IV, SCP_SECRET_KEY_INDEX_GFW_<> )
// HS_UCODE_DMEM - Ek = AES-ECB( Seed4, SCP_SECRET_KEY_INDEX_GFW_<> )
// VDPA - Ek = AES-ECB( Seed5, SCP_SECRET_KEY_INDEX_GFW_<> )
// NVFLASH_DMEM - Ek = AES-ECB( Seed6, SCP_SECRET_KEY_INDEX_GFW_<> )
// GSYNC_FW - Ek = AES-ECB( Seed7, SCP_SECRET_KEY_INDEX_GFW_<> )
// PR_PDUB_PROD - Ek = AES-ECB( Seed8, SCP_SECRET_KEY_INDEX_PLAYREADY_PDUB )
//

#define NV_SCP_SECRET_IDX_GFW_DEVINIT_PROD                      (SCP_SECRET_KEY_INDEX_GFW_PROD_40)
#define NV_SCP_SECRET_IDX_GFW_VBIOS_CERT_PROD                   (SCP_SECRET_KEY_INDEX_GFW_PROD_40)
#define NV_SCP_SECRET_IDX_GFW_HULK_PROD                         (SCP_SECRET_KEY_INDEX_GFW_PROD_40)
#define NV_SCP_SECRET_IDX_GFW_HS_UCODE_DMEM_PROD                (SCP_SECRET_KEY_INDEX_GFW_PROD_40)
#define NV_SCP_SECRET_IDX_GFW_VDPA_PROD                         (SCP_SECRET_KEY_INDEX_GFW_PROD_40)
#define NV_SCP_SECRET_IDX_GFW_NVFLASH_DMEM_PROD                 (SCP_SECRET_KEY_INDEX_GFW_PROD_40)
#define NV_SCP_SECRET_IDX_GFW_GSYNC_FW_UPDATE_PROD              (SCP_SECRET_KEY_INDEX_GFW_PROD_40)
#define NV_SCP_SECRET_IDX_GFW_PLAY_READY_PDUB_PROD              (SCP_SECRET_KEY_INDEX_PLAYREADY_PDUB)

#define NV_SCP_SECRET_IDX_GFW_DEVINIT_DBG                       (SCP_SECRET_KEY_INDEX_GFW_DBG_0)
#define NV_SCP_SECRET_IDX_GFW_VBIOS_CERT_DBG                    (SCP_SECRET_KEY_INDEX_GFW_DBG_0)
#define NV_SCP_SECRET_IDX_GFW_HULK_DBG                          (SCP_SECRET_KEY_INDEX_GFW_DBG_0)
#define NV_SCP_SECRET_IDX_GFW_HS_UCODE_DMEM_DBG                 (SCP_SECRET_KEY_INDEX_GFW_DBG_0)
#define NV_SCP_SECRET_IDX_GFW_VDPA_DBG                          (SCP_SECRET_KEY_INDEX_GFW_DBG_0)
#define NV_SCP_SECRET_IDX_GFW_NVFLASH_DMEM_DBG                  (SCP_SECRET_KEY_INDEX_GFW_DBG_0)
#define NV_SCP_SECRET_IDX_GFW_GSYNC_FW_UPDATE_DBG               (SCP_SECRET_KEY_INDEX_GFW_DBG_0)
#define NV_SCP_SECRET_IDX_GFW_PLAY_READY_PDUB_DBG               (SCP_SECRET_KEY_INDEX_GFW_DBG_0)


#endif // __ga102_scp_secret_usage_h__
