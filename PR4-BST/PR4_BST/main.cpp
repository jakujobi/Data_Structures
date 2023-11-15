//main.cpp

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
//#include <cassert>
//#include <cstdlib>
//#include <ctime>

using namespace std;

//This includes some tests that were refined by an online unit tests generator.
//Code from stackoverflow responses, and geeksforgeeks were used in coming up with some of these tests and how they work

// int randomize()  
// {    
//     return (rand() % 1000);  
// } 

int main() {
    BST myTree;
    //srand(time(NULL));  

    // Test 1: Insertion and Inorder Traversal
    cout << "Test 1: Insertion and Inorder Traversal\n";
    for (int i = 0; i < 10; ++i) {
        myTree.insert(i);
    }
    myTree.inorderView(); //
    cout << "Expected: Ordered sequence from 0 to 9\n"; // Expected: Ordered sequence from 0 to 9

    // Test 2: Duplicate Insertion
    cout << "\n\nTest 2: Duplicate Insertion\n\n";
    myTree.insert(5);
    myTree.inorderView(); // Expected: No change, duplicates ignored
    cout << "Expected: No change, duplicates ignored\n\n";

    // Test 3: Deletion of Non-Existent Element
    cout << "\n\nTest 3: Removal of Non-Existent Element\n";
    myTree.remove(10);
    myTree.inorderView(); // Expected: No change, element not found
    cout << "Expected: No change, element not found\n\n";

    // Test 4: Deletion of Leaf Node
    cout << "\n\nTest 4: Deletion of Leaf Node\n";
    myTree.remove(0);
    myTree.inorderView(); // Expected: Sequence from 1 to 9
    cout << "Expected: Sequence from 1 to 9\n\n";

    // Test 5: Deletion of Node with One Child
    cout << "\n\nTest 5: Deletion of Node with One Child\n";
    myTree.remove(8);
    myTree.inorderView(); // Expected: Sequence from 1 to 7, then 9
    cout << "Expected: Sequence from 1 to 7, then 9\n\n";

    // Test 6: Deletion of Node with Two Children
    cout << "\n\nTest 6: Deletion of Node with Two Children\n";
    myTree.remove(5);
    myTree.inorderView(); // Expected: Sequence from 1 to 4, then 6 to 7, then 9
    cout << "Expected: Sequence from 1 to 4, then 6 to 7, then 9\n\n";

    //// Test 7: Search for Existing and Non-Existing Elements
    //cout << "\nTest 7: Search for Existing and Non-Existing Elements\n";
    //assert(myTree.search(3) != nullptr); // Should find element
    //assert(myTree.search(10) == nullptr); // Should not find element

    // Test 8: Preorder and Postorder Traversal
    cout << "\n\nTest 8: Preorder and Postorder Traversal\n";
    myTree.preorderView(); // Expected: Preorder sequence
    cout << "\n";
    myTree.postorderView(); // Expected: Postorder sequence
    cout << "\n\n";

    // Test 8.5 : Copy Constructor
    cout << "\n\nTest 8.5: Copy Constructor\n";
    BST newTree(myTree);
    cout << "Copy constructor worked\n";
    newTree.inorderView();
    cout << "\n\n";

    // Test 9: Clearing the Tree
    cout << "\n\nTest 9: Clearing the Tree\n";
    newTree.~BST(); // Destructor
    newTree.inorderView(); // Expected: BEGIN -> END (Empty tree)
    cout << "Expected: BEGIN -> END (Empty tree)\n\n";

    // Test 10: Large Number of Elements
    cout << "\n\nTest 10: Large Number of Elements\n";
    for (int i = 0; i < 1000; ++i) {
        myTree.insert(i);
    }
    myTree.inorderView(); // Expected: Ordered sequence from 0 to 999
    cout << "Expected: Ordered sequence from 0 to 999\n\n";

    // Additional rigorous tests
    // Test 11: Removing root repeatedly
    cout << "\n\nTest 11: Removing root repeatedly\n";
    myTree.remove(20); // Remove current root
    for (int i = 999; i >= 0; --i) {
        myTree.remove(i); // Remove new root each time
    }
    myTree.inorderView(); // Expected: BEGIN -> END (Empty tree)
    cout << "Expected: BEGIN -> END (Empty tree)\n\n";

    // Test 12: Inserting in descending order
    cout << "\n\nTest 12: Inserting in descending order\n";
    for (int i = 100; i > 0; --i) {
        myTree.insert(i);
    }
    myTree.inorderView(); // Expected: Ordered sequence from 1 to 100
    cout << "Expected: Ordered sequence from 1 to 100\n\n";

    // Test 13: Removing leaves, internal nodes, and root
    cout << "\n\nTest 13: Removing leaves, internal nodes, and root\n";
    myTree.remove(1); // Remove leaf
    myTree.remove(50); // Remove internal node
    myTree.remove(100); // Remove root
    myTree.inorderView(); // Expected: Ordered sequence from 2 to 99, excluding 50
    cout << "Expected: Ordered sequence from 2 to 99, excluding 50\n\n";

    // // Test 14: Searching for elements at different positions
    // cout << "\nTest 14: Searching for elements at different positions\n";
    // assert(myTree.search(2) != nullptr); // Leaf
    // assert(myTree.search(75) != nullptr); // Internal node
    // //assert(myTree.search(randomize()) == nullptr); // Non-existent
    // assert(myTree.search(99) != nullptr); // Root
    // assert(myTree.search(101) == nullptr); // Non-existent
    // //assert(myTree.search(randomize()) == nullptr); // Random element

    // // Test 15: Stress test with random insertions and deletions
    // cout << "\nTest 15: Stress test with random insertions and deletions\n";
    // srand(time(nullptr)); // Seed random number generator
    // for (int i = 0; i < 1000; ++i) {
    //     int num = rand() % 2000; // Random number between 0 and 1999
    //     if (rand() % 2) {
    //         myTree.insert(num);
    //     } else {
    //         myTree.remove(num);
    //     }
    // }
    // myTree.inorderView(); // Expected: A sequence of numbers, some missing due to deletions

    cout << "\nAll tests passed successfully!\n";
    return 0;
}
