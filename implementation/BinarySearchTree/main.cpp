
#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

void test_constructor() {
    BinarySearchTree<int> bst;
    assert(bst.size() == 0);
    assert(bst.height() == 0);
    assert(bst.is_empty());
}

void test_insert() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    assert(bst.size() == 5);
    assert(bst.find(50));
    assert(bst.find(30));
    assert(bst.find(70));

    bst.insert(50);
    assert(bst.size() == 5);
}

void test_find() {
    BinarySearchTree<int> bst;

    assert(!bst.find(10));

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    assert(bst.find(10));
    assert(bst.find(5));
    assert(bst.find(15));
    assert(!bst.find(99));
}

void test_remove() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.remove(20);
    assert(!bst.find(20));
    assert(bst.size() == 6);

    bst.remove(30);
    assert(!bst.find(30));
    assert(bst.find(40));
    assert(bst.size() == 5);

    bst.remove(50);
    assert(!bst.find(50));
    assert(bst.size() == 4);

    assert(bst.find(40));
    assert(bst.find(60));
    assert(bst.find(70));
    assert(bst.find(80));

    bst.remove(999);
    assert(bst.size() == 4);
}

void test_height() {
    BinarySearchTree<int> bst;

    assert(bst.height() == 0);

    bst.insert(10);
    assert(bst.height() == 1);

    bst.insert(5);
    bst.insert(15);
    assert(bst.height() == 2);

    bst.insert(2);
    assert(bst.height() == 3);
}

void test_clear() {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    bst.clear();

    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);
    assert(!bst.find(10));

    bst.clear();
    bst.insert(20);
    assert(bst.find(20));
}

void test_copy_constructor() {
    BinarySearchTree<int> original;

    original.insert(10);
    original.insert(5);
    original.insert(15);

    BinarySearchTree<int> copy(original);

    assert(copy.size() == 3);
    assert(copy.find(10));
    assert(copy.find(5));
    assert(copy.find(15));

    copy.remove(5);
    assert(original.find(5));
    assert(!copy.find(5));

    BinarySearchTree<int> empty;
    BinarySearchTree<int> empty_copy(empty);
    assert(empty_copy.is_empty());
}

void test_assignment() {
    BinarySearchTree<int> a;
    a.insert(10);
    a.insert(5);

    BinarySearchTree<int> b;
    b.insert(99);

    b = a;

    assert(b.size() == 2);
    assert(b.find(10));
    assert(b.find(5));
    assert(!b.find(99));

    b.remove(5);
    assert(a.find(5));

    b = b;
    assert(b.size() == 1);

    BinarySearchTree<int> empty;
    b = empty;
    assert(b.is_empty());
}

void test_traversals() {
    BinarySearchTree<int> bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::ostringstream output;
    std::streambuf* old = std::cout.rdbuf(output.rdbuf());

    bst.inorder();
    std::string inorder_result = output.str();

    output.str("");
    output.clear();

    bst.preorder();
    std::string preorder_result = output.str();

    output.str("");
    output.clear();

    bst.postorder();
    std::string postorder_result = output.str();

    std::cout.rdbuf(old);

    assert(inorder_result == "20 30 40 50 70 \n");
    assert(preorder_result == "50 30 20 40 70 \n");
    assert(postorder_result == "20 40 30 70 50 \n");
}

int main() {
    std::cout << "Running BinarySearchTree tests\n";

    test_constructor();
    test_insert();
    test_find();
    test_remove();
    test_height();
    test_clear();
    test_copy_constructor();
    test_assignment();
    test_traversals();

    std::cout << "All tests passed\n";
    return 0;
}
