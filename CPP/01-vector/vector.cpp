//
// Created by AnnA on 11.05.2018.
//

#include <iostream>
#include "vector.h"

// IMPORTANT: this works cause the call to other constructor is on the initialization list.
// It would go into an unfinitive initialization loop if the call to the parametrized constructor
// would be it the code.
Vector::Vector() : Vector(INITIAL_CAPACITY) {}

Vector::Vector(size_t initialCapacity) {
    capacity = getTheRoundUpToTheNextPoweroOfTwo(initialCapacity);
    size = 0;
    data = new int[capacity];
}

Vector::~Vector() {
    delete[] data;
}

size_t Vector::getSize() {
    return size;
}

size_t Vector::getCapacity() {
    return capacity;
}

bool Vector::isEmpty() {
    return getSize() == 0;
}

int Vector::at(size_t index) {
    assertIndexInBounds(index, false);
    return *(data + index);
}

void Vector::push(int value) {
    doubleCapacitizeVectorIfNeeded();

    size_t lastPosition = getSize();
    setAt(lastPosition, value);
    size++;
}

/**
 * When popping an item, if size is 1/4 of capacity, resize to half
 * @param vector
 * @return
 */
int Vector::pop() {
    int popped = at(getSize() - 1);
    size--;

    halfCapacitizeVectorIfNeeded();
    return popped;
}

void Vector::insert(size_t index, int value) {
    assertIndexInBounds(index, true);

    int initialSize = size;
    size++;
    doubleCapacitizeVectorIfNeeded();

    memmove(data + index + 1, data + index, (initialSize - index) * sizeof(int));
    setAt(index, value);
}

void Vector::prepend(int value) {
    insert(0 ,value);
}

void Vector::deleteItem(size_t index) {
    if (getSize() == 0 || index >= getSize()) {
        return;
    }

    memmove(data + index, data + index + 1, (getSize() - index - 1) * sizeof(int));
    size--;
    halfCapacitizeVectorIfNeeded();
}

int Vector::find(int item) {
    for (size_t i = 0; i < getSize(); i++) {
        if (at(i) == item) {
            return i;
        }
    }
    return -1;
}

void Vector::remove(int item) {
    if (getSize() == 0) {
        return;
    }

    size_t searchedItemIndex = 0;
    size_t insertionItemIndex = 0;

    for (; searchedItemIndex < getSize(); searchedItemIndex++, insertionItemIndex++) {
        while (searchedItemIndex < getSize() && at(searchedItemIndex) == item) {
            searchedItemIndex++;
        }

        if (searchedItemIndex == getSize()) {
            // We finished scanning. We will not include the item under searchedItemIndex.
            break;
        }
        setAt(insertionItemIndex, at(searchedItemIndex));
    }
    size = insertionItemIndex;
    halfCapacitizeVectorIfNeeded();
}


size_t Vector::getTheRoundUpToTheNextPoweroOfTwo(size_t value) {
    if (value <= INITIAL_CAPACITY) {
        return INITIAL_CAPACITY;
    }
    value--;
    value |= value >> 1;  // handle  2 bit numbers
    value |= value >> 2;  // handle  4 bit numbers
    value |= value >> 4;  // handle  8 bit numbers
    value |= value >> 8;  // handle 16 bit numbers
    if (sizeof(value) > 2) {
        value |= value >> 16; // handle 32 bit numbers
    }
    value++;
    return value;
}

void Vector::doubleCapacitizeVectorIfNeeded() {
    if (getCapacity() > getSize()) {
        return;
    }
    size_t doubledCapacity = capacity << 1;
    reCapacitizeVector(doubledCapacity);
}

void Vector::halfCapacitizeVectorIfNeeded() {
    if (getCapacity() == INITIAL_CAPACITY ||
        getSize() > getCapacity() * REDUCTION_FACTOR) {
        return;
    }
    size_t halfCapacity = capacity >> 1;
    reCapacitizeVector(halfCapacity);
    *(data + 2) = 2;
}

void Vector::reCapacitizeVector(size_t newCapacity) {
    int *reallocatedData = new int[newCapacity];
    std::memcpy(reallocatedData, data, sizeof(int) * newCapacity);

    delete[] data;
    data = reallocatedData;
    capacity = newCapacity;
}

void Vector::setAt(size_t index, int value) {
    *(data + index) = value;
}

void Vector::assertIndexInBounds(size_t index, bool allowEqualToSize) {
    if (index >= getSize() + (int) allowEqualToSize || index < 0) {
        std::cerr << "Position " << index << " out of bounds. The size of the vector is " << getSize() << ".\n\n";
//        throw new Exception();
    }
}

