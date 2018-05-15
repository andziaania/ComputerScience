//
// Created by AnnA on 11.05.2018.
//

#pragma once

#include <exception>
#include <string>

class Vector {
public:
    const size_t INITIAL_CAPACITY = 16;
    const float REDUCTION_FACTOR = 0.25;

    class IndexOutOfBoundException : std::exception {
    public:
        explicit IndexOutOfBoundException(const std::string &msg) {}

        const char *what() const noexcept override;
    };

protected:
    size_t size;
    size_t capacity;
    int *data;

public:
    Vector();
    explicit Vector(std::size_t initialCapacity);
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
    std::size_t getTheRoundUpToTheNextPowerOfTwo(std::size_t value);

    void doubleCapacitizeVectorIfNeeded();

    void halfCapacitizeVectorIfNeeded();

    void reCapacitizeVector(std::size_t new_capacity);

    void setAt(std::size_t index, int value);

    void assertIndexInBounds(std::size_t index, bool allowEqualToSize);
};
