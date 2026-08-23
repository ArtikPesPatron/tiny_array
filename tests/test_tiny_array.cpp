#include <cassert>
#include <utility>
#include <vector>

#include "tiny_array.hpp"

int main() {
    {
        TinyArray t(2);
        assert(t.size() == 0);
        assert(t.capacity() == 2);

        t.push_back(10);
        t.push_back(20);
        t.push_back(30);
        assert(t.size() == 3);
        assert(t.capacity() >= 3);
        assert(t.get(0) == 10);
        assert(t.get(1) == 20);
        assert(t.get(2) == 30);
    }

    {
        TinyArray t(1000);
        assert(t.size() == 0);
        assert(t.capacity() == 1000);

        for (int i = 0; i < 1000; ++i) {
            t.push_back(i);
        }
        for (int i = 0; i < 1000; ++i) {
            assert(t.get(i) == i);
        }
    }

    {
        {
            TinyArray t(1000);

            t.push_back(10);
            t.push_back(20);
            t.push_back(30);
            assert(t.size() == 3);
            assert(t.capacity() >= 3);
            assert(t.get(0) == 10);
            assert(t.get(1) == 20);
            assert(t.get(2) == 30);
        }
    }
    {
        TinyArray a(2);
        a.push_back(1);
        a.push_back(2);

        TinyArray b = std::move(a);
        assert(b.size() == 2);
        assert(b.get(0) == 1);
        assert(b.get(1) == 2);
        assert(a.size() == 0);
        assert(a.capacity() == 0);

        a.push_back(3);
        assert(a.size() == 1);
        assert(a.get(0) == 3);
    }
    {
        TinyArray a(2);
        a.push_back(7);

        TinyArray b(4);
        b.push_back(100);
        b = std::move(a);
        assert(b.size() == 1);
        assert(b.get(0) == 7);
        assert(a.size() == 0);
    }
    {
        std::vector<TinyArray> v;
        for (int i = 0; i < 10; i++) {
            TinyArray t;
            t.push_back(i);
            v.push_back(std::move(t));
        }
        assert(v.size() == 10);
        assert(v[3].get(0) == 3);
        assert(v[9].get(0) == 9);
    }
}