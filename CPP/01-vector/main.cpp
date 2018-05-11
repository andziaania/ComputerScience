//
// Created by AnnA on 11.05.2018.
//
#include <iostream>
#include <assert.h>

#include "vector.h"

/**
 * Implement a vector - mutable array with automatic resizing
 *
 * */

//TODO exceptions

void test_initialization() {

    Vector v(2);

    assert(v.getSize() == 0);
    assert(v.getCapacity() == 16);

    Vector v0(0);
    assert(v0.getCapacity() == 16);

    Vector v1(17);
    assert(v1.getCapacity() == 32);

    Vector v2(32);
    assert(v2.getCapacity() == 32);

    Vector v3(2^9 - 3);
    assert(v.getCapacity() == 2^9);

    Vector v4(2^9);
    assert(v.getCapacity() == 2^9);

    printf("OK -- test_initialization\n");
}

void test_empty_initialization() {
    Vector v;

    assert(v.getSize() == 0);
    assert(v.getCapacity() == 16);

    printf("OK -- test_empty_initialization\n");
}

void test_v_is_empty_for_empty_initialization() {
    Vector v;
    Vector vWithInitialCapacity(145);

    assert(v.isEmpty());
    assert(vWithInitialCapacity.isEmpty());

    printf("OK -- test_v_is_empty_for_empty_initialization\n");
}

void test_v_push() {
    Vector v(2);

    v.push(5);
    assert(v.at(0) == 5);
    assert(v.getSize() == 1);

    v.push(4);
    assert(v.at(0) == 5);
    assert(v.at(1) == 4);
    assert(v.getSize() == 2);

    v.push(3);
    assert(v.at(2) == 3);

    printf("OK -- test_v_push\n");
}

void test_v_insert() {
    Vector v;

    v.insert(0, 10);
    assert(v.at(0) == 10);

    v.push(11);
    v.insert(0, 12);
    v.insert(2, 13);
    assert(v.at(0) == 12);
    assert(v.at(2) == 13);

    v.insert(2, 14);
    assert(v.at(2) == 14);
    assert(v.at(3) == 13);

    printf("OK -- test_v_insert\n");
}

void test_v_pop() {
    Vector v(2);

    // v.pop(); exit is called

    v.push(1);
    int popped = v.pop();
    assert(v.getSize() == 0);
    assert(popped == 1);

    v.push(2);
    v.push(3);

    int popped3 = v.pop();
    int popped2 = v.pop();


    assert(popped2 == 2);
    assert(popped3 == 3);


    printf("OK -- test_v_pop\n");
}

void test_v_prepend() {
    Vector v(2);

    v.prepend(88);
    assert(v.at(0) == 88);
    v.prepend(77);
    assert(v.at(0) == 77);
    assert(v.at(1) == 88);


    printf("OK -- test_v_prepend\n");
}

void test_v_delete() {
    Vector v(2);

    // 0 items
    v.deleteItem(0);
    assert(v.getSize() == 0);
    v.deleteItem(3);
    assert(v.getSize() == 0);

    // 1 item
    v.push(123);
    // delete item out of range
    v.deleteItem(3);
    assert(v.getSize() == 1);
    assert(v.at(0) == 123);
    // delete the item
    v.deleteItem(0);
    assert(v.getSize() == 0);
    // nothing to delete any more
    v.deleteItem(0);
    assert(v.getSize() == 0);

    // delete item out of range

    // k items
    v.push(0); v.push(1); v.push(2); v.push(3); v.push(4); v.push(5);
    v.deleteItem(3);
    assert(v.getSize() == 5);
    assert(v.at(0) == 0);
    assert(v.at(2) == 2);
    assert(v.at(3) == 4);
    assert(v.at(4) == 5);


    printf("OK -- test_v_delete\n");
}

void test_v_delete_with_capacity_change() {
    Vector v;

    // insert 18 values
    v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1);
    v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1);
    v.push(1); v.push(1);

    v.deleteItem(3);
    assert(v.getSize() == 17);
    assert(v.getCapacity() == 32);

    // squize to 1/4 capacity == 8
    v.deleteItem(0);
    v.deleteItem(0); v.deleteItem(0); v.deleteItem(0); v.deleteItem(0);
    v.deleteItem(0); v.deleteItem(0); v.deleteItem(0); v.deleteItem(0);
    assert(v.getSize() == 8);
    assert(v.getCapacity() == 16);


    printf("OK -- test_v_delete_with_capacity_change\n");
}

void test_v_pop_empty() {
    Vector v(2);

    //TODO


    printf("OK -- test_v_\n");
}

