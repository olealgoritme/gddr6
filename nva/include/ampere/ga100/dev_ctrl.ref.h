// --------------------------------------------------------------------------------
// 
#define NV_CTRL                      0x00b7ffff:0x00b60000 /* RW--D */
#define NV_CTRL_CPU_INTR_TOP(i)             (0x00B73400+(i)*4) /* R--4A */
#define NV_CTRL_CPU_INTR_TOP__SIZE_1 64 /*       */
#define NV_CTRL_CPU_INTR_TOP_VALUE                        31:0 /* R--VF */
#define NV_CTRL_CPU_INTR_TOP_EN_SET(i)               (0x00B73800+(i)*4) /* RW-4A */
#define NV_CTRL_CPU_INTR_TOP_EN_SET__SIZE_1   64 /*       */
#define NV_CTRL_CPU_INTR_TOP_EN_SET_VALUE                          31:0 /* RWIVF */
#define NV_CTRL_CPU_INTR_TOP_EN_SET_VALUE_INIT               0x00000000 /* R-I-V */
#define NV_CTRL_CPU_INTR_TOP_EN_CLEAR(i)             (0x00B73C00+(i)*4) /* RW-4A */
#define NV_CTRL_CPU_INTR_TOP_EN_CLEAR__SIZE_1 64 /*       */
#define NV_CTRL_CPU_INTR_TOP_EN_CLEAR_VALUE                        31:0 /* RWIVF */
#define NV_CTRL_CPU_INTR_TOP_EN_CLEAR_VALUE_INIT             0x00000000 /* R-I-V */
#define NV_CTRL_CPU_INTR_LEAF(i)                                         (0x00B74000+(i)*4) /* RW-4A */
#define NV_CTRL_CPU_INTR_LEAF__SIZE_1    1024 /*       */
#define NV_CTRL_CPU_INTR_LEAF_VALUE                                                    31:0 /* RWIVF */
#define NV_CTRL_CPU_INTR_LEAF_VALUE_INIT                                         0x00000000 /* R-I-V */
#define NV_CTRL_CPU_INTR_LEAF_ARRAY_SIZE_PER_FN  16 /*       */
#define NV_CTRL_CPU_INTR_LEAF_EN_SET(i)                                           (0x00B78000+(i)*4) /* RW-4A */
#define NV_CTRL_CPU_INTR_LEAF_EN_SET__SIZE_1      1024 /*       */
#define NV_CTRL_CPU_INTR_LEAF_EN_SET_VALUE                                                      31:0 /* RWIVF */
#define NV_CTRL_CPU_INTR_LEAF_EN_SET_VALUE_INIT                                           0x00000000 /* R-I-V */
#define NV_CTRL_CPU_INTR_LEAF_EN_CLEAR(i)                                         (0x00B7C000+(i)*4) /* RW-4A */
#define NV_CTRL_CPU_INTR_LEAF_EN_CLEAR__SIZE_1    1024 /*       */
#define NV_CTRL_CPU_INTR_LEAF_EN_CLEAR_VALUE                                                    31:0 /* RWIVF */
#define NV_CTRL_CPU_INTR_LEAF_EN_CLEAR_VALUE_INIT                                         0x00000000 /* R-I-V */
#define NV_CTRL_LEGACY_ENGINE_STALL_INTR_BASE_VECTORID         0xB66880 /* C--4R */
#define NV_CTRL_LEGACY_ENGINE_STALL_INTR_BASE_VECTORID_VECTOR      11:0 /* C--UF */
#define NV_CTRL_LEGACY_ENGINE_STALL_INTR_BASE_VECTORID_VECTOR_INIT   192 /* C---V */
#define NV_CTRL_LEGACY_ENGINE_NONSTALL_INTR_BASE_VECTORID       0xB66884 /* C--4R */
#define NV_CTRL_LEGACY_ENGINE_NONSTALL_INTR_BASE_VECTORID_VECTOR    11:0 /* C--UF */
#define NV_CTRL_LEGACY_ENGINE_NONSTALL_INTR_BASE_VECTORID_VECTOR_INIT   0 /* C---V */
#define  NV_CTRL_USERMODE_CFG0                                 0xB668A8 /* C--4R */
#define  NV_CTRL_USERMODE_CFG0_USERMODE_CLASS_ID                   15:0 /* C--UF */
#define  NV_CTRL_USERMODE_CFG0_USERMODE_CLASS_ID_VALUE   50529 /* C---V */
#define NV_CTRL_MAILBOX_SCRATCH(i)                (0x00B60000+(i)*4) /* RW-4A */
#define NV_CTRL_MAILBOX_SCRATCH__SIZE_1 1024 /*       */
#define NV_CTRL_MAILBOX_SCRATCH_DATA                            31:0 /* RWXVF */
#define NV_CTRL_DOORBELL(i)                          (0x00B64000+(i)*8) /*       */
#define NV_CTRL_DOORBELL__SIZE_1                64 /*       */
#define NV_CTRL_DOORBELL_HANDLE                  31:0 /*       */
#define NV_CTRL_DOORBELL_VECTOR                  11:0 /*       */
#define NV_CTRL_DOORBELL_RSVD                      15:12 /*       */
#define NV_CTRL_DOORBELL_RUNLIST_ID          22:16 /*       */
#define NV_CTRL_DOORBELL_RUNLIST_ID_INVALID_RUNLIST            0x7F /*       */
#define NV_CTRL_DOORBELL_RUNLIST_DOORBELL                      22:22           /*       */
#define NV_CTRL_DOORBELL_RUNLIST_DOORBELL_DISABLE              0x1   /*       */
#define NV_CTRL_DOORBELL_RUNLIST_DOORBELL_ENABLE               0x0    /*       */
#define NV_CTRL_DOORBELL_RSVD2                    31:23 /*       */
#define NV_CTRL_DOORBELL_GSP_DOORBELL                           31:31         /*       */
#define NV_CTRL_DOORBELL_GSP_DOORBELL_DISABLE                   0x1 /*       */
#define NV_CTRL_DOORBELL_GSP_DOORBELL_ENABLE                    0x0  /*       */
#define NV_CTRL_PRIV_DOORBELL(i)                                          (0x00B64800+(i)*8) /*       */
#define NV_CTRL_PRIV_DOORBELL__SIZE_1                                64 /*       */
#define NV_CTRL_PRIV_DOORBELL_HANDLE                                  31:0 /*       */
#define NV_CTRL_PRIV_DOORBELL_VECTOR                                  11:0 /*       */
#define NV_CTRL_PRIV_DOORBELL_RSVD                                      30:12 /*       */
#define NV_CTRL_PRIV_DOORBELL_CPU_NOTIFICATION              31:31 /*       */
#define NV_CTRL_PRIV_DOORBELL_CPU_NOTIFICATION_TRUE    1 /*       */
#define NV_CTRL_PRIV_DOORBELL_CPU_NOTIFICATION_FALSE  0 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF(i)              (0x00B66800+(i)*4) /* RW-4A */
#define NV_CTRL_VIRTUAL_INTR_LEAF__SIZE_1                          2 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_PENDING                       31:0 /* RWIVF */
#define NV_CTRL_VIRTUAL_INTR_LEAF_PENDING_INIT                     0 /* RWI-V */
#define NV_CTRL_VIRTUAL_INTR_LEAF_PENDING_INTR                     1 /* R---V */
#define NV_CTRL_VIRTUAL_INTR_LEAF_PENDING_CLEAR                    1 /* -W--V */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_SET(i)           (0x00B66820+(i)*4) /* RW-4A */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_SET__SIZE_1                       2 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_SET_VALUE                      31:0 /* RWIVF */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_SET_VALUE_INIT                    0 /* RWI-V */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_SET_VECTOR(i)                   (i) /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_SET_VECTOR_ENABLE                 1 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_SET_VECTOR_ENABLED                1 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_SET_VECTOR_DISABLED               0 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_CLEAR(i)         (0x00B66840+(i)*4) /* RW-4A */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_CLEAR__SIZE_1                     2 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_CLEAR_VALUE                    31:0 /* RWIVF */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_CLEAR_VALUE_INIT                  0 /* RWI-V */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_CLEAR_VECTOR(i)                 (i) /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_CLEAR_VECTOR_DISABLE              1 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_CLEAR_VECTOR_ENABLED              1 /*       */
#define NV_CTRL_VIRTUAL_INTR_LEAF_EN_CLEAR_VECTOR_DISABLED             0 /*       */
#define NV_CTRL_VIRTUAL_INTR_RETRIGGER                    0x00B66870 /* -W-4R */
#define NV_CTRL_VIRTUAL_INTR_RETRIGGER_FIELD                     0:0 /* -WXVF */
#define NV_CTRL_VIRTUAL_INTR_RETRIGGER_FIELD_RETRIGGER             1 /* -W--V */
#define NV_CTRL_VIRTUAL_INTR_VECTORID                                       0x00B66874 /* C--4R */
#define NV_CTRL_VIRTUAL_INTR_VECTORID_VALUE                                       11:0 /* C--VF */
#define NV_CTRL_VIRTUAL_INTR_VECTORID_VALUE_CONSTANT 130 /* C---V */
#define NV_CTRL_CPU_INTR_LEAF_TRIGGER(i)                   (0x00B66C00+(i)*4) /* -W-4A */
#define NV_CTRL_CPU_INTR_LEAF_TRIGGER__SIZE_1       64 /*       */
#define NV_CTRL_CPU_INTR_LEAF_TRIGGER_VECTOR                             11:0 /* -WXVF */
#define NV_CTRL_CPU_DOORBELL_VECTORID                                      0x00B6687C /* C--4R */
#define NV_CTRL_CPU_DOORBELL_VECTORID_VALUE                                      11:0 /* C--VF */
#define NV_CTRL_CPU_DOORBELL_VECTORID_VALUE_CONSTANT 129 /* C---V */
#define NV_CTRL_SW_INTR_NOSTALL_VECTORID                                         0x00B6688C /* C--4R */
#define NV_CTRL_SW_INTR_NOSTALL_VECTORID_VALUE                                         11:0 /* C--VF */
#define NV_CTRL_SW_INTR_NOSTALL_VECTORID_VALUE_CONSTANT 31 /* C---V */
// 
// --------------------------------------------------------------------------------
