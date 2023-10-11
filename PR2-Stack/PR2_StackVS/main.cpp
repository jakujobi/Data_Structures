//main.cpp

//!________________________________________________
// Driver/main Files (.cpp) 
/******************************************************************** 
*** NAME : JOHN AKUJOBI                                         *** 
*** CLASS : CSC 300 - DATA STRUCTURES                           *** 
*** ASSIGNMENT : Assignment #2 - Stack Testing                  *** 
*** DUE DATE : 10-06-23                                         *** 
*** INSTRUCTOR : GAMRADT                                        *** 
*********************************************************************/
/********************************************************************* 
*** DESCRIPTION : This program tests the Stack class to ensure that ***
                 every operation works as expected.                 ***
*********************************************************************/
#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
    /********************************************************************
    *** Test Case 1: Testing Default Constructor and Push            ***
    *********************************************************************/
    cout << "Test Case 1: Default Constructor and Push\n";
    Stack defaultStack; // Create a stack using default constructor and default capacity
    defaultStack.push("CSc"); // Push some elements onto the stack
    defaultStack.push("300");
    defaultStack.push("Data");
    defaultStack.view(); // Expected: TOP -> Data -> 300 -> CSc -> BOTTOM
    cout << "------------------------------------\n";

    /********************************************************************
    *** Test Case 2: Testing Parameterized Constructor and Resize     ***
    *********************************************************************/
    cout << "Test Case 2: Parameterized Constructor and Resize\n";
    Stack paramStack(1);    // Create a stack using parameterized constructor and given capacity of just 1
    paramStack.push("Structures");
    paramStack.push("ADT"); // Here it might resize if implemented correctly
    paramStack.view(); // Expected: TOP -> ADT -> Structures -> BOTTOM
    cout << "------------------------------------\n";

    /********************************************************************
    *** Test Case 3: Testing Copy Constructor                         ***
    *********************************************************************/
    cout << "Test Case 3: Copy Constructor\n";
    Stack copyOfDefaultStack = defaultStack; // Create a copy of the default stack
    copyOfDefaultStack.view(); // Expected: TOP -> Data -> 300 -> CSc -> BOTTOM
    cout << "------------------------------------\n";

    /********************************************************************
    *** Test Case 4: Testing Pop and Peek                             ***
    *********************************************************************/
    cout << "Test Case 4: Pop and Peek\n";
    Element topElement = defaultStack.pop();    // Pop the top element
    cout << "Popped Element: " << topElement << endl; // Expected: Data
    cout << "Peek after pop: " << defaultStack.peek() << endl; // Expected: 300
    defaultStack.view(); // Expected: TOP -> 300 -> CSc -> BOTTOM
    cout << "------------------------------------\n";

    /********************************************************************
    *** Test Case 5: Test Edge Case (Push on Full Stack)               ***
    *********************************************************************/
    cout << "Test Case 5: Push on Full Stack\n";
    // Depending on your implementation, this might show resize option
    paramStack.push("Stack");   // Push on full stack
    paramStack.push("Overflow");
    paramStack.view(); 
    cout << "------------------------------------\n";

    /********************************************************************
    *** Test Case 6: Test Edge Case (Pop from Empty Stack)             ***
    *** This is to check the error that was sent in the email.         ***
    *********************************************************************/
    cout << "Test Case 6: Pop from Empty Stack\n";
    Stack emptyStack;
    try {
        emptyStack.pop();
    } catch (const runtime_error& e) {
        cout << e.what() << endl; // Expected: Stack is empty. Cannot pop.
    }
    cout << "------------------------------------\n";

        /********************************************************************
    *** Test Case 7: Testing Destructor                               ***
    *********************************************************************/
    cout << "Test Case 7: Destructor\n";
    {
        Stack destructorStack;
        destructorStack.push("Test");
        destructorStack.push("Destructor");
        // Destructor will be called automatically at the end of this scope.
        // You won't see any output directly from this test case. 
        // The real test is to check if the program doesn't crash, indicating the destructor worked.
    }
    cout << "Destructor ran successfully.\n";
    cout << "------------------------------------\n";

    /********************************************************************
    *** Test Case 8: Peek on Empty Stack                              ***
    *********************************************************************/
    cout << "Test Case 8: Peek on Empty Stack\n";
    try {
        Stack anotherEmptyStack;
        anotherEmptyStack.peek();
    } catch (const runtime_error& e) {
        cout << e.what() << endl; // Expected: //OOP! The stack is empty. Cannot peek.
    }
    cout << "------------------------------------\n";

    /********************************************************************
    *** Test Case 9: Verify Resize Functionality                      ***
    *********************************************************************/
    cout << "Test Case 9: Verify Resize Functionality\n";
    Stack resizeStack(2);
    resizeStack.push("Initial");
    resizeStack.push("Size");
    resizeStack.push("Expanded"); // Here it might resize if implemented correctly
    resizeStack.view(); // Expected: TOP -> Expanded -> Size -> Initial -> BOTTOM
    cout << "------------------------------------\n";

    /********************************************************************
    *** Test Case 10: Test Copy Constructor with Empty Stack         ***
    *********************************************************************/
    cout << "Test Case 10: Copy Constructor with Empty Stack\n";
    Stack emptyOriginalStack;
    Stack copiedEmptyStack = emptyOriginalStack;
    copiedEmptyStack.view(); // Expected: TOP -> BOTTOM (because the copied stack should also be empty)
    cout << "------------------------------------\n";

    //********************************************************************

    return 0;
}


