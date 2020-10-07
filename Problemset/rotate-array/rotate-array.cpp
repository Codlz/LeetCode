
// @Title: 旋转数组 (Rotate Array)
// @Author: 554216885@qq.com
// @Date: 2020-10-03 14:44:50
// @Runtime: 4 ms
// @Memory: 9.6 MB

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k -1);
        reverse(nums, k, nums.size() - 1);
    }
    void reverse(vector<int>& nums, int begin, int end) 
    {   
        int temp;
        while (begin < end) {
            temp = nums[begin];
            nums[begin++] = nums[end];
            nums[end--] = temp;
        }
    }
};
