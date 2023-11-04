/********************************************************************
*** NAME : John Akujobi ***
*** CLASS : CSc 300 ***
*** ASSIGNMENT : 4 ***
*** DUE DATE : 11-08-23 ***
*** INSTRUCTOR : GAMRADT ***
*********************************************************************
*** DESCRIPTION : This program rigorously tests the Binary Search Tree (BST) ***
*** implementation for correctness and robustness. It includes tests for ***
*** insertion, deletion, searching, and traversal. ***
********************************************************************/

#include "BST.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

//This includes some tests that were refined by an online unit tests generator.
//Code from stackoverflow responses were used in coming up with some of these tests and how they work

int main() {
    BST myTree;

    // Test 1: Insertion and Inorder Traversal
    cout << "Test 1: Insertion and Inorder Traversal\n";
    for (int i = 0; i < 10; ++i) {
        myTree.insert(i);
    }
    myTree.inorderView(); // Expected: Ordered sequence from 0 to 9

    // Test 2: Duplicate Insertion
    cout << "\nTest 2: Duplicate Insertion\n";
    myTree.insert(5);
    myTree.inorderView(); // Expected: No change, duplicates ignored

    // Test 3: Deletion of Non-Existent Element
    cout << "\nTest 3: Deletion of Non-Existent Element\n";
    myTree.remove(10);
    myTree.inorderView(); // Expected: No change, element not found

    // Test 4: Deletion of Leaf Node
    cout << "\nTest 4: Deletion of Leaf Node\n";
    myTree.remove(0);
    myTree.inorderView(); // Expected: Sequence from 1 to 9

    // Test 5: Deletion of Node with One Child
    cout << "\nTest 5: Deletion of Node with One Child\n";
    myTree.remove(8);
    myTree.inorderView(); // Expected: Sequence from 1 to 7, then 9

    // Test 6: Deletion of Node with Two Children
    cout << "\nTest 6: Deletion of Node with Two Children\n";
    myTree.remove(5);
    myTree.inorderView(); // Expected: Sequence from 1 to 4, then 6 to 7, then 9

    // Test 7: Search for Existing and Non-Existing Elements
    cout << "\nTest 7: Search for Existing and Non-Existing Elements\n";
    assert(myTree.search(3) != nullptr); // Should find element
    assert(myTree.search(10) == nullptr); // Should not find element

    // Test 8: Preorder and Postorder Traversal
    cout << "\nTest 8: Preorder and Postorder Traversal\n";
    myTree.preorderView(); // Expected: Preorder sequence
    myTree.postorderView(); // Expected: Postorder sequence

    // Test 9: Clearing the Tree
    cout << "\nTest 9: Clearing the Tree\n";
    BST newTree(myTree); // Copy constructor
    newTree.~BST(); // Destructor
    newTree.inorderView(); // Expected: BEGIN -> END (Empty tree)

    // Test 10: Large Number of Elements
    cout << "\nTest 10: Large Number of Elements\n";
    for (int i = 0; i < 1000; ++i) {
        myTree.insert(i);
    }
    myTree.inorderView(); // Expected: Ordered sequence from 1 to 999

    // Additional rigorous tests
    // Test 11: Removing root repeatedly
    cout << "\nTest 11: Removing root repeatedly\n";
    myTree.remove(20); // Remove current root
    for (int i = 999; i >= 0; --i) {
        myTree.remove(i); // Remove new root each time
    }
    myTree.inorderView(); // Expected: BEGIN -> END (Empty tree)

    // Test 12: Inserting in descending order
    cout << "\nTest 12: Inserting in descending order\n";
    for (int i = 100; i > 0; --i) {
        myTree.insert(i);
    }
    myTree.inorderView(); // Expected: Ordered sequence from 1 to 100

    // Test 13: Removing leaves, internal nodes, and root
    cout << "\nTest 13: Removing leaves, internal nodes, and root\n";
    myTree.remove(1); // Remove leaf
    myTree.remove(50); // Remove internal node
    myTree.remove(100); // Remove root
    myTree.inorderView(); // Expected: Ordered sequence from 2 to 99, excluding 50

    // Test 14: Searching for elements at different positions
    cout << "\nTest 14: Searching for elements at different positions\n";
    assert(myTree.search(2) != nullptr); // Leaf
    assert(myTree.search(75) != nullptr); // Internal node
    assert(myTree.search(99) != nullptr); // Root
    assert(myTree.search(101) == nullptr); // Non-existent

    // Test 15: Stress test with random insertions and deletions
    cout << "\nTest 15: Stress test with random insertions and deletions\n";
    srand(time(nullptr)); // Seed random number generator
    for (int i = 0; i < 1000; ++i) {
        int num = rand() % 2000; // Random number between 0 and 1999
        if (rand() % 2) {
            myTree.insert(num);
        } else {
            myTree.remove(num);
        }
    }
    myTree.inorderView(); // Expected: A sequence of numbers, some missing due to deletions

    cout << "\nAll tests passed successfully!\n";
    return 0;
}
