
// @Title: 01 矩阵 (01 Matrix)
// @Author: 554216885@qq.com
// @Date: 2020-10-13 20:26:35
// @Runtime: 204 ms
// @Memory: 34.3 MB

class Solution {
public:
    int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size();
        queue<int*> _q;

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (matrix[i][j] == 0) {
                    //先将所有0入队，默认从距所有0距离为0的超级源点出发
                    int* p = new int[2];
                    p[0] = i; p[1] = j;
                    _q.push(p);
                }
                else 
                    matrix[i][j] = -1;
                    //将所有1标记为为未访问过
            }
        }
        //因为使用BFS,所有的1都是先被离他最近的0到达
        while (!_q.empty()) {
            int* p = _q.front();
            _q.pop();
            int nx, ny;
            for (int i = 0;i < 4;i++) {
                nx = p[0] + step[i][0];
                ny = p[1] + step[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] < 0) {
                    matrix[nx][ny] = matrix[p[0]][p[1]] + 1; //等于上一步的距离加1
                    int* np = new int[2];
                    np[0] = nx; np[1] = ny;
                    _q.push(np);
                }
            }
            delete []p;
        }
        return matrix;
    }
};
