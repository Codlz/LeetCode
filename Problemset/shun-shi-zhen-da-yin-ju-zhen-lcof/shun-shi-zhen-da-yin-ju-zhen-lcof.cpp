
// @Title: 顺时针打印矩阵 (顺时针打印矩阵  LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-05 18:44:31
// @Runtime: 20 ms
// @Memory: 10 MB

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() < 1)
            return {};
        vector<int> res;
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rows = matrix.size(), cols = matrix[0].size();
        int count = 0, len = rows * cols;
        int dir = 0;
        int x = 0, y = 0;
        while (count < len) {
            res.push_back(matrix[x][y]);
            matrix[x][y] = INT_MIN;
            count++;
            int next_x = x + move[dir][0], next_y = y + move[dir][1];
            if (next_x >= rows || next_x < 0 || next_y >= cols || next_y < 0 || matrix[next_x][next_y] == INT_MIN) {
                dir = (dir + 1) %4;
            }
            x = x + move[dir][0]; y +=  move[dir][1];
        }

        return res;
    }
};
