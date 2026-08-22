#include <iostream>

#include "tiny_array.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    if (!(std::cin >> n) || n < 0) {
        return 0;
    }
    TinyArray t(static_cast<std::size_t>(n));

    for (long long i = 0; i < n; i++) {
        long long tmp;
        if (!(std::cin >> tmp)) {
            return 0;
        }
        t.push_back(tmp);
    }

    for (long long i = 0; i < n; i++) {
        std::cout << t.get(i) << ' ';
    }

    std::cout << '\n';
    return 0;
}