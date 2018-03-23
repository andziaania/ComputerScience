#ifndef VECTOR
#define VECTOR

#include <stdlib.h>

const int INITIAL_CAPACITY = 16;


typedef struct Vector {
    int *data;
    int size;
    int capacity;
} Vector;



#endif
