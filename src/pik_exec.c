#include "pik_exec.h"

int pik_exec_on_string(PikMachine* mach, const char* string)
{
    if(PIKAXE_ERR_HAS(mach))
        return 0;
    goto EXEC_STATE_BASE;
EXEC_STATE_BASE:
    // ...
EXEC_STATE_GOOD_END:
    return 1;
}