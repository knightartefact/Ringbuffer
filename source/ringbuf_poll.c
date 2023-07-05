/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ringbuf_poll
*/

#include "ringbuf.h"

size_t ringbuf_size(ringbuf_t *ringbuf)
{
    return ringbuf->size;
}

size_t ringbuf_capacity(ringbuf_t *ringbuf)
{
    return ringbuf->capacity;
}

size_t ringbuf_free_space(ringbuf_t *ringbuf)
{
    return ringbuf->capacity - ringbuf->size;
}

bool ringbuf_is_full(ringbuf_t *ringbuf)
{
    return ringbuf->size == ringbuf->capacity;
}

bool ringbuf_is_empty(ringbuf_t *ringbuf)
{
    return ringbuf->size == 0;
}
