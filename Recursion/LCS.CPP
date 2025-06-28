#include <bits/stdc++.h>
using namespace std;

int lcs(string s ,string t){
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp (n+1,vector<int> (m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

return dp[n][m];
}
int main() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << "Length of LCS: " << lcs(s1, s2) << endl;
    return 0;
}
