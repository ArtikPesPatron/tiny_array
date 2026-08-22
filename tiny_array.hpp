#pragma once

#include <cstddef>

class TinyArray {
public:
    explicit TinyArray(std::size_t initial_capacity = 0);
    ~TinyArray();

    TinyArray(const TinyArray&) = delete;
    TinyArray& operator=(const TinyArray&) = delete;

    void push_back(long long value);
    long long get(std::size_t index) const;

    std::size_t size() const;
    std::size_t capacity() const;

private:
    long long* data_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
};