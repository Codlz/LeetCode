
// @Title: 礼物的最大价值 (礼物的最大价值 LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-11 20:52:57
// @Runtime: 28 ms
// @Memory: 8.9 MB

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1;i < n;i++) {
            grid[0][i] += grid[0][i - 1]; 
        }
        for (int i = 1;i < m;i++) {
            grid[i][0] += grid[i - 1][0];
        }
        //使用动态规划，因为第一行只能从它的左边到达，所以最大累计值可以直接计算。第一列只能从它的上面到达
        for (int i = 1;i < m;i++) {
            for (int j = 1;j < n;j++) {
                grid[i][j] += grid[i - 1][j] > grid[i][j - 1] ? grid[i - 1][j] : grid[i][j - 1];
            }
        }
        return grid[m - 1][n - 1];
    }
};
