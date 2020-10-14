
// @Title: 秋叶收藏集 (秋叶收藏集)
// @Author: 554216885@qq.com
// @Date: 2020-10-12 20:35:28
// @Runtime: 676 ms
// @Memory: 111.5 MB

class Solution {
public:
    int minimumOperations(string leaves) 
    {
        //可以用新的叶子替换leaves中的叶子
        //使用 0 1 2 分别表示 左 中 右 的叶子
        //使用动态规划, dp[i][j]表示i + 1个叶子已经完成符合ryr，且当前叶子处于状态j的时候的最小调整次数
        //无穷大表示不满足ryr要求
        int n = leaves.length();
        vector<vector<int> > dp(n, {0, 0, 0});
        
        //设置边界条件
        dp[0][0] = leaves[0] == 'y' ? 1 : 0;
        dp[0][1] = dp[0][2]  = 0x3f3f3f3f;
        
        int isYellow;
        for (int i = 1;i < n;i++) {
            isYellow = leaves[i] == 'y' ? 1 : 0;
            dp[i][0] = dp[i - 1][0] + isYellow;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (1 - isYellow);
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][2]) + isYellow;
        }
        
        //最后一片叶子的状态必须为2
        return dp[n - 1][2];
    }
};
