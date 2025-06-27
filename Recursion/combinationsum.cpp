#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sprint(vector<int>& arr, vector<int>& ans, int target, int ind,int n,int sum, vector<vector<int>> &result){
        if(ind>=n || sum>target){
            return ;
        }
        if(sum==target){
            result.push_back(ans);
            return;
        }
        ans.push_back(arr[ind]);
        sum+=arr[ind];
        sprint(arr,ans,target,ind+1,n,sum,result);
        sum-=arr[ind];
        ans.pop_back();
        while(ind + 1<n && arr[ind]==arr[ind+1]){
            ind++;
        }
        sprint(arr,ans,target,ind+1,n,sum,result);
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> result;
        vector<int> ans;
        sprint(arr,ans,target,0,n,0,result);
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    vector<vector<int>> result1 = sol.combinationSum2(candidates1, target1);
    
    cout << "Test Case 1: Target = " << target1 << endl;
    for(auto& combo : result1) {
        cout << "[ ";
        for(int num : combo) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    vector<vector<int>> result2 = sol.combinationSum2(candidates2, target2);
    
    cout << "\nTest Case 2: Target = " << target2 << endl;
    for(auto& combo : result2) {
        cout << "[ ";
        for(int num : combo) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}