
; int strcmp(const char *s1, const char *s2)

XDEF strcmp_callee

strcmp_callee:

   pop af
   pop hl
   pop de
   push af
   
   INCLUDE "../../z80/asm_strcmp.asm"
