
; int wv_priority_queue_shrink_to_fit(wv_priority_queue_t *q)

SECTION code_adt_wv_priority_queue

PUBLIC _wv_priority_queue_shrink_to_fit

EXTERN _bv_priority_queue_shrink_to_fit

defc _wv_priority_queue_shrink_to_fit = _bv_priority_queue_shrink_to_fit
