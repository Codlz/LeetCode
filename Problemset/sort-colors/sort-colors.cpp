
// @Title: 颜色分类 (Sort Colors)
// @Author: 554216885@qq.com
// @Date: 2020-10-07 20:39:30
// @Runtime: 0 ms
// @Memory: 8 MB

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p1 = 0;
        for (int i = 0;i < nums.size();i++) {
            if (nums[i] == 1) {
                swap(nums[i], nums[p1]);
                p1++;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                if (p0 < p1) {
                    //p0指针前面存在已经放置好的p1
                    swap(nums[p1], nums[i]);
                }
                p0++, p1++;
            }
        }
    }
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};
