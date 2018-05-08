#ifndef VECTOR
#define VECTOR

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "vector.h"

const int INITIAL_CAPACITY = 16;
const float REDUCTION_FACTOR = 0.25;

typedef struct Vector {
    int *data;
    size_t size;
    size_t capacity;
} Vector;



Vector *v_init(size_t initial_capacity);

Vector *v_empty_init();

void v_destroy(Vector *vector);

size_t v_size(Vector *vector);

size_t v_capacity(Vector *vector);

bool v_is_empty(Vector *vector);

int v_at(Vector *vector, size_t position);

void v_push(Vector *vector, int value);

/**
 * When popping an item, if size is 1/4 of capacity, resize to half
 * @param vector
 * @return
 */
int v_pop(Vector *vector);

void v_insert(Vector *vector, size_t index, int value);

void v_prepend(Vector *vector, int value);

void v_delete(Vector *vector, size_t index);

int v_find(Vector *v, int item);

void v_remove(Vector *v, int item);

/***** internal methods *****/

size_t get_the_round_up_to_the_next_power_of_two(size_t value);

void double_capacitize_vector_if_needed(Vector* vector);

void half_capacitize_vector_if_needed(Vector *vector);

void re_capacitize_vector(Vector *vector, size_t new_capacity);

void setAt(Vector *vector, size_t index, int value);

#endif
