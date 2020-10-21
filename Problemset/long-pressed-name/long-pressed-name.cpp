
// @Title: 长按键入 (Long Pressed Name)
// @Author: 554216885@qq.com
// @Date: 2020-10-21 00:35:44
// @Runtime: 0 ms
// @Memory: 6.4 MB

class Solution {
public:
    bool isLongPressedName(string name, string typed) 
    {
        int i = 0, j = 0;
        while (i < name.length() and j < typed.length()) {
            if (name[i] == typed[j]) {
                while (typed[j + 1] == name[i]) {
                    //把j字符串移动到同一字符的最后面
                    ++j;
                    if (name[i + 1] == name[i]) 
                        ++i;
                }
                ++i; ++j;
            }
            else {
                return false;
            }
        }
        
        if (i == name.length() and j == typed.length())
            return true;
        return false;
    }
};
