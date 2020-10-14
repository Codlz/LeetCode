
// @Title: 查找常用字符 (Find Common Characters)
// @Author: 554216885@qq.com
// @Date: 2020-10-14 11:28:32
// @Runtime: 56 ms
// @Memory: 11.7 MB

class Solution {
public:
    vector<string> commonChars(vector<string> A) 
    {
        unordered_map<char, int> a;
        vector<string> ans;
        
        for (char& c : A[0]) {
            a[c]++;
        }
        for (int i = 1;i < A.size();i++) {
            unordered_map<char, int> an;
            for (char& c : A[i]) {
                an[c]++;
            }
            unordered_map<char, int>::iterator it;
            for (it = a.begin();it != a.end();it++) {
                it->second = min(it->second, an[it->first]);
            }
        }
        unordered_map<char, int>::iterator it;
        for (it = a.begin();it != a.end();it++) {
            while (it->second--) {
                string s;
                s.append(1, it->first);
                ans.push_back(s);
            }
        }
        return ans;
    }
};
