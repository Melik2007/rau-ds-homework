
#include "CircularBuffer.h"
#include <cassert>
#include <iostream>

// Реализуйте методы CircularBuffer<T>:
//
//   1. CircularBuffer(int capacity)    - конструктор
//   2. ~CircularBuffer()               - деструктор
//   3. CircularBuffer(const &)         - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. push_back(const T&)             - добавить в конец
//   6. pop_front()                     - удалить с начала
//   7. operator[](int)                 - доступ по индексу
//   8. front()                         - первый элемент
//   9. back()                          - последний элемент
//  10. is_full()                       - буфер полон
//  11. is_empty()                      - буфер пуст
//  12. clear()                          - очистить
//  13. size()                          - количество элементов
//  14. capacity()                      - размер буфера
//
// Напишите для каждой функции один тест:
//   void test_<название_функции>() { ... }
//
// Каждый тест должен проверять:
//   - Нормальный случай
//   - Граничные случаи

void test_push_back() {
    CircularBuffer<int> buf(5);
    
    // Нормальный случай
    buf.push_back(10);
    assert(buf.size() == 1);
    assert(buf.front() == 10);
    assert(buf.back() == 10);
    
    buf.push_back(20);
    buf.push_back(30);
    assert(buf.size() == 3);
    assert(buf.back() == 30);
    
    // Граничный случай: переполнение
    buf.push_back(40);
    buf.push_back(50);
    buf.push_back(60);
    
    std::cout << "test_push_back passed" << std::endl;
}

// void test_pop_front() { ... }
// void test_operator_bracket() { ... }
// void test_front() { ... }
// void test_back() { ... }
// void test_capacity() { ... }
// void test_size() { ... }
// void test_is_full() { ... }
// void test_is_empty() { ... }
// void test_clear() { ... }
// void test_copy_constructor() { ... }
// void test_assignment_operator() { ... }

int main() {
    std::cout << "Running CircularBuffer tests" << std::endl;
    
    test_push_back();
    
    // Добавляйте свои тесты:
    // test_pop_front();
    // test_operator_bracket();
    
    std::cout << "All tests passed" << std::endl;
    return 0;
}
