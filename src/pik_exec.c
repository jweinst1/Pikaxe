#include "pik_exec.h"

int pik_exec_on_string(PikMachine* mach, const char* string)
{
    // pre execution prep
    Pik_grchr_t* capt_head;
    Pik_ins_t* ins_head;
    if(PIKAXE_ERR_HAS(mach))
        return 0;
    if(!PIKAXE_IS_INITIALIZED(mach)) {
        sprintf(mach->err_mes, "ERR: %s\n", "Tried to execute on non-initialized machine");
        return 0;
    }
    mach->last_seg = mach->capture;
    capt_head = mach->capture;
    ins_head = mach->instructions;
    goto EXEC_STATE_BASE;
EXEC_STATE_BASE:
    switch(*ins_head) {
        default:
            goto EXEC_STATE_FAILED;
    }
EXEC_STATE_FAILED:
    return 0;
EXEC_STATE_GOOD_END:
    return 1;
}