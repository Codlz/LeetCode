
// @Title: N皇后 II (N-Queens II)
// @Author: 554216885@qq.com
// @Date: 2020-10-17 22:29:24
// @Runtime: 40 ms
// @Memory: 7.7 MB

class Solution {
public:
    typedef unordered_set<int> unset;
    int cnt;
    int totalNQueens(int n) 
    {   
        cnt = 0;
        unset s1, s2, s3;
        dfs(0, n, s1, s2, s3);
        cout << cnt;
        return cnt;
    }
    bool canPut(int x, int y ,unset& s1, unset& s2, unset& s3) 
    {
        return (s1.find(x + y) == s1.end() and s3.find(y) == s3.end() and s2.find(x - y) == s2.end());
    }
    void dfs(int row, int n, unset& s1, unset& s2, unset& s3)
    {
        if (row == n){
            cnt++;
            return;
        }
        for (int i = 0;i < n;i++) {
            int x = row, y = i;
            if (canPut(x, y, s1, s2, s3)) {
                s1.insert(x + y);
                s2.insert(x - y);
                s3.insert(y);
                dfs(row + 1, n, s1, s2, s3);
                s1.erase(x + y);
                s2.erase(x - y);
                s3.erase(y);
            }
        }
    }
};
