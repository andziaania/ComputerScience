#ifndef VECTOR
#define VECTOR

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "vector.h"

const int INITIAL_CAPACITY = 16;


typedef struct Vector {
    int *data;
    int size;
    int capacity;
} Vector;



Vector *v_init(unsigned int initial_capacity);

Vector *v_empty_init();

void v_destroy(Vector *vector);

size_t v_size(Vector *vector);

size_t v_capacity(Vector *vector);

bool v_is_empty(Vector *vector);

int v_at(Vector *vector, unsigned int position);

void v_push(Vector *vector, int value);



#endif
