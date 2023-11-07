
//!_______________________________________________________________
/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment //!# - ###############              *** 
*** DUE DATE : //!                                               *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/
/********************************************************************* 
*** DESCRIPTION : //!############################################
*********************************************************************/

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
