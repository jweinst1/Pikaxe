#ifndef PIKAXE_PIK_MEM_H
#define PIKAXE_PIK_MEM_H

#include "pik_machine.h"

int pik_mem_init_capture(PikMachine* mach, size_t cap);

int pik_mem_init_inst(PikMachine* mach, size_t cap);

int pik_mem_init_all(PikMachine* mach, size_t cap);
/**
 * Releases ownership of the group string.
 * The string must be freed after it's done being
 * used.
 */
Pik_grchr_t* pik_mem_rel_capt(PikMachine* mach);
/**
 * Same as the group capture release, but for instructions
 */
Pik_ins_t* pik_mem_rel_inst(PikMachine* mach);

int pik_mem_grow_capture(PikMachine* mach, size_t addon);

int pik_mem_grow_inst(PikMachine* mach, size_t addon);

void pik_mem_del_mach(PikMachine* mach);


#endif // PIKAXE_PIK_MEM_H
