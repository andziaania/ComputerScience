//
// Created by AnnA on 11.05.2018.
//

#pragma once

#include <cstdint>


class Vector {
private:
    const int INITIAL_CAPACITY = 16;
    const float REDUCTION_FACTOR = 0.25;

public:
    Vector();
    Vector(std::size_t initialCapacity);
    ~Vector();

    std::size_t getSize();

    std::size_t getCapacity();

    bool isEmpty();

    int at(std::size_t index);

    void push(int value);
/**
 * When popping an item, if size is 1/4 of capacity, resize to half
 * @param vector
 * @return
 */
    int pop();

    void insert(std::size_t index, int value);

    void prepend(int value);

    void deleteItem(std::size_t index);

    int find(int item);

    void remove(int item);

protected:
    std::size_t getTheRoundUpToTheNextPoweroOfTwo(std::size_t value);

    void doubleCapacitizeVectorIfNeeded();

    void halfCapacitizeVectorIfNeeded();

    void reCapacitizeVector(std::size_t new_capacity);

    void setAt(Vector *vector, std::size_t index, int value);

    void checkAllocationSuccess(void *ptr);

    void assertIndexInBounds(Vector *vector, std::size_t index, bool allowEqualToSize);
};
