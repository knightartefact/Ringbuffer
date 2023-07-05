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
    for (size_t i = 0; i < size; i++) {
        if (ringbuf_push(ringbuf, data[i]) == -1)
            return -1;
    }
    return 0;
}

int ringbuf_pop_buffer(ringbuf_t *ringbuf, char *data, size_t *size)
{
    char temp[1024] = {0};
    int status = 0;

    if (size == NULL)
        return -1;
    if ((*size) >= ringbuf->size)
        (*size) = ringbuf->size;
    for (size_t i = 0; i < (*size); i++) {
        status = ringbuf_pop(ringbuf, &temp[i]);
        if (status == -1) {
            (*size) = i;
            break;
        }
    }
    memcpy(data, temp, (*size));
    return 0;
}

void ringbuf_flush(ringbuf_t *ringbuf)
{
    ringbuf->size = 0;
    ringbuf->write_index = 0;
    ringbuf->read_index = 0;
}
