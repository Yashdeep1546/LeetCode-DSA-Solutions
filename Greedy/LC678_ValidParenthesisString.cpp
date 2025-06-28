#include <bits/stdc++.h>
using namespace std;

/*
LeetCode #678: Valid Parenthesis String

Problem Description:
Given a string s containing only three types of characters: '(', ')' and '*', 
return true if s is valid.

The following rules define a valid string:
- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "(*)"
Output: true

Example 3:
Input: s = "(*))"
Output: true

Example 4:
Input: s = "((("
Output: false

Constraints:
- 1 <= s.length <= 100
- s[i] is '(', ')' or '*'.
*/

class Solution {
public:



    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            else if(s[i]==')'){
                mini--;
                maxi--;
            }
            else{
                mini--;
                maxi++;
            }
            if(maxi<0) return false;
            if(mini<0) mini=0;
        }
        return mini==0;
    }
};

// For testing
int main() {
    Solution sol;
    
    // Test Case 1
    string s1 = "()";
    cout << "Test Case 1: " << (sol.checkValidString(s1) ? "true" : "false") << endl; // Expected: true
    
    // Test Case 2
    string s2 = "(*)";
    cout << "Test Case 2: " << (sol.checkValidString(s2) ? "true" : "false") << endl; // Expected: true
    
    // Test Case 3
    string s3 = "(*))";
    cout << "Test Case 3: " << (sol.checkValidString(s3) ? "true" : "false") << endl; // Expected: true
    
    // Test Case 4
    string s4 = "(((";
    cout << "Test Case 4: " << (sol.checkValidString(s4) ? "true" : "false") << endl; // Expected: false
    
    return 0;
} 