/*
LeetCode 225. Implement Stack using Queues
https://leetcode.com/problems/implement-stack-using-queues/

Implement a last-in-first-out (LIFO) stack using only two queues. 
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:
- void push(int x) Pushes element x to the top of the stack.
- int pop() Removes the element on the top of the stack and returns it.
- int top() Returns the element on the top of the stack.
- boolean empty() Returns true if the stack is empty, false otherwise.

Example:
Input:
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output:
[null, null, null, 2, 2, false]

Time Complexity:
- Push: O(n)
- Pop: O(1)
- Top: O(1)
- Empty: O(1)
*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        int size = q.size();
        // Rotate the queue to make the last element come to the front
        while (--size) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int top = q.front();
        q.pop();
        return top;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};


int main() {
    MyStack* stack = new MyStack();
    
    // Test Case 1: Basic operations
    cout << "Test Case 1:" << endl;
    stack->push(1);
    stack->push(2);
    cout << "top(): " << stack->top() << endl;   // should return 2
    cout << "pop(): " << stack->pop() << endl;   // should return 2
    cout << "empty(): " << (stack->empty() ? "true" : "false") << endl;  // should return false
    cout << endl;
    
    // Test Case 2: More operations
    cout << "Test Case 2:" << endl;
    stack->push(3);
    stack->push(4);
    cout << "pop(): " << stack->pop() << endl;   // should return 4
    cout << "top(): " << stack->top() << endl;   // should return 3
    cout << "pop(): " << stack->pop() << endl;   // should return 3
    cout << "pop(): " << stack->pop() << endl;   // should return 1
    cout << "empty(): " << (stack->empty() ? "true" : "false") << endl;  // should return true
    
    delete stack;
    return 0;
} 