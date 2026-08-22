#include "tiny_array.hpp"

#include <cassert>

void TinyArray::init(std::size_t initial_capacity) {
    data = new long long[initial_capacity];
    size = 0;
    capacity = initial_capacity;
}

void TinyArray::destroy() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

long long TinyArray::get(std::size_t index) const {
    assert(index < size);
    return data[index];
}

void TinyArray::push_back(long long value) {
    if (size == capacity) {
        std::size_t new_capacity;
        if (capacity == 0) {
            new_capacity = 1;
        } else {
            new_capacity = capacity * 2;
        }
        long long* new_data = new long long[new_capacity];
        for (std::size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    data[size] = value;
    size++;
}