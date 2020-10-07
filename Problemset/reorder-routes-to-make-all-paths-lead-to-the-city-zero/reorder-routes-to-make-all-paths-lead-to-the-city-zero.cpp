
// @Title: 重新规划路线 (Reorder Routes to Make All Paths Lead to the City Zero)
// @Author: 554216885@qq.com
// @Date: 2020-10-06 18:57:13
// @Runtime: 648 ms
// @Memory: 77.8 MB

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int> > list;
        //储存每个节点所连的边
        vector<int> flag(n, 0);
        //存储哪些点已经访问过了
        int res = 0;
        list.resize(n);
        for (int i = 0;i < connections.size();i++) {
            list[connections[i][0]].push_back(i);
            list[connections[i][1]].push_back(i);
        }
        //广度优先搜索
        queue<int> _q;
        _q.push(0); int cur;
        while (!_q.empty()) {
            cur = _q.front();
            _q.pop();
            for (auto& e : list[cur]) {
                int a = connections[e][0], b = connections[e][1];
                //a为边的起始点，b为边的终点
                if (flag[a] || flag[b])
                    continue;
                if (a == cur) {
                    res++;
                    _q.push(b);
                }
                else 
                    _q.push(a);
            }
            flag[cur] = 1;
        }
        return res;
    }
};
