/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ringbuf_actions
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ringbuf.h"

int ringbuf_push(ringbuf_t *ringbuf, char data)
{
    if (ringbuf->size >= ringbuf->capacity) {
        return -1;
    }
    ringbuf->data[ringbuf->write_index] = data;
    ringbuf->write_index = (ringbuf->write_index + 1) % ringbuf->capacity;
    ringbuf->size++;
    return 0;
}

int ringbuf_pop(ringbuf_t *ringbuf, char *data)
{
    if (ringbuf->size <= 0)
        return -1;
    (*data) = ringbuf->data[ringbuf->read_index];
    ringbuf->read_index = (ringbuf->read_index + 1) % ringbuf->capacity;
    ringbuf->size--;
    return 0;
}

int ringbuf_push_buffer(ringbuf_t *ringbuf, char *data, size_t size)
{
    if (ringbuf_is_full(ringbuf))
        return -1;
    for (size_t i = 0; i < size; i++) {
        if (ringbuf_push(ringbuf, data[i]) == -1)
            return i + 1;
    }
    return size;
}

int ringbuf_pop_buffer(ringbuf_t *ringbuf, char *data, size_t size)
{
    char temp[1024] = {0};

    if (ringbuf_is_full(ringbuf))
        return -1;
    if ((size) >= ringbuf->size)
        (size) = ringbuf->size;
    for (size_t i = 0; i < (size); i++) {
        if (ringbuf_pop(ringbuf, &temp[i]) == -1) {
            return (i + 1);
        }
    }
    memcpy(data, temp, size);
    return size;
}

void ringbuf_flush(ringbuf_t *ringbuf)
{
    ringbuf->size = 0;
    ringbuf->write_index = 0;
    ringbuf->read_index = 0;
}
