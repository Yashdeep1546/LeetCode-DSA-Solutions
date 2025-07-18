class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;
                int target = -nums[i] - nums[j];
                int sum = nums[left] + nums[right];
                while (left < right) {
                    if ( sum== target) {
                        res.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while (left < right && nums[right] ==nums[right - 1]) {
                            right--;
                        }
                    }
                    else if( sum < target) left++;
                    else right--;
                }
            }
        }

        return res;
    }
};
