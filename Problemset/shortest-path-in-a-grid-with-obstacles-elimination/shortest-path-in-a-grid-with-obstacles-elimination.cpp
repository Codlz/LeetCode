
// @Title: 网格中的最短路径 (Shortest Path in a Grid with Obstacles Elimination)
// @Author: 554216885@qq.com
// @Date: 2020-10-18 14:19:18
// @Runtime: 104 ms
// @Memory: 18.4 MB

class Solution {
public:
    int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int shortestPath(vector<vector<int>>& grid, int k) 
    {
        int m = grid.size(), n = grid[0].size();
        int vis[m][n];
        memset(vis, -1, sizeof vis);
        //vis记录到达该点的剩余可消除障碍数最多的状态
        //最先到达一个点的状态，不一定是最优状态

        queue<vector<int> > q;
        q.push({0, 0, 0, 0});
        vis[0][0] = k;
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            int x = v[0], y = v[1], c = v[2], d = v[3];
            //使用vector储存x y 已经消除的障碍 距离
            if (x == (m - 1) and y == (n - 1))
                return d;
            for (int i = 0; i < 4; i++) {
                int nx = x + move[i][0], ny = y + move[i][1];
                if (nx >= 0 and nx < m and ny >= 0 and ny < n) {
                    int nc = c + grid[nx][ny];
                    if (nc > k)
                        continue;
                    if (vis[nx][ny] != - 1 and vis[nx][ny] >= k -nc)
                        continue;
                    else {
                        vis[nx][ny] = k - nc;
                        q.push({nx, ny, nc, d + 1});
                    }
                }
            }
        }
        return -1;
    }
};
