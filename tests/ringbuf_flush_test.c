/*
** EPITECH PROJECT, 2023
** ringbuffer
** File description:
** ringbuf_flush_test
*/

#include <criterion/criterion.h>
#include "ringbuf.h"

Test(flush, flush_success)
{
    ringbuf_t *rb = ringbuf_new(10);

    ringbuf_push_buffer(rb, "Hello!", 6);
    ringbuf_flush(rb);
    cr_assert(rb->capacity == 10);
    cr_assert(rb->size == 0);
    cr_assert(rb->read_index == 0);
    cr_assert(rb->write_index == 0);
    ringbuf_destroy(rb);
}
