#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    Stack stack;

    stack.push(20);
    stack.push(40);
    stack.push(60);
    stack.push(80);

    if (stack.empty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    
    cout << "Top of stack: " << stack.top() << endl;

    stack.pop();

    cout << "Top of stack after pop: " << stack.top() << endl;
    cout << "Average value of stack elements: " << stack.average() << endl;

    return 0;
}