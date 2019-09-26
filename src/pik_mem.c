#include "pik_mem.h"

int pik_mem_init_capture(PikMachine* mach, size_t cap)
{
    mach->capture = malloc(sizeof(Pik_grchr_t) * cap);
    if(mach->capture == NULL) {
        sprintf(mach->err_mes, "Err:%s\n", "Cannot initialize capture buffer");
        return 0;
    }
    mach->capture_len = 0;
    mach->capture_cap = cap;
    return 1;
}