#include <vector>
#include <cstddef>

using namespace std; 

class Stack {
private:
    vector<int> data;

public:
    Stack();

    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    size_t size() const;
    double average() const;
};