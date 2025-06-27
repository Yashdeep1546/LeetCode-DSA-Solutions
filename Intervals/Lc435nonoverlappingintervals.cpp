#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>intervals[i+1][0]){
                count++;j
            }
        }
        return count;
        
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<vector<int>> intervals1 = {{1,2},{2,3},{3,4},{1,3}};
    vector<vector<int>> intervals2 = {{1,2},{1,2},{1,2}};
    vector<vector<int>> intervals3 = {{1,2},{2,3}};
    
    cout << "Test Case 1: " << sol.eraseOverlapIntervals(intervals1) << endl;  // Should output: 1
    cout << "Test Case 2: " << sol.eraseOverlapIntervals(intervals2) << endl;  // Should output: 2
    cout << "Test Case 3: " << sol.eraseOverlapIntervals(intervals3) << endl;  // Should output: 0
    
    return 0;
} 