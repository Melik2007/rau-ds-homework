
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& d) : data(d), left(nullptr), right(nullptr) {}
    };
    
    Node* _root;
    int _size;
    
    Node* insert_recursive(Node* node, const T& value);
    Node* remove_recursive(Node* node, const T& value);
    Node* find_recursive(Node* node, const T& value) const;
    void clear_recursive(Node* node);
    int height_recursive(Node* node) const;

public:
    /// 1. Конструктор по умолчанию
    BinarySearchTree();
    
    /// 2. Деструктор
    ~BinarySearchTree();
    
    /// 3. Конструктор копирования
    BinarySearchTree(const BinarySearchTree& other);
    
    /// 4. Оператор присваивания
    BinarySearchTree& operator=(const BinarySearchTree& other);
    
    /// 5. insert(const T& value) - вставить
    void insert(const T& value);
    
    /// 6. remove(const T& value) - удалить
    void remove(const T& value);
    
    /// 7. find(const T& value) - найти элемент
    bool find(const T& value) const;
    
    /// 8. inorder() - обход в порядке (выводит на консоль)
    void inorder() const;
    
    /// 9. preorder() - префиксный обход
    void preorder() const;
    
    /// 10. postorder() - постфиксный обход
    void postorder() const;
    
    /// 11. size() - количество элементов
    int size() const;
    
    /// 12. height() - высота дерева
    int height() const;
    
    /// 13. clear() - очистить
    void clear();
    
    /// 14. is_empty() - пусто ли
    bool is_empty() const;
};

#endif // BINARYSEARCHTREE_H
