/*
** EPITECH PROJECT, 2023
** ringbuffer
** File description:
** ringbuf_push_test
*/

#include <criterion/criterion.h>
#include "ringbuf.h"

Test(push, push_to_empty)
{
    ringbuf_t *rb = ringbuf_new(10);
    int return_status = ringbuf_push(rb, 'G');

    cr_assert(return_status == 0);
    cr_assert(rb->size == 1);
    cr_expect(rb->data[rb->read_index] == 'G');
    cr_expect(rb->write_index == 1);
    ringbuf_destroy(rb);
}

Test(push, push_multiple_bytes)
{
    ringbuf_t *rb = ringbuf_new(10);

    cr_assert(ringbuf_push(rb, 'G') == 0);
    cr_assert(ringbuf_push(rb, 'o') == 0);
    cr_assert(ringbuf_push(rb, 'o') == 0);
    cr_assert(ringbuf_push(rb, 'd') == 0);
    cr_assert(rb->size == 4);
    cr_expect(rb->data[rb->read_index] == 'G');
    cr_expect(rb->write_index == 4);
    cr_assert_arr_eq(rb->data, "Good", 4);
    ringbuf_destroy(rb);
}

Test(push, push_to_full)
{
    ringbuf_t *rb = ringbuf_new(1);

    cr_assert(ringbuf_push(rb, 'A') == 0);
    cr_assert(ringbuf_push(rb, 'B') == -1);
    ringbuf_destroy(rb);
}
