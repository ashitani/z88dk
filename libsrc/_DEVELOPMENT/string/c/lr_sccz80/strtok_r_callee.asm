
; char *strtok_r(char * restrict s, const char * restrict sep, char ** restrict lasts)

XDEF strtok_r_callee

strtok_r_callee:

   pop hl
   pop bc
   pop de
   ex (sp),hl
   
   INCLUDE "../../z80/asm_strtok_r.asm"
