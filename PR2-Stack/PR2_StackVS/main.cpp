//main.cpp





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