
// @Title: 树中距离之和 (Sum of Distances in Tree)
// @Author: 554216885@qq.com
// @Date: 2020-10-06 16:37:46
// @Runtime: 148 ms
// @Memory: 26.4 MB

class Solution {
public:
    vector<vector<int> > vers;
    //每个点的相邻点
    vector<int> siz;
    //每个点的以它为根的子树大小
    vector<int> root_dis;
    //存储根节点到其他节点的距离之和
    vector<int> res;

    void dfs_size_dis(int pre, int cur) {
        //一遍深搜，求出了 每个节点的子树大小以及子树到root节点距离的和                                                          {
        siz[cur] = 1;
        //每个节点子树大小至少为1

        if (pre != cur) {
            root_dis[cur] = root_dis[pre] + 1;
        }

        int dis_sum = 0;
        //当前节点为根的树的所有节点到root节点距离的和      
        for (auto& v : vers[cur]) {
            if (v != pre) {
                //如果v不是当前节点的前驱
                dfs_size_dis(cur, v);
                siz[cur] +=  siz[v];
                dis_sum += root_dis[v];
            }
        }
        root_dis[cur] += dis_sum;
    }
    void dfs_res(int pre,int cur,int tot) {
        if (cur != 0) {
            //每个节点的到其他节点的距离可以由它的父节点得出
            res[cur] = res[pre] + (tot - siz[cur]) - siz[cur];
        }
        for (auto v : vers[cur]) {
            if (v != pre) {
                dfs_res(cur, v, tot);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        siz.resize(N, 0);
        vers.resize(N);
        root_dis.resize(N,0);
        res.resize(N, 0);
        for (auto& e : edges) {
            vers[e[0]].push_back(e[1]);
            vers[e[1]].push_back(e[0]);
            //存储每个点的与它相邻的点
        }
        dfs_size_dis(0, 0);
        res[0] = root_dis[0];
        dfs_res(0, 0, N);
        return res;
    }
    
};
