
#include "Vector.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

void test_default_constructor() {
    Vector<int> v;
    assert(v.size() == 0);
    assert(v.empty());
}

void test_size_constructor() {
    Vector<int> v(3);
    assert(v.size() == 3);
    assert(v[0] == 0);
    assert(v[2] == 0);

    Vector<int> empty(0);
    assert(empty.empty());
}

void test_push_back() {
    Vector<int> v;
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);

    for (int i = 0; i < 20; ++i) {
        v.push_back(i);
    }

    assert(v.size() == 21);
    assert(v.back() == 19);
}

void test_pop_back() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 10);

    v.pop_back();
    assert(v.empty());

    bool thrown = false;
    try {
        v.pop_back();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_operator_bracket() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    assert(v[0] == 10);
    v[1] = 30;
    assert(v[1] == 30);

    const Vector<int>& cv = v;
    assert(cv[0] == 10);
}

void test_at() {
    Vector<int> v;
    v.push_back(7);

    assert(v.at(0) == 7);

    bool thrown = false;
    try {
        v.at(1);
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_front() {
    Vector<int> v;
    v.push_back(4);
    v.push_back(8);

    assert(v.front() == 4);

    v.pop_back();
    assert(v.front() == 4);

    v.clear();

    bool thrown = false;
    try {
        v.front();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_back() {
    Vector<int> v;
    v.push_back(4);
    v.push_back(8);

    assert(v.back() == 8);

    v.pop_back();
    assert(v.back() == 4);

    v.clear();

    bool thrown = false;
    try {
        v.back();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_insert() {
    Vector<int> v;
    v.insert(0, 10);
    v.insert(1, 30);
    v.insert(1, 20);

    assert(v.size() == 3);
    assert(v[0] == 10);
    assert(v[1] == 20);
    assert(v[2] == 30);

    bool thrown = false;
    try {
        v.insert(5, 40);
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_erase() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.erase(1);
    assert(v.size() == 2);
    assert(v[0] == 10);
    assert(v[1] == 30);

    v.erase(0);
    v.erase(0);
    assert(v.empty());

    bool thrown = false;
    try {
        v.erase(0);
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_swap() {
    Vector<int> a;
    Vector<int> b;

    a.push_back(1);
    a.push_back(2);
    b.push_back(9);

    a.swap(b);

    assert(a.size() == 1);
    assert(a[0] == 9);
    assert(b.size() == 2);
    assert(b[0] == 1);

    a.swap(a);
    assert(a[0] == 9);
}

void test_clear() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);

    v.clear();
    assert(v.empty());
    assert(v.size() == 0);

    v.clear();
    assert(v.empty());

    v.push_back(3);
    assert(v[0] == 3);
}

void test_resize() {
    Vector<int> v;
    v.resize(3);

    assert(v.size() == 3);
    assert(v[0] == 0);
    assert(v[2] == 0);

    v[0] = 10;
    v.resize(1);

    assert(v.size() == 1);
    assert(v[0] == 10);

    v.resize(0);
    assert(v.empty());
}

void test_copy_constructor() {
    Vector<int> a;
    a.push_back(10);
    a.push_back(20);

    Vector<int> b(a);
    assert(b.size() == 2);
    assert(b[0] == 10);

    b[0] = 99;
    assert(a[0] == 10);

    Vector<int> empty;
    Vector<int> copy(empty);
    assert(copy.empty());
}

void test_assignment_operator() {
    Vector<int> a;
    a.push_back(5);
    a.push_back(10);

    Vector<int> b;
    b = a;

    assert(b.size() == 2);
    assert(b[0] == 5);

    b[0] = 100;
    assert(a[0] == 5);

    b = b;
    assert(b.size() == 2);
    assert(b[0] == 100);

    Vector<int> empty;
    b = empty;
    assert(b.empty());
}

void test_reserve() {
    Vector<int> v;
    v.reserve(10);

    assert(v.capacity() >= 10);
    assert(v.size() == 0);

    v.push_back(5);
    v.reserve(2);

    assert(v[0] == 5);
    assert(v.capacity() >= 10);
}

void test_iterators() {
    Vector<int> v;
    v.push_back(3);
    v.push_back(7);

    assert(*v.begin() == 3);
    assert(*(v.end() - 1) == 7);

    Vector<int> empty;
    assert(empty.begin() == empty.end());
}

int main() {
    std::cout << "Running Vector tests\n";

    test_default_constructor();
    test_size_constructor();
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_at();
    test_front();
    test_back();
    test_insert();
    test_erase();
    test_swap();
    test_clear();
    test_resize();
    test_copy_constructor();
    test_assignment_operator();
    test_reserve();
    test_iterators();

    std::cout << "All tests passed\n";
    return 0;
}

