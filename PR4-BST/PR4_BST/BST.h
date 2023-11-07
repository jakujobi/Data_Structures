//BST.h
/**************************************************************************
*** NAME : John Akujobi                                                 ***
*** CLASS : CSc 300 - Data Structures                                   ***
*** ASSIGNMENT : 4                                                      ***
*** DUE DATE : 11-08-23                                                 ***
*** INSTRUCTOR : GAMRADT                                                ***
***************************************************************************
*** DESCRIPTION : This implementation file defines the functions for    ***
*** the Binary Search Tree (BST) Abstract Data Type (ADT). It includes  ***
*** methods for inserting, removing, and searching for elements as      ***
*** well as traversing the tree in pre-order, in-order, and post-order. ***
***************************************************************************/

// Binary Search Tree ADT
// Supported operations: 
// Insert, remove, search, preorder/inorder/postorder traversal

#pragma once

typedef int Element;

struct Node;
typedef Node* NodePtr;

struct Node {
    Element element;
    NodePtr left, right; 
};

class BST {
public:
    // Constructor/destructor
    BST();
    BST(const BST&);
    ~BST();
    
    // ADT operations
    void insert(const Element);
    void remove(const Element);
    NodePtr search(const Element) const;
    void preorderView() const;
    void inorderView() const; 
    void postorderView() const;

    private:
    // Private data members
    NodePtr root;
    
    // Private helper functions
    void copy(const NodePtr); //Edited to include destination tree
    void destroy(NodePtr&);
    void removeNode(NodePtr&);
    void findMaxNode(NodePtr&, NodePtr&);
    void insert(NodePtr&, const Element);
    void remove(NodePtr&, const Element); 
    NodePtr search(const NodePtr, const Element) const;
    void preorderView(const NodePtr) const;
    void inorderView(const NodePtr) const;
    void postorderView(const NodePtr) const;
};
