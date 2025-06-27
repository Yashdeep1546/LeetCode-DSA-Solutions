#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i][1]>intervals[i+1][0]){
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<vector<int>> intervals1 = {{0,30},{5,10},{15,20}};
    vector<vector<int>> intervals2 = {{7,10},{2,4}};
    
    cout << "Test Case 1: " << (sol.canAttendMeetings(intervals1) ? "true" : "false") << endl;
    cout << "Test Case 2: " << (sol.canAttendMeetings(intervals2) ? "true" : "false") << endl;
    
    return 0;
}