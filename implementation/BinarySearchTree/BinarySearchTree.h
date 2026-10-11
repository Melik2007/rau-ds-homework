
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <utility>

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& d)
            : data(d), left(nullptr), right(nullptr) {}
    };

    Node* _root;
    int _size;

    Node* insert_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            Node* new_node = new Node(value);
            ++_size;
            return new_node;
        }

        if (value < node->data) {
            node->left = insert_recursive(node->left, value);
        } else if (node->data < value) {
            node->right = insert_recursive(node->right, value);
        }

        return node;
    }

    Node* remove_recursive(Node* node, const T& value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            node->left = remove_recursive(node->left, value);
        } else if (node->data < value) {
            node->right = remove_recursive(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* right = node->right;
                delete node;
                --_size;
                return right;
            }

            if (node->right == nullptr) {
                Node* left = node->left;
                delete node;
                --_size;
                return left;
            }

            Node* successor = node->right;

            while (successor->left != nullptr) {
                successor = successor->left;
            }

            node->data = successor->data;
            node->right = remove_recursive(
                node->right, successor->data
            );
        }

        return node;
    }

    Node* find_recursive(Node* node, const T& value) const {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->data) {
            return find_recursive(node->left, value);
        }

        if (node->data < value) {
            return find_recursive(node->right, value);
        }

        return node;
    }

    void clear_recursive(Node* node) {
        if (node == nullptr) {
            return;
        }

        clear_recursive(node->left);
        clear_recursive(node->right);
        delete node;
    }

    int height_recursive(Node* node) const {
        if (node == nullptr) {
            return 0;
        }

        int left_height = height_recursive(node->left);
        int right_height = height_recursive(node->right);

        return 1 + (left_height > right_height
                    ? left_height : right_height);
    }

    Node* copy_recursive(const Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* copy = new Node(node->data);

        try {
            copy->left = copy_recursive(node->left);
            copy->right = copy_recursive(node->right);
        } catch (...) {
            clear_recursive(copy);
            throw;
        }

        return copy;
    }

    void inorder_recursive(const Node* node) const {
        if (node == nullptr) {
            return;
        }

        inorder_recursive(node->left);
        std::cout << node->data << " ";
        inorder_recursive(node->right);
    }

    void preorder_recursive(const Node* node) const {
        if (node == nullptr) {
            return;
        }

        std::cout << node->data << " ";
        preorder_recursive(node->left);
        preorder_recursive(node->right);
    }

    void postorder_recursive(const Node* node) const {
        if (node == nullptr) {
            return;
        }

        postorder_recursive(node->left);
        postorder_recursive(node->right);
        std::cout << node->data << " ";
    }

public:
    BinarySearchTree()
        : _root(nullptr), _size(0) {}

    ~BinarySearchTree() {
        clear();
    }

    BinarySearchTree(const BinarySearchTree& other)
        : _root(nullptr), _size(0) {
        _root = copy_recursive(other._root);
        _size = other._size;
    }

    BinarySearchTree& operator=(
        const BinarySearchTree& other
    ) {
        if (this != &other) {
            BinarySearchTree temp(other);
            std::swap(_root, temp._root);
            std::swap(_size, temp._size);
        }

        return *this;
    }

    void insert(const T& value) {
        _root = insert_recursive(_root, value);
    }

    void remove(const T& value) {
        _root = remove_recursive(_root, value);
    }

    bool find(const T& value) const {
        return find_recursive(_root, value) != nullptr;
    }

    void inorder() const {
        inorder_recursive(_root);
        std::cout << '\n';
    }

    void preorder() const {
        preorder_recursive(_root);
        std::cout << '\n';
    }

    void postorder() const {
        postorder_recursive(_root);
        std::cout << '\n';
    }

    int size() const {
        return _size;
    }

    int height() const {
        return height_recursive(_root);
    }

    void clear() {
        clear_recursive(_root);
        _root = nullptr;
        _size = 0;
    }

    bool is_empty() const {
        return _root == nullptr;
    }
};

#endif

