#include <bits/stdc++.h>
using namespace std;

int func( vector<int> & nums){
int res=0;
int left=0;
int right=nums.size()-1;
while(left<right){
    int cont=0;
    int height=min(nums[left],nums[right]);
    cont= height*(right-left);
    res= res<cont? cont:res;
}

return res;
}
