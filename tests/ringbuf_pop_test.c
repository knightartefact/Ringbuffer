/*
** EPITECH PROJECT, 2023
** ringbuffer
** File description:
** ringbuf_pop_test
*/

#include <criterion/criterion.h>
#include "ringbuf.h"

ringbuf_t *setup_ringbuf(void)
{
    ringbuf_t *rb = ringbuf_new(32);

    ringbuf_push_buffer(rb, "Hello, world!", 13);
    return rb;
}

Test(pop, empty)
{
    ringbuf_t *rb = ringbuf_new(10);
    char data = 0;

    cr_assert(ringbuf_pop(rb, &data) == -1);
    ringbuf_destroy(rb);
}

Test(pop, pop_single_char)
{
    ringbuf_t *rb = setup_ringbuf();
    char data = 0;

    cr_assert(ringbuf_pop(rb, &data) == 0);
    cr_expect(data == 'H');
    cr_expect(rb->read_index == 1);
    cr_expect(rb->write_index == 13);
    cr_expect(rb->size == 12);
    ringbuf_destroy(rb);
}

Test(pop, pop_multiple_chars)
{
    ringbuf_t *rb = setup_ringbuf();
    char data = 0;

    cr_assert(ringbuf_pop(rb, &data) == 0);
    cr_expect(data == 'H');
    cr_expect(rb->read_index == 1);
    cr_expect(rb->write_index == 13);
    cr_expect(rb->size == 12);
    cr_assert(ringbuf_pop(rb, &data) == 0);
    cr_expect(data == 'e');
    cr_expect(rb->read_index == 2);
    cr_expect(rb->write_index == 13);
    cr_expect(rb->size == 11);
    cr_assert(ringbuf_pop(rb, &data) == 0);
    cr_expect(data == 'l');
    cr_expect(rb->read_index == 3);
    cr_expect(rb->write_index == 13);
    cr_expect(rb->size == 10);
    cr_assert(ringbuf_pop(rb, &data) == 0);
    cr_expect(data == 'l');
    cr_expect(rb->read_index == 4);
    cr_expect(rb->write_index == 13);
    cr_expect(rb->size == 9);
    cr_assert(ringbuf_pop(rb, &data) == 0);
    cr_expect(data == 'o');
    cr_expect(rb->read_index == 5);
    cr_expect(rb->write_index == 13);
    cr_expect(rb->size == 8);
    ringbuf_destroy(rb);
}
