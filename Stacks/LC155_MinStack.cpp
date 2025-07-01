/*
LeetCode 155. Min Stack
https://leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
- MinStack() initializes the stack object.
- void push(int val) pushes the element val onto the stack.
- void pop() removes the element on the top of the stack.
- int top() gets the top element of the stack.
- int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

Example:
Input:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output:
[null,null,null,null,-3,null,0,-2]

Time Complexity: O(1) for all operations
Space Complexity: O(n)
*/

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s;        // Main stack
    stack<int> minStack; // Stack to keep track of minimums

public:
    MinStack() {
        // Constructor
    }

    void push(int val) {
        s.push(val);
        // Push to minStack if empty or new val <= current min
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }

    void pop() {
        if (s.top() == minStack.top())
            minStack.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack* minStack = new MinStack();
    
    // Test Case 1: From LeetCode example
    cout << "Test Case 1:" << endl;
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << "getMin(): " << minStack->getMin() << endl;  // should return -3
    minStack->pop();
    cout << "top(): " << minStack->top() << endl;        // should return 0
    cout << "getMin(): " << minStack->getMin() << endl;  // should return -2
    cout << endl;
    
    // Test Case 2: More operations
    cout << "Test Case 2:" << endl;
    minStack->push(-5);
    cout << "getMin(): " << minStack->getMin() << endl;  // should return -5
    minStack->push(1);
    cout << "top(): " << minStack->top() << endl;        // should return 1
    cout << "getMin(): " << minStack->getMin() << endl;  // should return -5
    minStack->pop();
    cout << "getMin(): " << minStack->getMin() << endl;  // should return -5
    
    delete minStack;
    return 0;
} 