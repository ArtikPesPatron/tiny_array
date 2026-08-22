#pragma once

#include <cstddef>

struct TinyArray {
    long long* data = nullptr;
    std::size_t size = 0;
    std::size_t capacity = 0;

    void init(std::size_t initial_capacity);
    void push_back(long long value);
    long long get(std::size_t index) const;
    void destroy();
};