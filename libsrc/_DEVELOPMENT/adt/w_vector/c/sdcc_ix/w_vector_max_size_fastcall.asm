
; void *w_vector_max_size_fastcall(w_vector_t *v)

SECTION code_adt_w_vector

PUBLIC _w_vector_max_size_fastcall

defc _w_vector_max_size_fastcall = asm_w_vector_max_size

INCLUDE "adt/w_vector/z80/asm_w_vector_max_size.asm"
