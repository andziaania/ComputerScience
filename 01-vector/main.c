#include <stdio.h>
#include <assert.h>

#include "vector.h"
#include "vector.c"



void test_initialization();

void test_determine_capacity();



int main() {
    test_initialization();
    test_determine_capacity();
    return 0;
}

void test_initialization() {
    Vector *v = vector_init(3);

    assert(v->size == 0);
    assert(v->capacity == 16);

    vector_destroy(v);
    printf("OK -- test_initialization\n");

}   



void test_determine_capacity() {
    int val1 = determine_capacity(0);
    assert(val1 == 16);

    int val2 = determine_capacity(16);
    assert(val2 == 32);

    int val3 = determine_capacity(17);
    assert(val3 == 32);

    int val4 = determine_capacity(32);
    assert(val4 == 64);

    printf("OK -- test_determine_capacity\n");
}
