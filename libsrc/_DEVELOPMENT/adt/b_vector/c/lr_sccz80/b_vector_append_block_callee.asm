
; void *b_vector_append_block(b_vector_t *v, size_t n)

XDEF b_vector_append_block_callee

b_vector_append_block_callee:

   pop hl
   pop bc
   ex (sp),hl
   
   INCLUDE "../../z80/asm_b_vector_append_block.asm"
