/*
** EPITECH PROJECT, 2023
** Ringbuffer
** File description:
** ringbuf
*/

#ifndef RINGBUF_H_
    #define RINGBUF_H_
    #include <stddef.h>
    #include <stdbool.h>

    typedef struct ringbuf_s ringbuf_t;

    struct ringbuf_s {
        char *data;
        size_t capacity;
        size_t size;
        size_t read_index;
        size_t write_index;
    };

/**
 * @brief Initialize a ring buffer.
 * @param ringbuf The ringbuffer to initialise.
 * @param capacity The capacity of the ringbuffer (in bytes).
 * @return 0 if the ringbuffer was successfuly initialized.
*/
int ringbuf_init(ringbuf_t *ringbuf, size_t capacity);

/**
 * @brief Create a new ring buffer.
 * @param capacity The capacity of the ringbuffer (in bytes).
 * @return A newly created ringbuffer pointer or NULL if an error occurred.
*/
ringbuf_t *ringbuf_new(size_t capacity);

/**
 * @brief Destroy a ringbuffer.
 * @param ringbuf The ringbuffer you want to destroy.
*/
void ringbuf_destroy(ringbuf_t *ringbuf);

/**
 * @brief Push a character into the ringbuffer.
 * @param ringbuf The ringbuffer to push the character into.
 * @param data The character to push into the ringbuffer.
 * @return 0 if the character was pushed or -1 if the ringbuffer is full.
*/
int ringbuf_push(ringbuf_t *ringbuf, char data);

/**
 * @brief Push a character buffer into the ringbuffer.
 * @param ringbuf The destination ringbuffer to push the source buffer into.
 * @param data The source character buffer.
 * @param size The size (in bytes) of the source charcter buffer.
 * @return 0 if the ringbuffer was pushed or -1 if the ringbuffer is full.
*/
int ringbuf_push_buffer(ringbuf_t *ringbuf, char *data, size_t size);

/**
 * @brief Pop a character from the ringbuffer.
 * @param ringbuf The ringbuffer to pop a character from.
 * @param data The character that was popped from the ringbuffer.
 * @return 0 if the character was pushed or -1 if the ringbuffer is empty.
*/
int ringbuf_pop(ringbuf_t *ringbuf, char *data);

/**
 * @brief Pop a character buffer from the ringbuffer.
 * @param ringbuf The ringbuffer to pop the characters from.
 * @param data The destination character buffer (where popped characters go).
 * @param size The number of characters to pop from the source ringbuffer.
 * @return 0 if the character was pushed or -1 if the ringbuffer is full.
*/
int ringbuf_pop_buffer(ringbuf_t *ringbuf, char *data, size_t *size);

/**
 * @brief Get the size of a ringbuffer (number of elements present).
 * @param ringbuf The ringbuffer to get the data from.
 * @return The size of the ringbuffer.
*/
size_t ringbuf_size(ringbuf_t *ringbuf);

/**
 * @brief Get the total capacity of a ringbuffer.
 * @param ringbuf The ringbuffer to get the data from.
 * @return The capacity of the ringbuffer.
*/
size_t ringbuf_capacity(ringbuf_t *ringbuf);

/**
 * @brief Get the remaining free space of a ringbuffer.
 * @param ringbuf The ringbuffer to get the data from.
 * @return The number of free slots in the ringbuffer.
*/
size_t ringbuf_free_space(ringbuf_t *ringbuf);

/**
 * @brief Check if the ringbuffer is full.
 * @param ringbuf The ringbuffer to get the data from.
 * @return True if the ringbuffer is full and False otherwise.
*/
bool ringbuf_is_full(ringbuf_t *ringbuf);

/**
 * @brief Check if the ringbuffer is empty.
 * @param ringbuf The ringbuffer to get the data from.
 * @return True if the ringbuffer is empty and False otherwise.
*/
bool ringbuf_is_empty(ringbuf_t *ringbuf);

/**
 * @brief Clears all the data contained by the buffer by resetting write/read heads to default positions.
 * @param ringbuf The ringbuffer to clear.
*/
void ringbuf_flush(ringbuf_t *ringbuf);

/**
 * @brief Search for a character in the ringbuffer.
 * @param ringbuf The ringbuffer to search.
 * @param ref The character to find.
 * @return The index of the character in the ringbuffer or -1 if not present.
*/
int ringbuf_search_char(ringbuf_t *ringbuf, char ref);

#endif /* !RINGBUF_H_ */
