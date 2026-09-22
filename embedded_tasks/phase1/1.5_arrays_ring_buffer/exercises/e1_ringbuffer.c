#include <stddef.h>
#include <stdint.h>
#include "e1_ringbuffer.h"

void rb_init(RingBuffer_t *rb)
{
    if (rb == NULL) return;

    rb->head = 0;
    rb->tail = 0;
}

RbStatus_t rb_put(RingBuffer_t *rb, uint8_t byte)
{
    if (rb == NULL) return RB_NULL_PTR;

    uint16_t next = (uint16_t)((rb->head + 1U) & RB_MASK);
    if(next == rb->tail) return RB_FULL;

    rb->data[rb->head] = byte;
    rb->head = next;

    return RB_OK;
}

RbStatus_t rb_get(RingBuffer_t *rb, uint8_t *out)
{
    if (rb == NULL || out == NULL) return RB_NULL_PTR;

    if (rb->head == rb->tail) return RB_EMPTY;

    *out = rb->data[rb->tail];
    rb->tail = (uint16_t)((rb->tail + 1U) & RB_MASK);

    return RB_OK;
}

uint16_t rb_count(const RingBuffer_t *rb)
{
    if (rb == NULL) return 0U;

    return (uint16_t)((rb->head - rb->tail) & RB_MASK);
}

uint8_t rb_is_empty(const RingBuffer_t *rb)
{
    return (rb == NULL || rb->head == rb->tail) ? 1U : 0U;
}

uint8_t rb_is_full(const RingBuffer_t *rb)
{
    if (rb == NULL) return 1U;

    return (((rb-head + 1U) & RB_MASK) == rb->tail) ? 1U : 0U;
}