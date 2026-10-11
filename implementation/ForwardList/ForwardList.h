
#ifndef FORWARDLIST_H
#define FORWARDLIST_H

#include <stdexcept>
#include <utility>

template <typename T>
class ForwardList {
public:
    struct Node {
        T data;
        Node* next;

        Node(const T& d) : data(d), next(nullptr) {}
    };

private:
    Node* _head;
    int _size;

public:
    ForwardList() : _head(nullptr), _size(0) {}

    ~ForwardList() {
        clear();
    }

    ForwardList(const ForwardList& other)
        : _head(nullptr), _size(0) {
        Node* tail = nullptr;

        try {
            for (Node* current = other._head;
                 current != nullptr;
                 current = current->next) {

                Node* node = new Node(current->data);

                if (_head == nullptr) {
                    _head = node;
                } else {
                    tail->next = node;
                }

                tail = node;
                ++_size;
            }
        } catch (...) {
            clear();
            throw;
        }
    }

    ForwardList& operator=(const ForwardList& other) {
        if (this != &other) {
            ForwardList temp(other);
            swap(temp);
        }

        return *this;
    }

    void swap(ForwardList& other) noexcept {
        std::swap(_head, other._head);
        std::swap(_size, other._size);
    }

    void push_front(const T& x) {
        Node* node = new Node(x);
        node->next = _head;
        _head = node;
        ++_size;
    }

    void pop_front() {
        if (_head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node* old = _head;
        _head = _head->next;
        delete old;
        --_size;
    }

    T& front() {
        if (_head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        return _head->data;
    }

    const T& front() const {
        if (_head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        return _head->data;
    }

    void insert_after(Node* node, const T& value) {
        if (node == nullptr) {
            throw std::invalid_argument("Null node");
        }

        Node* current = _head;

        while (current != nullptr && current != node) {
            current = current->next;
        }

        if (current == nullptr) {
            throw std::invalid_argument("Node not in list");
        }

        Node* new_node = new Node(value);
        new_node->next = node->next;
        node->next = new_node;
        ++_size;
    }

    void erase_after(Node* node) {
        if (node == nullptr) {
            throw std::invalid_argument("Null node");
        }

        Node* current = _head;

        while (current != nullptr && current != node) {
            current = current->next;
        }

        if (current == nullptr) {
            throw std::invalid_argument("Node not in list");
        }

        if (node->next == nullptr) {
            throw std::out_of_range("No node after this one");
        }

        Node* old = node->next;
        node->next = old->next;
        delete old;
        --_size;
    }

    void clear() {
        while (_head != nullptr) {
            Node* old = _head;
            _head = _head->next;
            delete old;
        }

        _size = 0;
    }

    void reverse() {
        Node* previous = nullptr;
        Node* current = _head;

        while (current != nullptr) {
            Node* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        _head = previous;
    }

    int size() const {
        return _size;
    }

    bool empty() const {
        return _head == nullptr;
    }

    Node* begin() {
        return _head;
    }

    Node* begin() const {
        return _head;
    }
};

#endif
