
// @Title: 实现 strStr() (Implement strStr())
// @Author: 554216885@qq.com
// @Date: 2020-10-20 16:11:14
// @Runtime: 4 ms
// @Memory: 7.2 MB

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int len1 = haystack.length(), len2 = needle.length();
        if (len1 < len2)
            return -1;
        if (len2 == 0)
            return 0;
        int* _next = new int[len2 + 1];
        get_next(len2, needle, _next);
        int ans = kmp(len1, len2, haystack, needle, _next);

        return ans;
    }
    void get_next(int n, string& p, int _next[])
    {
        int i, j;
        i = 0;
        _next[0] = j = -1;
        while (i < n) {
            if (j == - 1 || p[i] == p[j]) {
                i++; j++;
                _next[i] = j;
            }
            else {
                j = _next[j];
            }
        }
    }
    int kmp(int len1, int len2, string& t, string& p, int _next[])
    {
        int i = 0, j =0;
        while (i < len1) {
            if (j == -1 || t[i] == p[j]) {
                i++; j++;
            }
            else {
                j = _next[j];
            }
            if (j == len2) {
                return i - len2;
            }
        }
        return -1;
    }
};
