#include "stack.h"
#include <stdexcept>

// Stack functions

Stack::Stack() {}

void Stack::push(int value) {
    data.push_back(value);
}

// Removes the top value from the stack
void Stack::pop() {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    data.pop_back();
}

// Returns the top value of the stack
int Stack::top() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

// Checks if the stack is empty
bool Stack::empty() const {
    return data.empty();
}

size_t Stack::size() const {
    return data.size();
}

// Computes the average of all elements in the stack
double Stack::average() const {
    if (empty()) {
        throw std::out_of_range("Stack is empty");
    }
    double sum = 0;
    for (int value : data) {
        sum += value;
    }
    return sum / data.size(); 

  
} 