#include <stdio.h>

#include "vector.h"

int determine_capacity(int initial_capacity);


Vector *vector_init(int initial_capacity) {
    
    Vector *vector = malloc(sizeof(vector));

    int capacity = determine_capacity(initial_capacity);

    vector->size = 0;
    vector->capacity = capacity;
    vector->data = malloc(sizeof(vector) * capacity);

}

void vector_destroy(Vector *vector) {
    free(vector->data);
    free(vector);
}

int determine_capacity(int initial_capacity) {
    int capacity = INITIAL_CAPACITY;
    while (initial_capacity / capacity > 0) {
        capacity <<= 1;
    }
    return capacity;
}
