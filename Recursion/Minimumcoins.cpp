#include <bits/stdc++.h>
using namespace std;

//MEMOIZATION
// int minc(vector<int> &d, int target , int i,vector<vector<int>> &dp){

//     if(target==0) return 0;
//     if(i<0) return 1e9;  //Not using INTMAX because of overflow may occur
//     if(dp[i][target]!=-1) return dp[i][target];
//     int nottake= 0+minc(d,target,i-1,dp);
//     int take= 1e9;  //Not using INTMAX because of overflow may occur
//     if(target>=d[i] ) take= 1+ minc(d,target-d[i],i,dp);

//     return dp[i][target]=min(nottake,take);

// }

// int main() {
//     vector<int> d ={3,5,7};
//     int target = 1000000;
//     vector<vector<int>>dp (d.size(),vector <int> (target+1,-1));
//     cout<< minc(d,target,d.size()-1,dp);
//     return 0;
//     }


//TABULATION


int minc(vector<int> &d, int target , int n){
vector<vector<int>> dp(d.size(),vector<int> (target+1,1e9));
for(int i = 0; i <= target; i++) {
    if(i % d[0] == 0) dp[0][i] = i / d[0];
}

 for(int i=1;i<d.size();i++){
        for(int t=0;t<=target;t++){
                int nottake = dp[i-1][t];
                int take=1e9;
                if(t>=d[i] ) take= 1+ dp[i][t-d[i]];
                dp[i][t]= min (take,nottake);
        }

    }

return dp[d.size()-1][target];
}
int main() {
    vector<int> coins = {3, 5, 7};
    int target = 9;
    int ans = minc(coins, target, coins.size());
    if (ans == -1) cout << "Not possible\n";
    else cout << "Minimum coins: " << ans << "\n";
    return 0;
}
