
// @Title: 摆动序列 (Wiggle Subsequence)
// @Author: 554216885@qq.com
// @Date: 2020-10-05 00:02:18
// @Runtime: 0 ms
// @Memory: 7 MB

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int len = 1;
        //长度至少为1

        //状态
        const int begin = 0;
        const int up = 1;
        const int down = 2;
        int flag = begin;
        for (int i = 1;i < nums.size();i++) {
            //每有一次状态变化，len加一
            switch (flag)
            {
            case begin:
                
                if (nums[i-1] < nums[i]){ 
                    flag = up;
                    len++;
                }
                else if(nums[i-1] > nums[i]){
                    flag = down;
                    len++;
                }
                continue;
            
            case up:
                if (nums[i-1] > nums[i]) {
                    len++;
                    flag = down;
                }
                continue;
            case down:
                if (nums[i-1] < nums[i]) {
                    len++;
                    flag = up;
                }
                continue;
            
            default:
                continue;
            }
        }
        return len;
        
    }
};
