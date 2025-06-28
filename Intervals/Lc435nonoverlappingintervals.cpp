#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1]<b[1];
        });
        int count=0,end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=end){
                end=intervals[i][1];
            }
            else{
                count++;
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