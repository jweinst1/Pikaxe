#include "pik_mem.h"


static int _pik_mem_init(PikMachine* mach, size_cap, int capture, int inst)
{
    if(capture) {
        mach->capture = malloc(sizeof(Pik_grchr_t) * cap);
        if(mach->capture == NULL) {
            sprintf(mach->err_mes, "Err:%s\n", "Cannot initialize capture buffer");
            return 0;
        }
        mach->capture_len = 0;
        mach->capture_cap = cap;
        return 1;   
    }
    
    if(inst) {
        mach->instructions = malloc(sizeof(Pik_ins_t) * cap);
        if(mach->instructions == NULL) {
            sprintf(mach->err_mes, "Err:%s\n", "Cannot initialize instruction buffer");
            return 0;
        }
        mach->instructions_len = 0;
        mach->instructions_cap = cap;
        return 1;    
    }
}

int pik_mem_init_capture(PikMachine* mach, size_t cap)
{
    return _pik_mem_init(mach, cap, 1, 0);
}

int pik_mem_init_inst(PikMachine* mach, size_t cap)
{
    return _pik_mem_init(mach, cap, 0, 1);
}

int pik_mem_init_all(PikMachine* mach, size_t cap)
{
    return _pik_mem_init(mach, cap, 1, 1);
}

Pik_grchr_t* pik_mem_rel_capt(PikMachine* mach)
{
    Pik_grchr_t* gotcap = mach->capture;
    mach->capture = NULL;
    mach->capture_cap = 0;
    mach->capture_len = 0;
    return gotcap;
}

Pik_ins_t* pik_mem_rel_inst(PikMachine* mach)
{
    Pik_ins_t* gotins = mach->instructions;
    mach->instructions = NULL;
    mach->instructions_cap = 0;
    mach->instructions_len = 0;
    return gotins;  
}



int pik_mem_grow_capture(PikMachine* mach, size_t addon)
{
    // to do
    return 1;
}

int pik_mem_grow_inst(PikMachine* mach, size_t addon)
{
    // to do
    return 1;
}