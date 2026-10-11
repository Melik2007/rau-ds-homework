
#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <stdexcept>
#include <utility>

template <typename T>
class CircularBuffer {
private:
    T* _data;
    int _capacity;
    int _head;
    int _tail;
    int _size;

public:
    explicit CircularBuffer(int capacity)
        : _data(nullptr),
          _capacity(capacity),
          _head(0),
          _tail(0),
          _size(0) {
        if (capacity <= 0) {
            throw std::invalid_argument(
                "Capacity must be positive"
            );
        }

        _data = new T[capacity]{};
    }

    ~CircularBuffer() {
        delete[] _data;
    }

    CircularBuffer(const CircularBuffer& other)
        : _data(new T[other._capacity]),
          _capacity(other._capacity),
          _head(0),
          _tail(other._size % other._capacity),
          _size(other._size) {
        try {
            for (int i = 0; i < _size; ++i) {
                _data[i] = other[i];
            }
        } catch (...) {
            delete[] _data;
            throw;
        }
    }

    CircularBuffer& operator=(const CircularBuffer& other) {
        if (this != &other) {
            CircularBuffer temp(other);

            std::swap(_data, temp._data);
            std::swap(_capacity, temp._capacity);
            std::swap(_head, temp._head);
            std::swap(_tail, temp._tail);
            std::swap(_size, temp._size);
        }

        return *this;
    }

    void push_back(const T& x) {
        if (is_full()) {
            throw std::overflow_error("Buffer is full");
        }

        _data[_tail] = x;
        _tail = (_tail + 1) % _capacity;
        ++_size;
    }

    void pop_front() {
        if (is_empty()) {
            throw std::out_of_range("Buffer is empty");
        }

        _head = (_head + 1) % _capacity;
        --_size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }

        return _data[(_head + index) % _capacity];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= _size) {
            throw std::out_of_range("Index out of range");
        }

        return _data[(_head + index) % _capacity];
    }

    T& front() {
        if (is_empty()) {
            throw std::out_of_range("Buffer is empty");
        }

        return _data[_head];
    }

    const T& front() const {
        if (is_empty()) {
            throw std::out_of_range("Buffer is empty");
        }

        return _data[_head];
    }

    T& back() {
        if (is_empty()) {
            throw std::out_of_range("Buffer is empty");
        }

        return _data[(_tail + _capacity - 1) % _capacity];
    }

    const T& back() const {
        if (is_empty()) {
            throw std::out_of_range("Buffer is empty");
        }

        return _data[(_tail + _capacity - 1) % _capacity];
    }

    bool is_full() const {
        return _size == _capacity;
    }

    bool is_empty() const {
        return _size == 0;
    }

    void clear() {
        _head = 0;
        _tail = 0;
        _size = 0;
    }

    int capacity() const {
        return _capacity;
    }

    int size() const {
        return _size;
    }
};

#endif
