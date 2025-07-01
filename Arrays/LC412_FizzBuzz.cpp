/*
LeetCode 412. Fizz Buzz
https://leetcode.com/problems/fizz-buzz/

Given an integer n, return a string array answer (1-indexed) where:
- answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
- answer[i] == "Fizz" if i is divisible by 3.
- answer[i] == "Buzz" if i is divisible by 5.
- answer[i] == i (as a string) if none of the above conditions are true.

Example 1:
Input: n = 3
Output: ["1","2","Fizz"]

Example 2:
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Example 3:
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

Time Complexity: O(n)
Space Complexity: O(1) (not counting output space)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int i) {
        
        vector<string> ans;
        for(int n=1;n<=i;n++){
       if(n%3==0&&n%5==0) ans.push_back("FizzBuzz");
       else if(n%3==0) ans.push_back("Fizz");
       else if(n%5==0) ans.push_back("Buzz");
       else{ 
        
        ans.push_back(to_string(n));
       
       }
        }
        return ans;
    }
};

// Function to print string vector
void printStringVector(const vector<string>& vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        cout << "\"" << vec[i] << "\"";
        if (i < vec.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    cout << "Test Case 1:" << endl;
    cout << "Input: n = 3" << endl;
    cout << "Output: ";
    printStringVector(solution.fizzBuzz(3));
    cout << endl;
    
    // Test Case 2
    cout << "Test Case 2:" << endl;
    cout << "Input: n = 5" << endl;
    cout << "Output: ";
    printStringVector(solution.fizzBuzz(5));
    cout << endl;
    
    // Test Case 3
    cout << "Test Case 3:" << endl;
    cout << "Input: n = 15" << endl;
    cout << "Output: ";
    printStringVector(solution.fizzBuzz(15));
    
    return 0;
} 