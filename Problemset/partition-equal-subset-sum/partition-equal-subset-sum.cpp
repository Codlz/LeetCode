
// @Title: 分割等和子集 (Partition Equal Subset Sum)
// @Author: 554216885@qq.com
// @Date: 2020-10-11 22:05:29
// @Runtime: 136 ms
// @Memory: 26 MB

class Solution {
public:
    bool canPartition(vector<int> nums) 
    {   
        int n = nums.size();
        if (n < 2)
            return false;

        int sum = 0; int maxnum = -0x3f3f3f;
        for (int& i : nums){
            maxnum = maxnum > i ? maxnum : i;
            sum += i;
        }
        int target = sum / 2;
        if (sum % 2 != 0 || maxnum > target)
            return false;
        
        //使用动态规划，dp[i][j]表示选取前i个数是否能有满足和为j的情况
        //动态规划的二维数组，把需要满足的条件放在列，把可能的选项放在行
        bool** dp = new bool*[n];
        for (int i = 0;i < n;i++) {
            dp[i] = new bool[target + 1];
            memset(dp[i], 0, sizeof(bool)*(target + 1));
        }
        //设置边界条件，对于和为0的条件，任何情况都可以满足
        //第一个数满足dp[0][nums[0]]
        for (int i = 0;i < n;i++) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1;i < n;i++) {
            for (int j = 1;j < target + 1;j++) {
                if (nums[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else {
                    //不加nums[i]和加入nums[i]
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[n - 1][target];
    }
};
