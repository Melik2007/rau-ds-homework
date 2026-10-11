
#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>

// Реализуйте методы BinarySearchTree<T>:
//   1. BinarySearchTree()              - конструктор
//   2. ~BinarySearchTree()             - деструктор
//   3. BinarySearchTree(const &)       - конструктор копирования
//   4. operator=(const &)              - оператор присваивания
//   5. insert(const T&)                - вставить
//   6. remove(const T&)                - удалить
//   7. find(const T&)                  - найти
//   8. inorder()                       - обход в порядке
//   9. preorder()                      - префиксный обход
//  10. postorder()                     - постфиксный обход
//  11. size()                          - размер
//  12. height()                        - высота
//  13. clear()                         - очистить
//  14. is_empty()                      - пусто ли

void test_insert() {
    BinarySearchTree<int> bst;
    
    bst.insert(50);
    assert(bst.size() == 1);
    assert(bst.find(50));
    
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    assert(bst.size() == 5);
    assert(bst.find(30));
    assert(bst.find(70));
    
    std::cout << "test_insert passed" << std::endl;
}

// void test_remove() { ... }
// void test_find() { ... }

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;
    test_insert();
    std::cout << "All tests passed" << std::endl;
    return 0;
}

