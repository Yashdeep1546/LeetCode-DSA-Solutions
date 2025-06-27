#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){

    int n = nums.size();
    set<vector<int>> seen;  // To avoid duplicates
    vector<vector<int>> res;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    if (seen.find(triplet) == seen.end()) {
                        seen.insert(triplet);
                        res.push_back(triplet);
                    }
                }
            }
        }
    }
    return res;
}
}
