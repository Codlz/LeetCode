
// @Title: 比较含退格的字符串 (Backspace String Compare)
// @Author: 554216885@qq.com
// @Date: 2020-10-19 10:42:14
// @Runtime: 4 ms
// @Memory: 6.4 MB

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        //从尾部开始遍历
        int p1 = S.length() - 1, p2 = T.length() - 1;
        int cnt1 = 0, cnt2 = 0;
        while (true) {
            while (p1 >= 0 and (cnt1 or S[p1] == '#')) {
                if (S[p1] == '#') {
                    ++cnt1;
                    --p1;
                }
                else if (cnt1) {
                    --p1;
                    --cnt1;
                }
            }
            while (p2 >= 0 and (cnt2 or T[p2] == '#')) {
                if (T[p2] == '#') {
                    ++cnt2;
                    --p2;
                }
                else if (cnt2) {
                    --p2;
                    --cnt2;
                }
            }
            
            if (S[p1] == T[p2]) {
                --p1;
                --p2;
                if (not(p1 >= 0 and p2 >=0))
                    break;
            }
            else
                break;
        }
        if (p1 == p2 and p1 == -1)
            return true;
        else
            return false;
    }
};
