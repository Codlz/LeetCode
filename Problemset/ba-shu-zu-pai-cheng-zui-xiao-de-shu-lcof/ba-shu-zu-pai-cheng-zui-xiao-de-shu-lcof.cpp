
// @Title: 把数组排成最小的数 (把数组排成最小的数 LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-09 19:22:30
// @Runtime: 32 ms
// @Memory: 11.3 MB

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> _vec;
        string res;
        for (int i = 0;i < nums.size();i++) {
            _vec.push_back(to_string(nums[i]));
        }
        sort(_vec.begin(), _vec.end(), cmp);
        for (int i = 0;i < _vec.size();i++) {
            res.insert(res.length(), _vec[i]);
        }

        return res;
    }
    inline static bool cmp(string a, string b) {
        return a + b < b + a;
    }
};
