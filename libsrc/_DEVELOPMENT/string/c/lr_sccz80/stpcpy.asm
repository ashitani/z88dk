
; char *stpcpy(char * restrict s1, const char * restrict s2)

XLIB stpcpy

LIB asm_stpcpy

stpcpy:

   pop af
   pop hl
   pop de
   
   push de
   push hl
   push af
   
   jp asm_stpcpy
