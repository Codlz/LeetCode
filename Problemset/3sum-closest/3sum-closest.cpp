
// @Title: 最接近的三数之和 (3Sum Closest)
// @Author: 554216885@qq.com
// @Date: 2020-10-13 09:41:26
// @Runtime: 16 ms
// @Memory: 9.9 MB

class Solution {
public:
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int i, j, k;
        int ans = 0x3f3f3f;
        int sum;

        for (i = 0;i <  nums.size() - 2 ;i++) {
            j = i + 1; k = nums.size() - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                ans = abs(ans - target) < abs(sum - target) ? ans : sum;
                if (sum < target)
                    j++;
                else if (sum > target)
                   k--;
                else 
                    return ans;
            }
        }
        return ans;
    }
};
