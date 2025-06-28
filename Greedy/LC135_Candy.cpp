#include <bits/stdc++.h>
using namespace std;

/*
LeetCode #135: Candy

Problem Description:
There are n children standing in a line. Each child is assigned a rating value given in an integer array ratings.
You are giving candies to these children subjected to the following requirements:
- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

Constraints:
- n == ratings.length
- 1 <= n <= 2 * 10^4
- 0 <= ratings[i] <= 2 * 10^4
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        // Initialize candies array with 1 for each child (rule 1)
        vector<int> candies(n, 1);
        
        // First pass: left to right
        // Ensure children with higher ratings get more candies than their left neighbors
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        // Second pass: right to left
        // Ensure children with higher ratings get more candies than their right neighbors
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                // Take the maximum to ensure we don't violate the left neighbor rule
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        
        // Sum up all candies
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

// For testing
int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> ratings1 = {1, 0, 2};
    cout << "Test Case 1: " << sol.candy(ratings1) << endl; // Expected: 5
    
    // Test Case 2
    vector<int> ratings2 = {1, 2, 2};
    cout << "Test Case 2: " << sol.candy(ratings2) << endl; // Expected: 4
    
    // Test Case 3
    vector<int> ratings3 = {1, 3, 2, 2, 1};
    cout << "Test Case 3: " << sol.candy(ratings3) << endl; // Expected: 7
    
    return 0;
} 