//BST.cpp
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
#include <string>

using namespace std;

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
    root = nullptr;
    //This indicates that the tree is empty
}


//! copy constructor
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
BST::BST(const BST& source) : root(nullptr) {
    //root = nullptr;
    try {
        copy(source.root);
    }
    catch (const runtime_error& e) {
        throw runtime_error("Could not copy the BST");
        return;
    }
}


//! destructor
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
    // //If the tree is empty, return
    // if (root == nullptr) {
    //     cout << "The BST is empty. Cannot destroy the tree." << endl;
    //     return;
    // }
    destroy(root);
    delete root;
    root = nullptr;
}


//! insert
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
    try {
        insert(root, element);
    }
    catch (const runtime_error& e) {
        throw runtime_error("Could not insert into the BST");
        return;
    }
}


//! remove
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
    try {
        //if (root != nullptr) {
            remove(root, element);
        //}
    }
    catch (const runtime_error& e) {
        throw runtime_error("Could not remove from the BST");
        return;
    }
}


//! search
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
    try {
        return search(root, element);
    }
    catch (const runtime_error& e) {
        throw runtime_error("Could not search the BST");
        return nullptr;
    }
}


//! preorderView
// Display the keys in the BST from top to bottom (left to right)
//********************************************************************
/* FUNCTION preorderView ***
*********************************************************************
*** DESCRIPTION : Displays the keys in the BST from top to bottom (left to right). ***
*** INPUT ARGS : None   ***
*** OUTPUT ARGS : None  ***
*** IN/OUT ARGS : None  ***
*** RETURN : None       ***
********************************************************************/
void BST::preorderView() const {
    try {
        cout << "BEGIN -> ";
        preorderView(root);
        cout << "END" << endl;
    }
    catch (const runtime_error& e) {
        throw runtime_error("Could not preorder view the BST");
        return;
    }
}


//! inorderView
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
    try {
        cout << "BEGIN -> ";
        inorderView(root);
        cout << "END" << endl;
    }
    catch (const runtime_error& e) {
        throw runtime_error("Could not inorder view the BST");
        return;
    }
}


//! postorderView
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
    try {
        cout << "BEGIN -> ";
        postorderView(root);
        cout << "END" << endl;
    }
    catch (const runtime_error& e) {
        throw runtime_error("Could not remove from the BST");
        return;
    }
}


// !Private member functions_____________________________________________________________________________________________________________________

//! copy
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
void BST::copy(const NodePtr sourceRoot) {
    // Start copying from the root
    if (sourceRoot != nullptr) {
        insert(sourceRoot->element); // Insert the element to the current tree
        copy(sourceRoot->left);      // Copy left subtree
        copy(sourceRoot->right);     // Copy right subtree
    }
}



//! destroy (recursive version)
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
    if (tree != nullptr) {
        //if the tree has a left child, destroy it
        //if (tree->left != nullptr) {
            destroy(tree->left);
        //}

        //if the tree has a right child, destroy it
        //if (tree->right != nullptr) {
            destroy(tree->right);
        //}

        //delete the current node
        delete tree;
        tree = nullptr;
    }
}



//! remove (recursive version)
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
// void BST::remove(NodePtr &tree, const Element element) {
//     //If the tree is not empty, remove the node
//     if (tree != nullptr) {
//         //Search for the node to be removed
//         tree = search(tree, tree->element);
//         if (tree == nullptr) {
// 			cout << "The element does not exist in the BST." << endl;
// 			return;
// 		}
//         removeNode(tree);
//     }

//     else {
//         cout << "The BST is empty. Cannot remove a node." << endl;
//         return;
//     }
// }
void BST::remove(NodePtr &tree, const Element element) {
    // If the tree is empty, return
    if (tree == nullptr) {
        cout << "Cannot remove the node." << endl;
        return;
    }

    // If the element to be removed is less than the current node's element, go to the left subtree
    if (element < tree->element) {
        remove(tree->left, element);
    }
    // If the element to be removed is greater than the current node's element, go to the right subtree
    else if (element > tree->element) {
        remove(tree->right, element);
    }
    // Found the node with the element
    else {
        removeNode(tree);
    }
}


