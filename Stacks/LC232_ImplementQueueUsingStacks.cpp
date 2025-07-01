/*
LeetCode 232. Implement Queue using Stacks
https://leetcode.com/problems/implement-queue-using-stacks/

Implement a first in first out (FIFO) queue using only two stacks. 
The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
- void push(int x) Pushes element x to the back of the queue.
- int pop() Removes the element from the front of the queue and returns it.
- int peek() Returns the element at the front of the queue.
- boolean empty() Returns true if the queue is empty, false otherwise.

Example:
Input:
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output:
[null, null, null, 1, 1, false]

Time Complexity: 
- Push: O(1)
- Pop: Amortized O(1)
- Peek: O(1)
- Empty: O(1)
*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x) { s1.push(x); }

    int pop() {

        if (!s2.empty()) {
            int top = s2.top();
            s2.pop();
            return top;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int i = s2.top();
        s2.pop();
        return i;
    }

    int peek() {

        if (!s2.empty()) {
            int top = s2.top();

            return top;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int i = s2.top();
        
        return i;
    }

    bool empty() { return s1.empty() && s2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main() {
    MyQueue* queue = new MyQueue();
    
    // Test Case 1: Basic operations
    cout << "Test Case 1:" << endl;
    queue->push(1);
    queue->push(2);
    cout << "peek(): " << queue->peek() << endl;  // should return 1
    cout << "pop(): " << queue->pop() << endl;    // should return 1
    cout << "empty(): " << (queue->empty() ? "true" : "false") << endl;  // should return false
    cout << endl;
    
    // Test Case 2: More operations
    cout << "Test Case 2:" << endl;
    queue->push(3);
    queue->push(4);
    cout << "pop(): " << queue->pop() << endl;    // should return 2
    cout << "peek(): " << queue->peek() << endl;  // should return 3
    cout << "pop(): " << queue->pop() << endl;    // should return 3
    cout << "pop(): " << queue->pop() << endl;    // should return 4
    cout << "empty(): " << (queue->empty() ? "true" : "false") << endl;  // should return true
    
    delete queue;
    return 0;
} 