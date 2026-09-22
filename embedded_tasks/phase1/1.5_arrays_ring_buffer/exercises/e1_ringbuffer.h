#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <stdint.h>

#define RB_SIZE 64U
#define RB_MASK (RB_SIZE - 1U)

typedef enum 
{
    RB_OK = 0,
    RB_FULL,
    RB_EMPTY,
    RB_NULL_PTR
} RbStatus_t;

typedef struct 
{
    uint8_t data[RB_SIZE];
    volatile uint16_t head;
    volatile uint16_t tail;
} RingBuffer_t;

void rb_init (RingBuffer_t *rb);
RbStatus_t rb_put (RingBuffer_t *rb, uint8_t byte);
RbStatus_t rb_get (RingBuffer_t *rb, uint8_t *out);
uint16_t rb_counter(const RingBuffer_t *rb);
uint8_t rb_is_empty(const RingBuffer_t *rb);
uint8_t rb_is_full(const RingBuffer_t *rb);

#endif