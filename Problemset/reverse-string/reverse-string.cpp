
// @Title: 反转字符串 (Reverse String)
// @Author: 554216885@qq.com
// @Date: 2020-10-08 08:41:47
// @Runtime: 56 ms
// @Memory: 23 MB

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int i = 0, j = s.size() - 1;
        while (i < j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;j--;
        }
    }
};
