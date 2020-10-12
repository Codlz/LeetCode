
// @Title: 最小覆盖子串 (Minimum Window Substring)
// @Author: 554216885@qq.com
// @Date: 2020-10-10 23:34:54
// @Runtime: 820 ms
// @Memory: 7.7 MB

class Solution {
public:
    unordered_map<char, int> map_s, map_t;
    string minWindow(string s, string t) {
        string ans;
        for (char c : t) {
            map_t[c]++;
        }
        int l = 0, r = -1;
        //滑动窗口的左右指针
        int ansl = -1, len = INT32_MAX;
        //ansl为答案的起始位, len为答案的长度
        while (r < int(s.size())) {
            r++;
            if (map_t.find(s[r]) != map_t.end()) {
                map_s[s[r]]++;
            }
            while (is_valid()) {
                if (r - l + 1 < len) {
                    //当前获得的长度最小
                    ansl = l;
                    len = r -l + 1;
                }
                if (map_t.find(s[l]) != map_t.end()){
                    map_s[s[l]]--;
                }
                l++;
            }
        }
        if (ansl == -1) 
            return "";
        else {
            return s.substr(ansl, len);
        }
    }
    bool is_valid() {
        //判断去掉当前s[begin]后是否满足条件   
        unordered_map<char, int>::iterator it;
        for (it = map_t.begin();it != map_t.end();it++) {
            char c = it->first; int v = it->second;
            if (map_s[c] < v)
                return false;
        }
        return true;
    }
};
