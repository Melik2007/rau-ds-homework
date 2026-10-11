
#include "CircularBuffer.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

void test_constructor() {
    CircularBuffer<int> buf(5);
    assert(buf.capacity() == 5);
    assert(buf.size() == 0);
    assert(buf.is_empty());

    bool thrown = false;
    try {
        CircularBuffer<int> invalid(0);
    } catch (const std::invalid_argument&) {
        thrown = true;
    }
    assert(thrown);
}

void test_push_back() {
    CircularBuffer<int> buf(3);

    buf.push_back(10);
    buf.push_back(20);
    buf.push_back(30);

    assert(buf.size() == 3);
    assert(buf.front() == 10);
    assert(buf.back() == 30);
    assert(buf.is_full());

    bool thrown = false;
    try {
        buf.push_back(40);
    } catch (const std::overflow_error&) {
        thrown = true;
    }
    assert(thrown);
    assert(buf.size() == 3);
}

void test_pop_front() {
    CircularBuffer<int> buf(3);

    bool thrown = false;
    try {
        buf.pop_front();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);

    buf.push_back(10);
    buf.push_back(20);
    buf.pop_front();

    assert(buf.front() == 20);
    assert(buf.size() == 1);

    buf.pop_front();
    assert(buf.is_empty());
}

void test_operator_bracket() {
    CircularBuffer<int> buf(3);

    buf.push_back(10);
    buf.push_back(20);
    buf.push_back(30);

    assert(buf[0] == 10);
    assert(buf[1] == 20);
    assert(buf[2] == 30);

    buf[1] = 99;
    assert(buf[1] == 99);

    const CircularBuffer<int>& cbuf = buf;
    assert(cbuf[1] == 99);

    bool thrown = false;
    try {
        buf[-1];
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);

    thrown = false;
    try {
        buf[3];
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_front() {
    CircularBuffer<int> buf(2);

    buf.push_back(5);
    assert(buf.front() == 5);

    buf.front() = 15;
    assert(buf.front() == 15);

    const CircularBuffer<int>& cbuf = buf;
    assert(cbuf.front() == 15);

    buf.pop_front();

    bool thrown = false;
    try {
        buf.front();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_back() {
    CircularBuffer<int> buf(2);

    buf.push_back(5);
    buf.push_back(10);

    assert(buf.back() == 10);
    buf.back() = 20;
    assert(buf.back() == 20);

    const CircularBuffer<int>& cbuf = buf;
    assert(cbuf.back() == 20);

    buf.clear();

    bool thrown = false;
    try {
        buf.back();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_is_full() {
    CircularBuffer<int> buf(2);

    assert(!buf.is_full());

    buf.push_back(1);
    assert(!buf.is_full());

    buf.push_back(2);
    assert(buf.is_full());

    buf.pop_front();
    assert(!buf.is_full());
}

void test_is_empty() {
    CircularBuffer<int> buf(2);

    assert(buf.is_empty());

    buf.push_back(1);
    assert(!buf.is_empty());

    buf.pop_front();
    assert(buf.is_empty());
}

void test_clear() {
    CircularBuffer<int> buf(3);

    buf.push_back(1);
    buf.push_back(2);
    buf.clear();

    assert(buf.is_empty());
    assert(buf.size() == 0);
    assert(buf.capacity() == 3);

    buf.clear();
    buf.push_back(10);
    assert(buf.front() == 10);
}

void test_capacity() {
    CircularBuffer<int> buf(4);

    assert(buf.capacity() == 4);

    buf.push_back(1);
    buf.clear();

    assert(buf.capacity() == 4);
}

void test_size() {
    CircularBuffer<int> buf(3);

    assert(buf.size() == 0);

    buf.push_back(1);
    buf.push_back(2);
    assert(buf.size() == 2);

    buf.pop_front();
    assert(buf.size() == 1);

    buf.clear();
    assert(buf.size() == 0);
}

void test_wrap_around() {
    CircularBuffer<int> buf(3);

    buf.push_back(10);
    buf.push_back(20);
    buf.push_back(30);

    buf.pop_front();
    buf.pop_front();

    buf.push_back(40);
    buf.push_back(50);

    assert(buf.is_full());
    assert(buf[0] == 30);
    assert(buf[1] == 40);
    assert(buf[2] == 50);
    assert(buf.front() == 30);
    assert(buf.back() == 50);
}

void test_copy_constructor() {
    CircularBuffer<int> original(3);

    original.push_back(10);
    original.push_back(20);
    original.pop_front();
    original.push_back(30);

    CircularBuffer<int> copy(original);

    assert(copy.capacity() == 3);
    assert(copy.size() == 2);
    assert(copy[0] == 20);
    assert(copy[1] == 30);

    copy[0] = 99;
    assert(original[0] == 20);

    CircularBuffer<int> empty(2);
    CircularBuffer<int> empty_copy(empty);
    assert(empty_copy.is_empty());
}

void test_assignment_operator() {
    CircularBuffer<int> a(3);
    a.push_back(10);
    a.push_back(20);

    CircularBuffer<int> b(2);
    b.push_back(99);

    b = a;

    assert(b.capacity() == 3);
    assert(b.size() == 2);
    assert(b[0] == 10);
    assert(b[1] == 20);

    b[0] = 50;
    assert(a[0] == 10);

    b = b;
    assert(b[0] == 50);

    CircularBuffer<int> empty(4);
    b = empty;

    assert(b.is_empty());
    assert(b.capacity() == 4);
}

int main() {
    std::cout << "Running CircularBuffer tests\n";

    test_constructor();
    test_push_back();
    test_pop_front();
    test_operator_bracket();
    test_front();
    test_back();
    test_is_full();
    test_is_empty();
    test_clear();
    test_capacity();
    test_size();
    test_wrap_around();
    test_copy_constructor();
    test_assignment_operator();

    std::cout << "All tests passed\n";
    return 0;
}

