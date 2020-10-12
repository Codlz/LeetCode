
// @Title: 最长不含重复字符的子字符串 (最长不含重复字符的子字符串 LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-09 14:08:27
// @Runtime: 12 ms
// @Memory: 6.7 MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alpha[128];
        memset(alpha, -1, 128 * sizeof(int));
        int count = 0, max_len = 0;
        //count代表当前以s[i - 1]为结尾的最长字符串
        for (int i = 0;i < s.size();i++) {
            if (alpha[s[i]] == -1)
            //s[i]还未出现
                count++;
            else
            {
                if (i - alpha[s[i]] <= count)
                    //上一个s[i]出现在当前字符串中
                    count = i - alpha[s[i]];
                else
                {
                    count++;
                }
                
            }      
            alpha[s[i]] = i;
            if (count > max_len) {
                max_len = count;
            }
        }
        return max_len;
    }
};
