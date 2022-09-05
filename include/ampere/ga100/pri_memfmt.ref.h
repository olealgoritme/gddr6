// --------------------------------------------------------------------------------
// 
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR                              0x00404600 /* RWE4R */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_EXTRA_INLINE_DATA                   0:0 /* R-EVF */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_EXTRA_INLINE_DATA_NOT_PENDING       0x0 /* R-E-V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_EXTRA_INLINE_DATA_PENDING           0x1 /* R---V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_MISSING_INLINE_DATA                 1:1 /* R-EVF */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_MISSING_INLINE_DATA_NOT_PENDING     0x0 /* R-E-V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_MISSING_INLINE_DATA_PENDING         0x1 /* R---V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_FEPIPE                            19:19 /* R-EVF */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_FEPIPE_FE0                          0x0 /* R-E-V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_FEPIPE_FE1                          0x1 /* R---V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_VEID     6+19:20 /* R-EVF */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_VEID_INIT                           0x0 /* R-E-V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_RESET                             30:30 /* -WEVF */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_RESET_V_0                           0x0 /* -WE-V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_RESET_ACTIVE                        0x1 /* -W--T */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_EN                                31:31 /* RWEVF */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_EN_DISABLE                          0x0 /* RW--V */
#define NV_PGRAPH_PRI_MEMFMT_HWW_ESR_EN_ENABLE                           0x1 /* RWE-V */
// 
// --------------------------------------------------------------------------------
