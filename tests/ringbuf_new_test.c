/*
** EPITECH PROJECT, 2023
** ringbuffer
** File description:
** ringbuf_new_test
*/

#include <criterion/criterion.h>
#include "ringbuf.h"

Test(creation, new_success)
{
    ringbuf_t *rb = ringbuf_new(10);

    cr_assert(rb != NULL, "Expected ringbuf to be not NULL.");
    ringbuf_destroy(rb);
}

Test(creation, new_fail_size_0)
{
    ringbuf_t *rb = ringbuf_new(0);

    cr_assert(rb == NULL, "Expected ringbuffer to be NULL.");
}
