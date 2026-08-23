#include <iostream>

#include "tiny_array.hpp"

TinyArray make_array(std::size_t initial_capacity) {
    TinyArray t(initial_capacity);
    t.push_back(1);
    t.push_back(2);
    return t;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    if (!(std::cin >> n) || n < 0) {
        return 0;
    }
    TinyArray t = make_array(static_cast<std::size_t>(n));

    for (long long i = 0; i < n; i++) {
        long long tmp;
        if (!(std::cin >> tmp)) {
            return 0;
        }
        t.push_back(tmp);
    }

    for (std::size_t i = 0; i < t.size(); i++) {
        std::cout << t.get(i) << ' ';
    }

    std::cout << '\n';
    return 0;
}