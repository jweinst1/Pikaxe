#include "pik_mem.h"


static int _pik_mem_init(PikMachine* mach, size_t cap, int capture, int inst)
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
    
    return 1;
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

static int _pik_mem_grow(PikMachine* mach, size_t addon, int capt, int ins)
{
    if(capt) {
        mach->capture_cap += addon;
        mach->capture = realloc(mach->capture, mach->capture_cap);
        if(mach->capture == NULL) {
            sprintf(mach->err_mes, "Err:%s\n", "Cannot grow capture buffer");
            return 0;
        }
        return 1;
    }
    
    if(ins) {
        mach->instructions_cap += addon;
        mach->instructions = realloc(mach->instructions, mach->instructions_cap);
        if(mach->instructions == NULL) {
            sprintf(mach->err_mes, "Err:%s\n", "Cannot grow instructions buffer");
            return 0;
        }
        return 1;     
    }
    return 1;
}

int pik_mem_grow_capture(PikMachine* mach, size_t addon)
{
    return _pik_mem_grow(mach, addon, 1, 0);
}

int pik_mem_grow_inst(PikMachine* mach, size_t addon)
{
    return _pik_mem_grow(mach, addon, 0, 1);
}

void pik_mem_del_mach(PikMachine* mach)
{
    free(mach->capture);
    free(mach->instructions);
    mach->capture = NULL;
    mach->instructions = NULL;
    mach->capture_cap = 0;
    mach->instructions_cap = 0;
}