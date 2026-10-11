
#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <stdexcept>
#include <utility>

template <typename T>
class Vector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;

    void _resize_capacity(size_t new_capacity) {
        T* new_data = new_capacity ? new T[new_capacity] : nullptr;

        try {
            for (size_t i = 0; i < _size; ++i) {
                new_data[i] = _data[i];
            }
        } catch (...) {
            delete[] new_data;
            throw;
        }

        delete[] _data;
        _data = new_data;
        _capacity = new_capacity;
    }

public:
    Vector() : _data(nullptr), _size(0), _capacity(0) {}

    explicit Vector(size_t initial_size)
        : _data(initial_size ? new T[initial_size]{} : nullptr),
          _size(initial_size),
          _capacity(initial_size) {}

    ~Vector() {
        delete[] _data;
    }

    Vector(const Vector& other)
        : _data(other._capacity ? new T[other._capacity] : nullptr),
          _size(0),
          _capacity(other._capacity) {
        try {
            for (size_t i = 0; i < other._size; ++i) {
                _data[i] = other._data[i];
            }
            _size = other._size;
        } catch (...) {
            delete[] _data;
            throw;
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            Vector temp(other);
            swap(temp);
        }
        return *this;
    }

    void push_back(const T& value) {
        T temp = value;

        if (_size == _capacity) {
            reserve(_capacity == 0 ? 1 : _capacity * 2);
        }

        _data[_size] = temp;
        ++_size;
    }

    void pop_back() {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        --_size;
    }

    T& operator[](size_t index) {
        return _data[index];
    }

    const T& operator[](size_t index) const {
        return _data[index];
    }

    T& at(size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    const T& at(size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    T& front() {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return _data[0];
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return _data[0];
    }

    T& back() {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return _data[_size - 1];
    }

    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Vector is empty");
        }
        return _data[_size - 1];
    }

    size_t size() const {
        return _size;
    }

    size_t capacity() const {
        return _capacity;
    }

    bool empty() const {
        return _size == 0;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > _capacity) {
            _resize_capacity(new_capacity);
        }
    }

    void clear() {
        _size = 0;
    }

    void resize(size_t new_size) {
        if (new_size > _capacity) {
            reserve(new_size);
        }

        for (size_t i = _size; i < new_size; ++i) {
            _data[i] = T{};
        }

        _size = new_size;
    }

    void insert(size_t pos, const T& value) {
        if (pos > _size) {
            throw std::out_of_range("Index out of range");
        }

        T temp = value;

        if (_size == _capacity) {
            reserve(_capacity == 0 ? 1 : _capacity * 2);
        }

        for (size_t i = _size; i > pos; --i) {
            _data[i] = _data[i - 1];
        }

        _data[pos] = temp;
        ++_size;
    }

    void erase(size_t pos) {
        if (pos >= _size) {
            throw std::out_of_range("Index out of range");
        }

        for (size_t i = pos; i + 1 < _size; ++i) {
            _data[i] = _data[i + 1];
        }

        --_size;
    }

    void swap(Vector& other) noexcept {
        std::swap(_data, other._data);
        std::swap(_size, other._size);
        std::swap(_capacity, other._capacity);
    }

    T* begin() {
        return _data;
    }

    const T* begin() const {
        return _data;
    }

    T* end() {
        return _data ? _data + _size : nullptr;
    }

    const T* end() const {
        return _data ? _data + _size : nullptr;
    }
};

#endif
