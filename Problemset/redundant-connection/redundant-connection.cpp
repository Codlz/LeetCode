
// @Title: 冗余连接 (Redundant Connection)
// @Author: 554216885@qq.com
// @Date: 2020-10-07 20:39:01
// @Runtime: 8 ms
// @Memory: 8.4 MB

class Solution {
public:
    int find_root(int x, int* parent) {
        while (parent[x] != -1) {
            x = parent[x];
        }
        return x;
    }
    int union_set(int x, int y, int* parent) {
        int x_root = find_root(x, parent);
        int y_root = find_root(y, parent);
        if (x_root == y_root)
            return 0;
        parent[x_root] = y_root;
        return 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int q = -1;
        int* parent = new int[n + 1];
        for (int i = 0;i < n + 1;i++) {
            parent[i] = -1;
        }
        for (int i = 0;i < n;i++) {
            int x = edges[i][0], y = edges[i][1];
            if (union_set(x, y, parent) == 0) {
                q = i;
            }
        }
        vector<int> res;
        res.push_back(edges[q][0]);
        res.push_back(edges[q][1]);
        return res;
    }
};
