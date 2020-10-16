
// @Title: 火柴拼正方形 (Matchsticks to Square)
// @Author: 554216885@qq.com
// @Date: 2020-10-15 11:45:47
// @Runtime: 104 ms
// @Memory: 9.7 MB

class Solution {
public:
    inline static bool cmp(int a, int b) {
        return a > b;
    }
    bool makesquare(vector<int> nums) {
        int sum = 0; int _max = 0; n = nums.size();
        for (int& a : nums) {
            sum += a;
            _max = max(_max, a);
        }
        target = sum / 4;
        if (sum % 4 != 0 || _max > target || n < 4)
            return false;
        //元素由大到小排序，可以更早的剪枝
        sort(nums.begin(), nums.end(), cmp);
        len[0] = len[1] = len[2] = len[3] = 0;
        return dfs(0, nums);
    }

    bool dfs(int idx, vector<int>& nums) {
        if (idx == n) {
            return (len[0] == len[1] && len[1] == len[2] && len[2] == len[3]);
        }
        for (int i = 0;i < 4;i++) {
            //利用深搜回溯
            len[i] += nums[idx];
            if (len[i] <= target) 
                if (dfs(idx + 1, nums))
                    return true;
            len[i] -= nums[idx];
        }
        return false;
    }

    int n; 
    int len[4]; 
    int target;
};
