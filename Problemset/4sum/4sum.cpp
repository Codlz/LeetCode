
// @Title: 四数之和 (4Sum)
// @Author: 554216885@qq.com
// @Date: 2020-10-05 10:39:06
// @Runtime: 80 ms
// @Memory: 12.9 MB

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 4) {
            return result;
        }
        sort(nums.begin(), nums.end());
        //进行排序
        //双重循环，循环中每次固定的都是最小的两个数
        //双重指针，对剩余的未固定的两个数进行选择
        for (int i= 0, len = nums.size();i < len - 3;i++) {
            if (i > 0 && nums[i - 1] == nums[i]){
                //同一层循环的相同最小数只取一次
                continue;
            }
            for (int j = i + 1;j < len - 2;j++) {
                if (j > i + 1 && nums[j - 1] == nums[j]){
                    continue;
                }
                //双指针起始
                int left = j + 1, right = len - 1;
                
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                
                        left++;
                        while (left < right && nums[right - 1] == nums[right]) {
                            right--;
                        }
                        right--;
                        //把指针移动到相同元素之后，避免重复录入
                    }
                    else if (sum < target) {
                        left++;
                    }
                    else if(sum > target) {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
