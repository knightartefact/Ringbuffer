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

Test(push_buffer, push_hello)
{
    ringbuf_t *rb = ringbuf_new(28);

    cr_assert(ringbuf_push_buffer(rb, "Hello!", 6) == 6);
    cr_expect_arr_eq(rb->data, "Hello!", 6);
    cr_expect(rb->size == 6);
    cr_expect(rb->write_index == 6);
    cr_expect(rb->read_index == 0);
    ringbuf_destroy(rb);
}

Test(push_buffer, push_overflow)
{
    ringbuf_t *rb = ringbuf_new(10);
    int pushed_bytes = ringbuf_push_buffer(rb, "Hello, World!", 13);

    cr_assert(pushed_bytes == 10, "Expected 10 but got %d.", pushed_bytes);
    cr_expect_arr_eq(rb->data, "Hello, Wor", 10);
    cr_expect(rb->size == 10);
    cr_expect(rb->write_index == 0);
    cr_expect(rb->read_index == 0);
    ringbuf_destroy(rb);
}

Test(push_buffer, already_full)
{
    ringbuf_t *rb = ringbuf_new(13);

    ringbuf_push_buffer(rb, "Hello, World!!!!", 16);
    cr_assert(ringbuf_push_buffer(rb, "Already full!", 13) == -1);
    cr_expect_arr_eq(rb->data, "Hello, World!", 10);
    cr_expect(rb->size == 13);
    cr_expect(rb->write_index == 0);
    cr_expect(rb->read_index == 0);
    ringbuf_destroy(rb);
}

Test(push_buffer, loopback)
{
    ringbuf_t *rb = ringbuf_new(8);

    rb->read_index = 5; // Just offset the read/write indexes to force loopback
    rb->write_index = 5;
    cr_assert(ringbuf_push_buffer(rb, "Hi guys!!!", 10) == 8);
    cr_expect(rb->read_index == 5);
    cr_expect(rb->write_index == 5);
    cr_expect(rb->size == 8);
    ringbuf_destroy(rb);
}
