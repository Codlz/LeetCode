
// @Title: 地图分析 (As Far from Land as Possible)
// @Author: 554216885@qq.com
// @Date: 2020-10-19 23:27:09
// @Runtime: 468 ms
// @Memory: 29.4 MB

class Solution {
public:
    typedef pair<int, int*> p;
    int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int** dis;
        dis = new int*[m];
        for (int i = 0; i < m; i++) {
            dis[i] = new int[n];
            memset(dis[i], 0x3f, sizeof(int) * n);
        }
        int _max = -1;
        dijstra(m, n, dis, grid, _max);
        
        if (_max == 0 || _max == -1) {
            //只有陆地和只有海洋的情况
            return -1;
        }
        else
        {
            return _max;
        }
        
    }
    void dijstra(int m, int n, int** dis, vector<vector<int> >& grid, int& _max) {
        bool** vis;
        vis = new bool*[m];
        for (int i = 0; i < m; i++) {
            vis[i] = new bool[n];
            memset(vis[i], false, sizeof(bool) * n);
        }
        priority_queue<p, vector<p>, greater<p> > q;
        //设置超级源点，和所有1的陆地距离都为0
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dis[i][j] = 0;
                    int* pos = new int[2];
                    pos[0] = i; pos[1] = j;
                    q.push({0, pos});
                }
            }
        }
        while (!q.empty()) {
            p cur = q.top();
            q.pop();
            if (vis[cur.second[0]][cur.second[1]])
                continue;
            for (int i = 0; i < 4; i++) {
                int nx = cur.second[0] + move[i][0];
                int ny = cur.second[1] + move[i][1];
                if (nx < 0 or nx >= m or ny < 0 or ny >= n or vis[nx][ny])
                    continue;
                if (dis[nx][ny] > dis[cur.second[0]][cur.second[1]] + 1) {
                    dis[nx][ny] =  dis[cur.second[0]][cur.second[1]] + 1;
                    int* pos = new int[2];
                    pos[0] = nx; pos[1] = ny;
                    q.push({dis[nx][ny], pos});
                }
            }
            vis[cur.second[0]][cur.second[1]] = true;
            if (cur.first > _max) {
                _max = cur.first;
            }
        }
    }
};
