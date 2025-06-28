#include <bits/stdc++.h>
using namespace std;


// using memoization
int knapsack( vector<int>&val, vector<int>&wt, int i ,int w, vector<vector<int>> &dp){

if(i==0){
    if(w>=wt[0]) return val[0];
   else return 0;
}
if(dp[i][w]!=-1) return dp[i][w];

int nottake= knapsack(val,wt,i-1,w,dp);
int take=INT_MIN;
if(w>=wt[i]) take = val[i]+knapsack(val,wt,i-1,w-wt[i],dp);

return dp[i][w]=max(take,nottake);


}



// using tabulation
/*int knapsack( vector<int>val, vector<int>wt, int n ,int Maxweight ){

vector<vector<int>>dp (n,vector<int> (Maxweight+1,0));

for(int i=wt[0]; i<=Maxweight ;i++) dp[0][i]=val[0];

for(int i=1;i<n;i++){
    for(int w=0;w<=Maxweight;w++){

      int nottake = 0+dp[i-1][w];
      int take=INT_MIN;
      if(w>=wt[i]){
        take = val[i]+dp[i-1][w-wt[i]];
      }
      dp[i][w]=max(take,nottake);
    }
}
return dp[n-1][Maxweight] ;
}
*/
int main(){
int n=4;
int MW=5;

vector<int> wt = {2, 3, 4, 5};
vector<int> val = {3, 4, 5, 6};

vector<vector<int>> dp(n, vector<int>(MW + 1, -1));

cout<<knapsack(val,wt,n-1,MW,dp);

//cout<<knapsack(val,wt,n,MW); //for tabulation
return 0;
}
