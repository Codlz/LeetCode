
// @Title: N 皇后 (N-Queens)
// @Author: 554216885@qq.com
// @Date: 2020-10-04 17:16:50
// @Runtime: 40 ms
// @Memory: 9.2 MB

class Solution {
public:
        inline vector<string> getBoard(const vector<int>& _vec) {
        //获取棋盘字符串数组的函数
        vector<string> result;
        int tot = _vec.size();
        for (int i = 0;i < tot;i++) {
            string str(tot,'.');
            str[_vec[i]] = 'Q';
            result.push_back(str);
        }
        return result;
    }
    inline bool canPutDown(int x, int y,const unordered_set<int>* _set) {
        return _set[0].find(y) == _set[0].end() && _set[1].find(x+y) == _set[1].end() && _set[2].find(x-y) == _set[2].end();
    }
    void dfs(int row, int tot, vector<int>& _vec, unordered_set<int>* _set, vector<vector<string> >& result) {
        //row正在深搜的行, tot为棋盘大小，_vec储存每一行皇后的位置, _set储存已经被占的位置
        if (row == tot) {
            result.push_back(getBoard(_vec));
            return;
        }
        for (int i = 0;i < tot;i++) {
            //对该行的每一列进行尝试
            int x = row, y = i;
            
            if (canPutDown(x, y, _set)) {
                _set[0].insert(y);
                _set[1].insert(x+y);
                _set[2].insert(x-y);
                _vec.push_back(y);
                dfs(row + 1, tot, _vec, _set, result);
                _set[0].erase(y);
                _set[1].erase(x+y);
                _set[2].erase(x-y);
                _vec.pop_back();
            }
        }

        return;
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<int> _vec;
        dfs(0, n, _vec,new unordered_set<int>[3], result);

        return result;
    }

};
