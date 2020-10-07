
// @Title: 子集 (Subsets)
// @Author: 554216885@qq.com
// @Date: 2020-10-04 15:24:07
// @Runtime: 4 ms
// @Memory: 6.9 MB

class Solution {
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int> > res;
    int n = nums.size();
    int kase = 1 << n;//有2^N种情况,从0到2^n-1遍历
    for (int i = 0;i < kase;i++) {
        vector<int> _vec;
        for (int j = 0;j < n;j++) {
            if(i & (1 << j))
                _vec.push_back(nums[j]);
        }
        res.push_back(_vec);
    }
    return res;
    }
};