//! removeNode
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
// void BST::removeNode(NodePtr &tree) {
//     //If the tree is empty, return
//     if (tree!=nullptr) {
//         //If the node is a leaf node, that is, has no children, delete the node
//         if (tree->left == nullptr && tree->right == nullptr) {
//             delete tree;
//             tree = nullptr;
//             return;
//         }

//         //If the node has one child on the left, delete the node and replace it with the left child
//         else if (tree->left != nullptr && tree->right == nullptr) {
//             NodePtr temp = tree;
//             tree = tree->left;
//             temp = nullptr;
//             delete temp;
//             return;
//         }

//         //If the node has one child on the right, delete the node and replace it with the right child
//         else if (tree->left == nullptr && tree->right != nullptr) {
//             NodePtr temp = tree;
//             tree = tree->right;
//             temp = nullptr;
//             delete temp;
//             return;
//         }

//         //If the node has two children, find the maximum key node in the left subtree and replace the node with the maximum key
//         else if (tree->left != nullptr && tree->right != nullptr) {
//             // NodePtr maxNode = nullptr;
//             // findMaxNode(tree->left, maxNode);
//             // tree->element = maxNode->element;
//             // delete maxNode;

//             NodePtr maxNode, maxNodeParent, temp;

//             temp = tree->left;

//             findMaxNode(temp, maxNode); // Find the maximum node in the left subtree
//             maxNodeParent = tree; // The parent of the maxNode is the node to be removed
//             tree->element = maxNode->element; // Replace the node's element with the max node's element

//             if (maxNodeParent->left == maxNode) {
//                 maxNodeParent->left = maxNode->left; // Replace maxNode with its left child
//             }
//             else {
//                 maxNodeParent->right = maxNode->left; // Replace maxNode with its left child
//             }

//             temp = nullptr;
//             maxNode = nullptr;
//             maxNodeParent = nullptr;

//             delete maxNode; // Delete the maxNode
//             delete temp;
//             delete maxNodeParent;

//             return;
//         }
//     }

//     else {
//         cout << "The BST is empty. Cannot remove from the tree." << endl;
//         tree = nullptr;
//         return;
//     }
// }

void BST::removeNode(NodePtr &tree) {
    // If the tree is empty, return
    if (tree == nullptr) {
        cout << "The BST is empty. Cannot remove from the tree." << endl;
        return;
    }

    // If the node is a leaf node, delete the node
    if (tree->left == nullptr && tree->right == nullptr) {
        delete tree;
        tree = nullptr;
    }
    // If the node has one child on the left
    else if (tree->left != nullptr && tree->right == nullptr) {
        NodePtr temp = tree;
        tree = tree->left;
        delete temp;
    }
    // If the node has one child on the right
    else if (tree->left == nullptr && tree->right != nullptr) {
        NodePtr temp = tree;
        tree = tree->right;
        delete temp;
    }
    // If the node has two children
    else {
        NodePtr maxNodeParent = tree;
        NodePtr maxNode = tree->left;

        // Find the maximum node in the left subtree
        while (maxNode->right != nullptr) {
            maxNodeParent = maxNode;
            maxNode = maxNode->right;
        }

        // Replace the node's element with the max node's element
        tree->element = maxNode->element;

        // Remove the max node
        if (maxNodeParent == tree) {
            maxNodeParent->left = maxNode->left;
        } else {
            maxNodeParent->right = maxNode->left;
        }

        delete maxNode;
    }
}




