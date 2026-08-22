#include <cassert>

#include "tiny_array.hpp"

int main() {
    {
        TinyArray t;
        t.init(2);
        assert(t.size == 0);
        assert(t.capacity == 2);

        t.push_back(10);
        t.push_back(20);
        t.push_back(30);
        assert(t.size == 3);
        assert(t.capacity >= 3);
        assert(t.get(0) == 10);
        assert(t.get(1) == 20);
        assert(t.get(2) == 30);

        t.destroy();
        assert(t.size == 0);
        assert(t.capacity == 0);
        assert(t.data == nullptr);
    }

    {
        TinyArray t;
        t.init(1000);
        assert(t.size == 0);
        assert(t.capacity == 1000);

        for (int i = 0; i < 1000; ++i) {
            t.push_back(i);
        }
        for (int i = 0; i < 1000; ++i) {
            assert(t.get(i) == i);
        }
        t.destroy();
    }

    {
        TinyArray t;
        t.init(3);

        t.push_back(10);
        t.push_back(20);
        t.push_back(30);

        t.destroy();
        assert(t.size == 0);
        assert(t.capacity == 0);
        assert(t.data == nullptr);

        t.init(3);
        assert(t.size == 0);
        assert(t.capacity == 3);

        t.push_back(10);
        t.push_back(20);
        t.push_back(30);
        assert(t.size == 3);
        assert(t.capacity >= 3);
        assert(t.get(0) == 10);
        assert(t.get(1) == 20);
        assert(t.get(2) == 30);

        t.destroy();
    }
}