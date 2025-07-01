/*
LeetCode 739. Daily Temperatures
https://leetcode.com/problems/daily-temperatures/

Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait 
after the ith day to get a warmer temperature. If there is no future day for which 
this is possible, keep answer[i] == 0 instead.

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                res[idx] = i - idx;
            }
            st.push(i);
        }

        return res;
    }
};

// Function to print vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> temperatures1 = {73,74,75,71,69,72,76,73};
    cout << "Test Case 1:" << endl;
    cout << "Input: ";
    printVector(temperatures1);
    cout << "Output: ";
    printVector(solution.dailyTemperatures(temperatures1));
    cout << endl;
    
    // Test Case 2
    vector<int> temperatures2 = {30,40,50,60};
    cout << "Test Case 2:" << endl;
    cout << "Input: ";
    printVector(temperatures2);
    cout << "Output: ";
    printVector(solution.dailyTemperatures(temperatures2));
    cout << endl;
    
    // Test Case 3
    vector<int> temperatures3 = {30,60,90};
    cout << "Test Case 3:" << endl;
    cout << "Input: ";
    printVector(temperatures3);
    cout << "Output: ";
    printVector(solution.dailyTemperatures(temperatures3));
    
    return 0;
} 