
// @Title: 简化路径 (Simplify Path)
// @Author: 554216885@qq.com
// @Date: 2020-10-04 01:00:54
// @Runtime: 16 ms
// @Memory: 8.3 MB

class Solution {
public:
    string simplifyPath(string path) 
    {
        int i = 0, len = path.length();
        vector<string> stk;
        string result;
        while (i < len) {
            if (path[i] == '/') {
                int j = i + 1;
                string str;
                while (j < len && path[j] != '/') {
                    str.append(1,path[j]);
                    j++;
                }
                if (str.length() > 0)
                    stk.push_back(str);
                i = j;
            }
        }
        int back = 0;
        while (!stk.empty()) {
            string str = stk.back();
            stk.pop_back();
            if (str == "..") {
                back++;    
            }
            else if(str == ".") {}
            else {
                if (!back)
                    result.insert(0, "/" + str);
                else {
                    back--;
                }
            }
        }
        if (result.length() == 0) {
            result.append(1, '/');
        }
        return result;
    }
};
