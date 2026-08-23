#include "tiny_array.hpp"

#include <cassert>

TinyArray::TinyArray(const std::size_t initial_capacity) {
    data_ = new long long[initial_capacity];
    size_ = 0;
    capacity_ = initial_capacity;
}

TinyArray::TinyArray(TinyArray&& other) noexcept {
    data_ = other.data_;
    size_ = other.size_;
    capacity_ = other.capacity_;

    other.capacity_ = 0;
    other.size_ = 0;
    other.data_ = nullptr;
}

TinyArray& TinyArray::operator=(TinyArray&& other) noexcept {
    if (this != &other) {
        delete[] data_;

        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

TinyArray::~TinyArray() {
    delete[] data_;
}

long long TinyArray::get(const std::size_t index) const {
    assert(index < size_);
    return data_[index];
}

void TinyArray::push_back(const long long value) {
    if (size_ == capacity_) {
        std::size_t new_capacity;
        if (capacity_ == 0) {
            new_capacity = 1;
        } else {
            new_capacity = capacity_ * 2;
        }
        long long* new_data = new long long[new_capacity];
        for (std::size_t i = 0; i < size_; i++) {
            new_data[i] = data_[i];
        }
        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }
    data_[size_] = value;
    size_++;
}

std::size_t TinyArray::size() const {
    return size_;
}

std::size_t TinyArray::capacity() const {
    return capacity_;
}