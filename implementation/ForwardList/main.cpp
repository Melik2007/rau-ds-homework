
#include "ForwardList.h"
#include <cassert>
#include <iostream>
#include <stdexcept>

void test_constructor() {
    ForwardList<int> list;
    assert(list.size() == 0);
    assert(list.empty());
    assert(list.begin() == nullptr);
}

void test_push_front() {
    ForwardList<int> list;

    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);

    assert(list.size() == 3);
    assert(list.front() == 3);
    assert(list.begin()->next->data == 2);
}

void test_pop_front() {
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);

    list.pop_front();
    assert(list.front() == 10);
    assert(list.size() == 1);

    list.pop_front();
    assert(list.empty());

    bool thrown = false;
    try {
        list.pop_front();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_front() {
    ForwardList<int> list;
    list.push_front(5);

    list.front() = 15;
    assert(list.front() == 15);

    const ForwardList<int>& const_list = list;
    assert(const_list.front() == 15);

    list.clear();

    bool thrown = false;
    try {
        list.front();
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_insert_after() {
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(5);

    list.insert_after(list.begin(), 7);

    assert(list.size() == 3);
    assert(list.begin()->next->data == 7);
    assert(list.begin()->next->next->data == 10);

    list.insert_after(list.begin()->next->next, 20);
    assert(list.size() == 4);

    bool thrown = false;
    try {
        list.insert_after(nullptr, 30);
    } catch (const std::invalid_argument&) {
        thrown = true;
    }
    assert(thrown);
}

void test_erase_after() {
    ForwardList<int> list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);

    list.erase_after(list.begin());

    assert(list.size() == 2);
    assert(list.begin()->next->data == 30);

    bool thrown = false;
    try {
        list.erase_after(list.begin()->next);
    } catch (const std::out_of_range&) {
        thrown = true;
    }
    assert(thrown);
}

void test_clear() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);

    list.clear();
    assert(list.empty());
    assert(list.size() == 0);

    list.clear();
    assert(list.empty());

    list.push_front(3);
    assert(list.front() == 3);
}

void test_reverse() {
    ForwardList<int> list;

    list.reverse();
    assert(list.empty());

    list.push_front(1);
    list.reverse();
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);

    list.reverse();

    assert(list.front() == 1);
    assert(list.begin()->next->data == 2);
    assert(list.begin()->next->next->data == 3);
}

void test_size_and_empty() {
    ForwardList<int> list;

    assert(list.size() == 0);
    assert(list.empty());

    list.push_front(5);
    assert(list.size() == 1);
    assert(!list.empty());

    list.pop_front();
    assert(list.size() == 0);
    assert(list.empty());
}

void test_begin() {
    ForwardList<int> list;
    assert(list.begin() == nullptr);

    list.push_front(10);
    list.push_front(20);

    assert(list.begin()->data == 20);
    assert(list.begin()->next->data == 10);

    const ForwardList<int>& const_list = list;
    assert(const_list.begin()->data == 20);
}

void test_copy_constructor() {
    ForwardList<int> original;
    original.push_front(10);
    original.push_front(20);

    ForwardList<int> copy(original);

    assert(copy.size() == 2);
    assert(copy.front() == 20);

    copy.front() = 99;
    assert(original.front() == 20);

    ForwardList<int> empty;
    ForwardList<int> empty_copy(empty);
    assert(empty_copy.empty());
}

void test_assignment_operator() {
    ForwardList<int> a;
    a.push_front(10);
    a.push_front(20);

    ForwardList<int> b;
    b.push_front(99);

    b = a;

    assert(b.size() == 2);
    assert(b.front() == 20);

    b.front() = 50;
    assert(a.front() == 20);

    b = b;
    assert(b.front() == 50);

    ForwardList<int> empty;
    b = empty;
    assert(b.empty());
}

int main() {
    std::cout << "Running ForwardList tests\n";

    test_constructor();
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_size_and_empty();
    test_begin();
    test_copy_constructor();
    test_assignment_operator();

    std::cout << "All tests passed\n";
    return 0;
}
