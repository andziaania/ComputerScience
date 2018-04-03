#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "vector.h"
#include "vector.c"

/**
 * Implement a vector - mutable array with automatic resizing
 *
 * */


void test_initialization() {
    Vector *v = v_init(3);

    assert(v_size(v) == 0);
    assert(v_capacity(v) == 16);

    v_destroy(v);
    printf("OK -- test_initialization\n");

}   

void test_empty_initialization() {
	Vector *v = v_empty_init();	

    assert(v_size(v) == 0);
    assert(v_capacity(v) == 16);

    v_destroy(v);
    printf("OK -- test_empty_initialization\n");
}

void test_v_is_empty_for_empty_initialization() {
	Vector *v = v_empty_init();	

    assert(v_is_empty(v));

    v_destroy(v);
    printf("OK -- test_v_is_empty_for_empty_initialization\n");
}

void test_v_push() {
	Vector *v = v_init(2);

	v_push(v, 5);
	assert(v_at(v, 0) == 5);
	assert(v_size(v) == 1);

	v_push(v, 4);
	assert(v_at(v, 0) == 5);
	assert(v_at(v, 1) == 4);
	assert(v_size(v) == 2);

	v_push(v, 3);
	assert(v_at(v,2) == 3);

	v_destroy(v);
	printf("OK -- test_v_push\n");
}

void test_v_push_adjusts_capacity() {
	Vector *v = v_empty_init();


	v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1);
	v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1); v_push(v, 1);
	v_push(v, 1); v_push(v, 1);

	assert(v_capacity(v) == 32);
	assert(v_size(v) == 18);
	assert(v_at(v, 16) == 1);
	assert(v_at(v, 17) == 1);

	v_destroy(v);
	printf("OK -- test test_v_push_adjusts_capacity\n");
}


void test_v_at() {
	Vector *v = v_init(5);

	assert(v_at(v, 11));

	v_destroy(v);
	printf("OK -- test_v_at\n");
}

void test_determine_capacity() {
    size_t val0 = determine_capacity(-1);
    assert(val0 == 16);

    size_t val1 = determine_capacity(0);
    assert(val1 == 16);

    size_t val2 = determine_capacity(16);
    assert(val2 == 32);

    size_t val3 = determine_capacity(17);
    assert(val3 == 32);

    size_t val4 = determine_capacity(32);
    assert(val4 == 64);

    printf("OK -- test_determine_capacity\n");
}


/**********************  MAIN  *****************/

int main() {
    test_initialization();
    test_empty_initialization();
	test_v_is_empty_for_empty_initialization();
//	test_v_at();
	test_v_push();
	test_v_push_adjusts_capacity();
    
	test_determine_capacity();
    return 0;
}



