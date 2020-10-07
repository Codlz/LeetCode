
// @Title: 搜索旋转排序数组 (Search in Rotated Sorted Array)
// @Author: 554216885@qq.com
// @Date: 2020-10-03 16:04:26
// @Runtime: 8 ms
// @Memory: 11 MB

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int begin = 0, end = nums.size() - 1;
        int index = -1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) {
                index = mid;
                break;
            }
            else if (nums[begin] <= nums[mid]) {
                //一个区间只要左右两端有序，这个区间就是有序的
                //mid的左边有序
                if (target < nums[mid] && target >= nums[begin]) {
                    end = mid - 1;
                }
                else {
                    begin = mid + 1;
                }
            }
            else {
                //mid要么左边有序，要么右边有序
                //mid 右边有序
                if (nums[mid] < target && target <= nums[end]) {
                    begin = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        return index;
    }
};
