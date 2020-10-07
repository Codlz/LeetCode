
// @Title: 两数之和 (Two Sum)
// @Author: 554216885@qq.com
// @Date: 2020-10-03 12:33:56
// @Runtime: 752 ms
// @Memory: 8.7 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0;i < nums.size() - 1;i++) {
            for (int j = i + 1;j < nums.size();j++) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
       return result; 
    }
};
