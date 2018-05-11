//
// Created by AnnA on 11.05.2018.
//

#include "vector.h"

Vector::Vector() {}

Vector::Vector(std::size_t initialCapacity) {}

Vector::~Vector() {}

std::size_t Vector::getSize() {}

std::size_t Vector::getCapacity() {}

bool Vector::isEmpty() {}

int Vector::at(std::size_t index) {}

void Vector::push(int value) {}
/**
 * When popping an item, if size is 1/4 of capacity, resize to half
 * @param vector
 * @return
 */
int Vector::pop() {}

void Vector::insert(std::size_t index, int value) {}

void Vector::prepend(int value) {}

void Vector::deleteItem(std::size_t index) {}

int Vector::find(int item) {}

void Vector::remove(int item) {}


std::size_t Vector::getTheRoundUpToTheNextPoweroOfTwo(std::size_t value) {}

void Vector::doubleCapacitizeVectorIfNeeded() {}

void Vector::halfCapacitizeVectorIfNeeded() {}

void Vector::reCapacitizeVector(std::size_t new_capacity) {}

void Vector::setAt(Vector *vector, std::size_t index, int value) {}

void Vector::checkAllocationSuccess(void *ptr) {}

void Vector::assertIndexInBounds(Vector *vector, std::size_t index, bool allowEqualToSize) {}

