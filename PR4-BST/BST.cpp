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

#include "BST.h"
#include <iostream>

// Default constructor
/********************************************************************
*** FUNCTION BST ***
***********************************************************************
*** DESCRIPTION : Constructs an empty Binary Search Tree.           ***
*** INPUT ARGS : None                                               ***
*** OUTPUT ARGS : None                                              ***
*** IN/OUT ARGS : None                                              ***
*** RETURN : None                                                   ***
********************************************************************/
BST::BST() : root(nullptr) {

}


//TODO copy constructor
// Copy constructor
/********************************************************************
*** FUNCTION BST (copy constructor) ***
*********************************************************************
*** DESCRIPTION : Constructs a Binary Search Tree by copying an existing BST. ***
*** INPUT ARGS : const BST &source ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
BST::BST(const BST &source) : root(nullptr) {
    if (source.root != nullptr) {
        copy(source.root);
    }
}


//TODO destructor
// Destructor
/********************************************************************
*** FUNCTION ~BST ***
*********************************************************************
*** DESCRIPTION : Destroys the Binary Search Tree and deallocates memory. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
BST::~BST() {
    destroy(root);
}


//TODO insert
// Insert a new key node to the BST
/********************************************************************
*** FUNCTION insert ***
*********************************************************************
*** DESCRIPTION : Inserts a new key node to the BST. ***
*** INPUT ARGS : const Element element ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::insert(const Element element) {
    insert(root, element);
}


//TODO remove
// Locate and remove an existing key node from the BST
/********************************************************************
*** FUNCTION remove ***
*********************************************************************
*** DESCRIPTION : Locates and removes an existing key node from the BST. ***
*** INPUT ARGS : const Element element ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::remove(const Element element) {
    remove(root, element);
}


//TODO search
// Return a pointer to an existing key node in the BST, otherwise NULL
/********************************************************************
*** FUNCTION search ***
*********************************************************************
*** DESCRIPTION : Returns a pointer to an existing key node in the BST, otherwise NULL. ***
*** INPUT ARGS : const Element element ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : NodePtr ***
********************************************************************/
NodePtr BST::search(const Element element) const {
    return search(root, element);
}


//TODO preorderView
// Display the keys in the BST from top to bottom (left to right)
/********************************************************************
**
//* FUNCTION preorderView ***
*********************************************************************
*** DESCRIPTION : Displays the keys in the BST from top to bottom (left to right). ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::preorderView() const {
    preorderView(root);
}


//TODO inorderView
// Display the keys in the BST in ascending order
/********************************************************************
*** FUNCTION inorderView ***
*********************************************************************
*** DESCRIPTION : Displays the keys in the BST in ascending order. ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::inorderView() const {
    inorderView(root);
}


//TODO postorderView
// Display the keys in the BST from bottom to top (left to right)
/********************************************************************
*** FUNCTION postorderView ***
*********************************************************************
*** DESCRIPTION : Displays the keys in the BST from bottom to top (left to right). ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::postorderView() const {
    postorderView(root);
}


// !Private member functions_____________________________________________________________________________________________________________________

//TODO copy
// Recursively copy an existing BST
/********************************************************************
*** FUNCTION copy ***
*********************************************************************
*** DESCRIPTION : Recursively copies an existing BST. ***
*** INPUT ARGS : const NodePtr source ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::copy(const NodePtr source) {
    // Implementation goes here
}


//TODO destroy (recursive version)
// Recursively remove all key nodes from the BST
/********************************************************************
*** FUNCTION destroy ***
*********************************************************************
*** DESCRIPTION : Recursively removes all key nodes from the BST. ***
*** INPUT ARGS : NodePtr &tree ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::destroy(NodePtr &tree) {
    // Implementation goes here
}


//TODO removeNode
// Remove an existing key node from the BST
/********************************************************************
*** FUNCTION removeNode ***
*********************************************************************
*** DESCRIPTION : Removes an existing key node from the BST. ***
*** INPUT ARGS : NodePtr &tree ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::removeNode(NodePtr &tree) {
    // Implementation goes here


    //Search for the node to be removed
}


//TODO findMaxNode
// Find the maximum key node in the left subtree of the BST
/********************************************************************
*** FUNCTION findMaxNode ***
*********************************************************************
*** DESCRIPTION : Finds the maximum key node in the left subtree of the BST. ***
*** INPUT ARGS : NodePtr &tree, NodePtr &maxNode ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::findMaxNode(NodePtr &tree, NodePtr &maxNode) {
    // Implementation goes here

    //If the tree is empty, return null

    //If the tree is not empty, find the maximum key node in the left subtree

    //Go to the left subtree

    //Traverse to the right continously until the right subtree is empty
}


//TODO insert (recursive version)
// Recursive version of insert
/********************************************************************
*** FUNCTION insert (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively inserts a new key node to the BST. ***
*** INPUT ARGS : NodePtr &tree, const Element element ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::insert(NodePtr &tree, const Element element) {
    // If the tree is empty, create a new node
    if (tree == nullptr) {
        tree = new Node;
        tree->element = element;    // Set the element
        tree->left = nullptr;       // Set left and right children to null
        tree->right = nullptr;
    }
    
    // If the element is less than the current node, insert to the left
    else if (element < tree->element) {
        insert(tree->left, element);
    }
    
    // If the element is greater than the current node, insert to the right
    else if (element > tree->element) {
        insert(tree->right, element);
    }
}


//TODO remove (recursive version)
// Recursive version of remove
/********************************************************************
*** FUNCTION remove (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively removes an existing key node from the BST. ***
*** INPUT ARGS : NodePtr &tree, const Element element ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::remove(NodePtr &tree, const Element element) {
    // Implementation goes here

    //If the tree is empty, return null and tell the user that the BST is empty
    if (tree == nullptr) {
        cout << "The BST is empty. Cannot remove a node." << endl;
        return;
    }

    else {
        //Search for the node to be removed

    }
}


//TODO search (recursive version)
// Recursive version of search
/********************************************************************
*** FUNCTION search (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively searches for an existing key node in the BST. ***
*** INPUT ARGS : const NodePtr tree, const Element element ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : NodePtr ***
********************************************************************/
NodePtr BST::search(const NodePtr tree, const Element element) const {
    // Implementation goes here

    //If the tree is empty, return null
    if (tree == nullptr) {
        return nullptr;
    }

    //and tell the user that the element is not in the BST because it is empty


    //If the element is less than the current node, search the left subtree

    //If the element is greater than the current node, search the right subtree
}


//TODO preorderView (recursive version)
// Recursive version of preorderView
/********************************************************************
*** FUNCTION preorderView (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively displays the keys in the BST from top to bottom (left to right). ***
*** INPUT ARGS : const NodePtr tree ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::preorderView(const NodePtr tree) const {
    // Implementation goes here

    //If the tree is empty, return null

}


//TODO inorderView (recursive version)
// Recursive version of inorderView
/********************************************************************
*** FUNCTION inorderView (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively displays the keys in the BST in ascending order. ***
*** INPUT ARGS : const NodePtr tree ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::inorderView(const NodePtr tree) const {
    // Implementation goes here

    //If the tree is empty, return null and tell the user that the BST is empty
}


//TODO postorderView (recursive version)
// Recursive version of postorderView
/********************************************************************
*** FUNCTION postorderView (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively displays the keys in the BST from bottom to top (left to right). ***
*** INPUT ARGS : const NodePtr tree ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::postorderView(const NodePtr tree) const {
    // Implementation goes here

    //If the tree is empty, return null and tell the user that the BST is empty
}