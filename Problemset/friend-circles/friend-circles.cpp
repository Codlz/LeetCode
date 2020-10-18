
// @Title: 朋友圈 (Friend Circles)
// @Author: 554216885@qq.com
// @Date: 2020-10-18 15:48:10
// @Runtime: 52 ms
// @Memory: 13.8 MB

class Solution {
public:
    int find_root(int x, int root[]) {
        if (root[x] == x)
            return x;
        return find_root(root[x], root);
    }
    int _union(int a, int b, int root[], int depth[]) {
        int root_a = find_root(a, root);
        int root_b = find_root(b, root);
        if (root_a == root_b)
            return 0;
        if (depth[root_a] > depth[root_b])
            root[root_b] = root_a;
        else if (depth[root_a] < depth[root_b])
            root[root_a] = root_b;
        else {
            root[root_b] = root_a;
            ++depth[root_a];
        }
        return 1;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        if (N == 1)
            return 1;
        int* root = new int[N];
        int* depth = new int[N];
        for (int i = 0; i < N; i++){
            depth[i] = 1;
            root[i] = i;
        }
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (M[i][j])
                    _union(i, j, root, depth);
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (root[i] == i)
                ++ans;
                //节点的父节点就是自身，代表这就是个根节点
        }
        return ans;
    }
};