//! findMaxNode
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
void BST::findMaxNode(NodePtr& temp, NodePtr& maxNode) {
    // Traverse to the rightmost node
    try {
        maxNode = temp;
        
        if (temp == nullptr) {
            cout <<"Could not find the Maximum Node" << endl;
            return;
        }

        else if (temp->right == nullptr) {
            return;
        }

        while (maxNode->right != nullptr) {
            temp = maxNode; // Keep track of the parent
            maxNode = maxNode->right; // Move to the right child
        }
    }
    catch (const runtime_error& e) {
        throw runtime_error("Could not find the Maximum Node");
        return;
    }

}


//! insert (recursive version)
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
void BST::insert(NodePtr &tree, const Element value) {
    // If the tree is empty, create a new node
    if (tree == nullptr) {
        tree = new Node;
        tree->element = value;    // Set the element
        tree->left = nullptr;       // Set left and right children to null
        tree->right = nullptr;
        return;
    }
    
    // If the element is less than the current node, insert to the left
    else if (value < tree->element) {
        insert(tree->left, value);
    }
    
    // If the element is greater than the current node, insert to the right
    else if (value > tree->element) {
        insert(tree->right, value);
    }

    //else if (element == tree->element) 
    else {
        cout << "The element, " << value << ", already exists in the BST." << endl;
        return;
    }
}


//! search (recursive version)
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
    //If the tree is empty, return null
    //and tell the user that the element is not in the BST because it is empty
    if (tree == nullptr) {
        cout << "The BST is empty. Cannot search for a node." << endl;
        return nullptr;
    }

    //If the element is equal to the current node, return the current node
    else if (element == tree->element) {
        return tree;
    }

    //If the element is less than the current node, search the left subtree
    else if (element < tree->element) {
        return search(tree->left, element);
    }

    //If the element is greater than the current node, search the right subtree
    else if (element > tree->element){
        return search(tree->right, element);
    }

    else {
        //If the element is not in the BST, return null
		return nullptr;
	}
}


//! preorderView (recursive version)
// Recursive version of preorderView
/********************************************************************
*** FUNCTION preorderView (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively displays the keys in the BST from top to bottom (left to right). CLR***
*** INPUT ARGS : const NodePtr tree ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::preorderView(const NodePtr tree) const {
    // //If the tree is empty, return null
    // if (tree == nullptr) {
    //     cout << "The BST is empty. Cannot display the tree." << endl;
    //     return;
    // }

    if (tree != nullptr) {
        //print the data of the current node
        cout << tree->element << " -> ";

        //print the data on the left child
        if (tree->left != nullptr) {
            preorderView(tree->left);
        }

        //print the data on the right child
        if (tree->right != nullptr) {
            preorderView(tree->right);
        }
    }
}


//! inorderView (recursive version)
// Recursive version of inorderView
/********************************************************************
*** FUNCTION inorderView (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively displays the keys in the BST in ascending order.LCR ***
*** INPUT ARGS : const NodePtr tree ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::inorderView(const NodePtr tree) const {
    //If the tree is empty, return null and tell the user that the BST is empty
    if (tree != nullptr) {
        inorderView(tree->left);           // Visit left subtree
        cout << tree->element << " -> "; // Visit node
        inorderView(tree->right);          // Visit right subtree
    }
}


//! postorderView (recursive version)
// Recursive version of postorderView
/********************************************************************
*** FUNCTION postorderView (recursive version) ***
*********************************************************************
*** DESCRIPTION : Recursively displays the keys in the BST from bottom to top (left to right). RCL ***
*** INPUT ARGS : const NodePtr tree ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void BST::postorderView(const NodePtr tree) const {
    // //If the tree is empty, return null and tell the user that the BST is empty
    // if (tree == nullptr) {
    //     cout << "The BST is empty. Cannot display the tree." << endl;
    //     return;
    // }

    if (tree != nullptr) {
        //print the left child
        if (tree->left != nullptr) {
            postorderView(tree->left);
        }

        //print the right child
        if (tree->right != nullptr) {
            postorderView(tree->right);
        }

        //print the current node
        cout << tree->element << " -> ";
    }
}