
// @Title: 字母异位词分组 (Group Anagrams)
// @Author: 554216885@qq.com
// @Date: 2020-10-16 15:27:56
// @Runtime: 76 ms
// @Memory: 19.2 MB

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> strs) {
        vector<vector<string> > res;
        int* alpha;
        alpha = new int[26];
        memset(alpha, 0, sizeof(int)*26);
        unordered_map<string, vector<int> > _map;
        for (int i = 0;i < strs.size();i++) {
            string s;
            for (char& c : strs[i]) {
                alpha[c - 'a']++;
            }
            for (int j = 0;j < 26;j++) {
                s.append(alpha[j], j + 'a');
                alpha[j] = 0;
            }
            _map[s].push_back(i);
        }
        res.resize(_map.size(), {});
        int n = 0;
        for (auto it = _map.begin();it != _map.end();it++) {
            for (int i : it->second) {
                res[n].push_back(strs[i]);
            }
            n++;
        }

        return res;
    }
};