void test_v_push_adjusts_capacity() {
//    Vector v(2);
//
//    v.push(5);
//    assert(v.at(0) == 5);
//    assert(v.getSize() == 1);
//
//    v.push(4);
//    assert(v.at(0) == 5);
//    assert(v.at(1) == 4);
//    assert(v.getSize() == 2);
//
//    v.push(3);
//    assert(v.at(2) == 3);
//
//    printf("OK -- test_v_push\n");

    Vector v(2);

    // insert 18 values
    v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1);
    v.push(1); v.push(1); v.push(1); v.push(1);
    v.push(1); v.push(1); v.push(1); v.push(1);
//    v.push(1); v.push(1);

    assert(v.getCapacity() == 32);
    assert(v.getSize() == 18);
    assert(v.at(16) == 1);
    assert(v.at(17) == 1);
    assert(v.at(5) == 1);
    assert(v.at(15) == 1);
    assert(v.at(1) == 1);


    printf("OK -- test test_v_push_adjusts_capacity\n");
}

void test_v_pop_adjusts_capacity() {
    Vector v;

    // 18 x push
    v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1);
    v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1); v.push(1);
    v.push(1); v.push(1);

    v.pop();
    assert(v.getCapacity() == 32);
    assert(v.getSize() == 17);
    v.pop();
    v.pop();
    assert(v.getCapacity() == 32);
    assert(v.getSize() == 15);

    // 7 x pop
    v.pop(); v.pop(); v.pop(); v.pop();
    v.pop(); v.pop(); v.pop();
    //(18 items - 3 - 7)
    assert(v.getCapacity() == 16);
    assert(v.getSize() == 8);


    printf("OK -- test test_v_pop_adjusts_capacity\n");
}


void test_v_at() {
    Vector v(5);
    for (int i = 0; i < 16; i++) {
        v.push(i);
    }


    printf("OK -- test_v_at\n");
}

void test_v_find() {
    Vector v(2);

    // find in empty vector
    assert(v.find(32) == -1);

    v.push(11);
    assert(v.find(32) == -1);
    assert(v.find(11) == 0);

    v.push(22);
    v.push(33);
    v.push(44);
    assert(v.find(22) == 1);
    assert(v.find(33) == 2);
    assert(v.find(44) == 3);

    v.push(44);
    v.push(33);
    v.push(33);
    v.push(44);
    v.push(33);
    assert(v.find(33) == 2);
    assert(v.find(44) == 3);


    printf("OK -- test_v_find\n");
}


void test_v_remove_emptyVectorOrOneSized() {
    Vector v(2);

    // Remove from an empty vector - do nothing
    v.remove(56);
    assert(v.getSize() == 0);

    v.push(55);
    v.remove(56);
    assert(v.getSize() == 1);
    assert(v.at(0) == 55);
    v.remove(55);
    assert(v.getSize() == 0);


    printf("OK -- test_v_remove_emptyVectorOrOneSized\n");
}

void test_v_remove() {
    Vector v(2);

    // Insert 18 elements. The capacity is increased to 32.
    v.push(15); v.push(15); v.push(15); v.push(15); v.push(15); v.push(15); v.push(15); v.push(15);
    v.push(15); v.push(15); v.push(15); v.push(15); v.push(15); v.push(15); v.push(15); v.push(15);
    v.push(15); v.push(15);
    v.remove(15);
    assert(v.getSize() == 0);
    assert(v.getCapacity() == 16);

    v.push(11);
    v.push(22);
    v.push(33);
    v.remove(22);
    assert(v.find(22) == -1);
    assert(v.find(11) == 0);
    assert(v.find(33) == 1);
    assert(v.getSize() == 2);

    v.push(44);
    v.push(33);
    v.push(33);
    v.push(44);
    v.push(33);
    v.remove(33);
    assert(v.find(33) == -1);
    assert(v.getSize() == 3);
    assert(v.find(44) == 1);

    v.remove(11);
    assert(v.find(11) == -1);
    assert(v.at(0) == 44);

    v.remove(44);
    assert(v.getSize() == 0);


    printf("OK -- test_v_remove\n");
}

void test_v_() {
    Vector v(2);




    printf("OK -- test_v_\n");
}
/**********************  MAIN  *****************/

int main() {
    std::cout << "Hello, World!" << std::endl;

    test_initialization();
    test_empty_initialization();
    test_v_is_empty_for_empty_initialization();
    test_v_at();
    test_v_push();

    test_v_push_adjusts_capacity();
    std::cout << "Hello, World!" << std::endl;
//    test_v_pop();
//    test_v_pop_adjusts_capacity();
//    test_v_insert();
//    test_v_prepend();
//    test_v_delete();
//    test_v_delete_with_capacity_change();
//    test_v_find();
//    test_v_remove_emptyVectorOrOneSized();
//    test_v_remove();

    return 0;
}