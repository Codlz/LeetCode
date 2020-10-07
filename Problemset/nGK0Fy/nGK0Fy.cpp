
// @Title: 速算机器人 (速算机器人)
// @Author: 554216885@qq.com
// @Date: 2020-10-07 00:03:42
// @Runtime: 0 ms
// @Memory: 5.8 MB

class Solution {
public:
    Solution():x(1), y(0){}
    int calculate(string s) {
        
        for (char& c : s) {
            if (c == 'A')
                eval(true);
            else if (c == 'B')
                eval(false);
        }
        return x + y;
    }
    void eval(bool t) {
        if (t) {
            x += x + y;
        }
        else
        {
            y += x +y;
        }
        
    }
private:
    int x,y;
};
