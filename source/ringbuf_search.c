/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ringbuf_search
*/

#include "ringbuf.h"

int ringbuf_search_char(ringbuf_t *ringbuf, char ref)
{
    for (size_t i = ringbuf->read_index; i < ringbuf->write_index; i++) {
        if (ringbuf->data[i] == ref) {
            return i + 1;
        }
    }
    return -1;
}