//! The old main function
// /******************************************************************** 
// *** NAME : JOHN AKUJOBI                                         *** 
// *** CLASS : CSC 300 - DATA STRUCTURES                           *** 
// *** ASSIGNMENT : Assignment #2 - Stack                          *** 
// *** DUE DATE : 10-06-23                                         *** 
// *** INSTRUCTOR : GAMRADT                                        *** 
// *********************************************************************/
// /*** DESCRIPTION : This program demonstrates the usage of the Stack class by        ***
//             - creating a stack                                                      ***
//             - pushing elements onto it                                              ***
//             - peeking at the top element                                            ***
//             - popping an element,                                                   ***
//             - resizing the stack,                                                   ***
//             - destroying the stack.                                                 ***
// *********************************************************************/

// #include <iostream>
// #include "Stack.h"
// using namespace std;

// /******************************************************************** 
// *** FUNCTION main *** 
// ********************************************************************* 
// *** DESCRIPTION : This function demonstrates the usage of the Stack class by creating a stack, pushing elements onto it, peeking at the top element, popping an element, and destroying the stack. *** 
// *** INPUT ARGS : None *** 
// *** OUTPUT ARGS : None *** 
// *** IN/OUT ARGS : None *** 
// *** RETURN : int (0) *** 
// ********************************************************************/
// int main() {
//     Stack stack; // Create a stack
//     cout << "Stack created. " << endl;

//     //Try to pop an element from the empty stack
//     cout << "\nAbout to try to pop an element from the empty stack." << endl;
//     try {
//         myStack.pop();
//     }
//     catch (const runtime_error& e) {
//         cout << e.what() << endl; // This will print "Stack is empty. Cannot pop."
//         // Handle error: perhaps prompt the user, or just continue the program
//     }

//     // Push some elements onto the stack and view the stack each time
//     cout << "\nAbout to Add " << "Element 2" << endl;
//     stack.push("Element 1");
//     cout << "Added element: " << "Element 1" << endl;
//     stack.view(); // Print the stack after pushing 1 element

//     cout << "\nAbout to Add " << "Element 2" << endl;
//     stack.push("Element 2");
//     cout << "Added element: " << "Element 2" << endl;
//     stack.view(); // Print the stack after pushing 2 elements

//     cout << "\nAbout to Add " << "Element 3" << endl;
//     stack.push("Element 3");
//     cout << "Added element: " << "Element 1" << endl;
//     stack.view(); // Print the stack after pushing 3 elements


//     // Peek at the top element
//     cout << "\nTop element: " << stack.peek() << endl;

//     // Pop an element
//     Element popped = stack.pop();
//     cout << "Popped element: " << popped << endl;

//     // Display the modified stack
//     cout << "\nModified stack contents:" << endl;
//     stack.view();

//     cout << endl;
//     stack.view(); // Print the stack

//     Stack stack2(stack);    // Copy the stack
//     stack2.view();            // Print the copied stack

//     cout << endl;
//     cout << "\nDestroy the stack" << endl;
//     //call the destructor to destroy the stack
//     //stack.destroy();

//     /*
//     cout << "\nCheck if the Stack is empty or not: " << endl;
//     // Check if the stack is empty after destruction
//     if (stack.empty()) {
//         cout << "Stack is empty after destruction." << endl;
//     } else {
//         cout << "Stack is not empty after destruction." << endl;
//     }
//     */

//     return 0;
// }