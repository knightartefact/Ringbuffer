/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ringbuf
*/

#include <stdlib.h>
#include <stdio.h>
#include "ringbuf.h"

int ringbuf_init(ringbuf_t *ringbuf, size_t capacity)
{
    ringbuf->data = malloc(sizeof(char) * capacity);
    if (ringbuf->data == NULL) {
        perror("malloc()");
        return -1;
    }
    ringbuf->capacity = capacity;
    ringbuf->read_index = 0;
    ringbuf->write_index = 0;
    ringbuf->size = 0;
    return 0;
}

ringbuf_t *ringbuf_new(size_t capacity)
{
    ringbuf_t *ringbuf = malloc(sizeof(ringbuf_t));

    if (ringbuf == NULL) {
        perror("malloc()");
        return NULL;
    }
    if (ringbuf_init(ringbuf, capacity) == -1) {
        return NULL;
    }
    return ringbuf;
}

void ringbuf_destroy(ringbuf_t *ringbuf)
{
    free(ringbuf->data);
    free(ringbuf);
}
