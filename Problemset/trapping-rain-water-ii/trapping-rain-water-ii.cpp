
// @Title: 接雨水 II (Trapping Rain Water II)
// @Author: 554216885@qq.com
// @Date: 2020-10-14 15:01:39
// @Runtime: 88 ms
// @Memory: 8.3 MB

class Solution {
    //假设水是从四周像中间流动的，先从周围较低的地方开始流。
public:
    struct Block {
        int x, y, h;
        Block(int x, int y, int h) : x(x), y(y), h(h) {}
    };
    struct  cmp
    {
        bool operator()(Block a, Block b) 
        {
            //重写仿函数，返回true的时候，堆中a排在b后面
            return a.h  >= b.h;
        }
    };
    int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(),  n = heightMap[0].size();

        if (m < 3 || n < 3)
            return 0;

        priority_queue<Block, vector<Block>, cmp> pq;
        for (int i = 0;i < m;i++) {
            pq.push(Block(i, 0, heightMap[i][0]));
            heightMap[i][0] = -1;
        }
        for (int i = 1;i < n;i++) {
            pq.push(Block(m - 1, i, heightMap[m - 1][i]));
            heightMap[m - 1][i] = -1;
        }
        for (int i = 0;i < m - 1;i++) {
            pq.push(Block(i, n - 1, heightMap[i][n - 1]));
            heightMap[i][n - 1] = -1;
        }
        for (int i = 1;i < n - 1;i++) {
            pq.push(Block(0, i, heightMap[0][i]));
            heightMap[0][i] = -1;
        }
        //将四周的块先加入优先队列中，由四周向中间宽搜

        int ans = 0;
        while (!pq.empty()) {
            int x = pq.top().x, y = pq.top().y, h = pq.top().h;
            pq.pop();
            for (int i = 0;i < 4;i++) {
                int nx = x + move[i][0], ny = y + move[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int nh = heightMap[nx][ny];
                    heightMap[nx][ny] = -1;
                    if (nh != -1 && nh <= h) {
                        ans += h - nh;
                        pq.push(Block(nx, ny, h));
                    }
                    else if (nh != -1) {
                        pq.push(Block(nx, ny, nh));
                    }
                }
            }
        }
        return ans;
    }
};
