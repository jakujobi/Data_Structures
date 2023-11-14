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
    /// Default constructor
    /********************************************************************
    *** FUNCTION BST ***
    ***********************************************************************
    *** DESCRIPTION : Constructs an empty Binary Search Tree.           ***
    *** INPUT ARGS : None                                               ***
    *** OUTPUT ARGS : None                                              ***
    *** IN/OUT ARGS : None                                              ***
    *** RETURN : None                                                   ***
    ********************************************************************/
    BST();

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
    BST(const BST&);

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
    ~BST();

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
    void insert(const Element);

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
    void remove(const Element);

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
    NodePtr search(const Element) const;

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
    void preorderView() const;

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
    void inorderView() const; 

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
