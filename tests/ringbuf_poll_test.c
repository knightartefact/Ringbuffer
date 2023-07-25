/*
** EPITECH PROJECT, 2023
** ringbuffer
** File description:
** ringbuf_poll_test
*/

#include <criterion/criterion.h>
#include "ringbuf.h"

Test(poll, size_empty)
{
    ringbuf_t *rb = ringbuf_new(213);

    cr_assert(ringbuf_size(rb) == 0);
    ringbuf_destroy(rb);
}

Test(poll, size_5)
{
    ringbuf_t *rb = ringbuf_new(10);

    ringbuf_push_buffer(rb, "Hello", 5);
    cr_assert(ringbuf_size(rb) == 5);
    ringbuf_destroy(rb);
}

Test(poll, capacity)
{
    size_t cap = 1090;
    ringbuf_t *rb = ringbuf_new(cap);

    cr_assert(ringbuf_capacity(rb) == cap);
    ringbuf_destroy(rb);
}

Test(poll, free_space)
{
    size_t cap = 142;
    ringbuf_t *rb = ringbuf_new(cap);

    ringbuf_push_buffer(rb, "It's me, Mario!", 15);
    cr_assert(ringbuf_free_space(rb) == (cap - 15));
    ringbuf_destroy(rb);
}

Test(poll, free_space_full)
{
    size_t cap = 20;
    ringbuf_t *rb = ringbuf_new(cap);

    ringbuf_push_buffer(rb, "It's me, Mario!", 15);
    ringbuf_push_buffer(rb, "And Luigi!", 10);
    cr_assert(ringbuf_free_space(rb) == 0);
    ringbuf_destroy(rb);
}

Test(poll, is_empty_true)
{
    size_t cap = 1090;
    ringbuf_t *rb = ringbuf_new(cap);

    cr_assert(ringbuf_is_empty(rb) == true);
    ringbuf_destroy(rb);
}

Test(poll, is_empty_false)
{
    size_t cap = 1090;
    ringbuf_t *rb = ringbuf_new(cap);

    ringbuf_push(rb, 'A');
    cr_assert(ringbuf_is_empty(rb) == false);
    ringbuf_destroy(rb);
}

Test(poll, is_full_true)
{
    size_t cap = 40;
    ringbuf_t *rb = ringbuf_new(cap);

    ringbuf_push_buffer(rb, "This is a simple message to fill the ringbuf.", 45);
    cr_assert(ringbuf_is_full(rb) == true);
    ringbuf_destroy(rb);
}

Test(poll, is_full_false)
{
    size_t cap = 40;
    ringbuf_t *rb = ringbuf_new(cap);

    ringbuf_push_buffer(rb, "This is a simple message.", 25);
    cr_assert(ringbuf_is_full(rb) == false);
    ringbuf_destroy(rb);
}
