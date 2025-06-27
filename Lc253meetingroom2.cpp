#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
       
       int count=0,maxi=0;
       vector<int>st;
       vector<int>end;
       for(int i=0;i<intervals.size();i++){
        st.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
       }
       sort(st.begin(),st.end());
       sort(end.begin(),end.end());
       int i=0,j=0;

       while(i<st.size() && j<end.size()){
        if(st[i]<end[j]){
            count++;
            i++;
            maxi=max(maxi,count);
        }
        else if(st[i]>=end[j]){
            count--;
            j++;
        
        maxi=max(maxi,count);
        }
       }
       return maxi;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<vector<int>> intervals1 = {{0,30},{5,10},{15,20}};
    vector<vector<int>> intervals2 = {{7,10},{2,4}};
    
    cout << "Test Case 1: " << sol.minMeetingRooms(intervals1) << endl;  // Should output: 2
    cout << "Test Case 2: " << sol.minMeetingRooms(intervals2) << endl;  // Should output: 1
    
    return 0;
} 