
// @Title: 划分字母区间 (Partition Labels)
// @Author: 554216885@qq.com
// @Date: 2020-10-22 09:18:21
// @Runtime: 0 ms
// @Memory: 6.8 MB

class Solution {
public:
    vector<int> partitionLabels(string S) 
    {
        int _map[26];
        vector<int> res;
        for (int i = 0; i < S.length(); ++i) {
            _map[S[i] - 'a'] = i;
            //记录每个字符最后一次出现的位置
        }
        int i = 0, j;
        while (i < S.length()) {
            int maxp = _map[S[i] - 'a'];
            j = i + 1;
            while (j < maxp) {
                maxp = maxp > _map[S[j] - 'a'] ? maxp : _map[S[j] - 'a'];
                ++j;
            }
            res.push_back(maxp - i + 1);
            i = maxp + 1;
        }
        return res;
    }
};
