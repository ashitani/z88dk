
; void *wa_priority_queue_pop(wa_priority_queue_t *q)

SECTION code_adt_wa_priority_queue

PUBLIC _wa_priority_queue_pop

EXTERN _wa_priority_queue_pop_fastcall

_wa_priority_queue_pop:

   pop af
   pop hl
   
   push hl
   push af

   jp _wa_priority_queue_pop_fastcall
