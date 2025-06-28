#include <bits/stdc++.h>
using namespace std;

/*
LeetCode #1353: Maximum Number of Events That Can Be Attended

Problem Description:
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
You can attend an event i at any day d where startDayi <= d <= endDayi. You can only attend one event at any time d.
Return the maximum number of events you can attend.

Example 1:
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as follows:
- Attend the first event on day 1.
- Attend the second event on day 2.
- Attend the third event on day 3.

Example 2:
Input: events = [[1,2],[2,3],[3,4],[1,2]]
Output: 4
Explanation: You can attend all the four events.
One way to attend them all is as follows:
- Attend the first event on day 1.
- Attend the second event on day 2.
- Attend the third event on day 3.
- Attend the fourth event on day 1.

Example 3:
Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4
Explanation: You can attend a maximum of 4 events.

Constraints:
- 1 <= events.length <= 10^5
- events[i].length == 2
- 1 <= startDayi <= endDayi <= 10^5
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Your solution here
        sort(events.begin(),events.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1]<b[1];
        });
        int attended=0;
        int days=0;
        int i=0; 
        while(i<events.size()){
            if(events[i][0]<=days&&days<=events[i][1]){
                attended++;
                days--;
                i--;
            }
            else if(events[i][0]>days){
                days--;
            }
            else{
                i--;
            }
        }
        return attended; // placeholder return
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<vector<int>> events1 = {{1,2},{2,3},{3,4}};
    cout << "Test Case 1: " << solution.maxEvents(events1) << endl; // Expected: 3
    
    // Test Case 2
    vector<vector<int>> events2 = {{1,2},{2,3},{3,4},{1,2}};
    cout << "Test Case 2: " << solution.maxEvents(events2) << endl; // Expected: 4
    
    // Test Case 3
    vector<vector<int>> events3 = {{1,4},{4,4},{2,2},{3,4},{1,1}};
    cout << "Test Case 3: " << solution.maxEvents(events3) << endl; // Expected: 4
    
    return 0;
} 