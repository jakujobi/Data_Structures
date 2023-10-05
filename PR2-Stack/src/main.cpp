//print hello world

#include <iostream>
#include "stack.h"
#include <string>
using namespace std;

int main(){
    cout << "hello world" << endl;

    Stack stack;

    stack.push("Hello");
    stack.push("World");

    stack.view();

    string top = stack.pop();
    cout << "Popped: " << top << endl;

    Stack copy = stack;
    copy.view();

    stack.push("Hello");
    stack.push("World");

    Stack another(3);
    another.push("A");
    another.push("B");
    another.push("C");

    another.view();

    return 0;
}