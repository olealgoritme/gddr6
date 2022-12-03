// --------------------------------------------------------------------------------
// 
#define NV_PTIMER                             0x00009FFF:0x00009000 /* RW--D */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0                     0x00009084 /* RW-4R */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_TO                         0:0 /* RWXVF */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_TO_ERROR                   0x1 /* RW--V */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_TO_CLEAR                   0x0 /* -W--V */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_TO_NONE                    0x0 /* RW--V */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_WRITE                      1:1 /* RWXVF */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_WRITE_TRUE                 0x1 /* RW--V */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_WRITE_FALSE                0x0 /* RW--V */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_ADDR                      23:2 /* RWXVF */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_FECS_TGT                 31:31 /* RWXVF */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_FECS_TGT_TRUE              0x1 /* RW--V */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_0_FECS_TGT_FALSE             0x0 /* RW--V */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_1                     0x00009088 /* RW-4R */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_1_DATA                      31:0 /* RWXVF */
#define NV_PTIMER_PRI_TIMEOUT_SAVE_1_DATA_WAS_READ              0x0 /* RW--V */
#define NV_PTIMER_PRI_TIMEOUT_FECS_ERRCODE               0x0000908C /* RW-4R */
#define NV_PTIMER_PRI_TIMEOUT_FECS_ERRCODE_DATA                31:0 /* RWXVF */
#define NV_PTIMER_ALARM_0                                0x00009420 /* RW-4R */
#define NV_PTIMER_ALARM_0_NSEC                                 31:5 /* RWIUF */
#define NV_PTIMER_ALARM_0_NSEC_INIT                             0x0 /* RWI-V */
#define NV_PTIMER_TIMER_INTR_VECTOR                    0x00009440 /*       */
#define NV_PTIMER_TIMER_INTR_VECTOR_ID              7:0 /*       */
#define NV_PTIMER_TIMER_INTR_VECTOR_ID_VALUE  148 /*       */
#define NV_PTIMER_PRI_TMR_CG1                             0x00009600 /* RW-4R */
#define NV_PTIMER_PRI_TMR_CG1_MONITOR_CG_EN                      0:0 /* RWIVF */
#define NV_PTIMER_PRI_TMR_CG1_MONITOR_CG_EN_ENABLED       0x00000001 /* RW--V */
#define NV_PTIMER_PRI_TMR_CG1_MONITOR_CG_EN_DISABLED      0x00000000 /* RWI-V */
#define NV_PTIMER_PRI_TMR_CG1_MONITOR_CG_EN__PROD         0x00000000 /* RW--V */
#define NV_PTIMER_PRI_TMR_CG1_SLCG                                1:1 /* RWIVF */
#define NV_PTIMER_PRI_TMR_CG1_SLCG_ENABLED                0x00000000 /* RW--V */
#define NV_PTIMER_PRI_TMR_CG1_SLCG_DISABLED               0x00000001 /* RWI-V */
#define NV_PTIMER_PRI_TMR_CG1_SLCG__PROD                  0x00000000 /* RW--V */
// 
// --------------------------------------------------------------------------------
