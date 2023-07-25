/*
** EPITECH PROJECT, 2023
** ringbuffer
** File description:
** ringbuf_init_test
*/

#include <criterion/criterion.h>
#include "ringbuf.h"

Test(init, init_success)
{
    ringbuf_t rb;

    cr_assert(ringbuf_init(&rb, 130) == 0);
    cr_expect(rb.capacity == 130);
    cr_expect(rb.size == 0);
    cr_expect(rb.read_index == 0);
    cr_expect(rb.write_index == 0);
    cr_assert(rb.data != NULL);
    free(rb.data);
}

Test(init, init_failure)
{
    ringbuf_t rb;
    int return_status = ringbuf_init(&rb, 0);

    cr_assert(return_status == -1, "Expected -1 but got %d.", ringbuf_init(&rb, 0));
}
