#ifndef PIKAXE_PIK_MACHINE_H
#define PIKAXE_PIK_MACHINE_H

#include "compiler-info.h"

#ifndef PIKAXE_ERR_MAX_LEN
#define PIKAXE_ERR_MAX_LEN 150
#endif

/**
 * This is a special character type intended to not be null terminated.
 * it is grouped by chars 0x2 and 0x3, for starting and ending a group.
 * It is terminated with 0x4
 */
typedef char Pik_grchr_t;

typedef enum {
    PIK_INST_STOP = 1,
    PIK_INST_CMP_S = 2,
    PIK_INST_CAP_S = 3,
    PIK_INST_GRP_N = 4,
    PIK_INST_GRP_U = 5,
    PIK_INST_GRP_D = 6,
    PIK_INST_GRP_RE = 7
} Pik_inst_t;

typedef unsigned char Pik_ins_t;

typedef struct {
    size_t capture_len;
    size_t capture_cap;
    Pik_grchr_t* capture;
    Pik_grchr_t* last_seg;
    size_t instructions_len;
    size_t instructions_cap;
    Pik_ins_t* instructions;
    char err_mes[PIKAXE_ERR_MAX_LEN];
} PikMachine;

#define PIKAXE_ERR_CLEAR(mach) (mach->err_mes[0] = '\0')
#define PIKAXE_ERR_HAS(mach) (mach->err_mes[0] != '\0')

#define PIKAXE_IS_INITIALIZED(mach) (mach->instructions != NULL && \
                                     mach->instructions_cap != 0 && \
                                     mach->capture != NULL && \
                                     mach->capture_cap != 0)

#endif // PIKAXE_PIK_MACHINE_H