// LeetCode 96. Unique Binary Search Trees
// Medium
// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.
//
// Example:
// Input: n = 3
// Output: 5
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    cout << "Test 1: " << sol.numTrees(3) << endl; // 5
    cout << "Test 2: " << sol.numTrees(1) << endl; // 1
    cout << "Test 3: " << sol.numTrees(5) << endl; // 42
    return 0;
} 