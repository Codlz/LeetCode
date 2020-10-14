
// @Title: 接雨水 (Trapping Rain Water)
// @Author: 554216885@qq.com
// @Date: 2020-10-14 22:41:35
// @Runtime: 8 ms
// @Memory: 7.2 MB

class Solution {
public:
    //使用动态规划的解法
    // int trap(vector<int>& height) {
    //     if (height.size() == 0)
    //         return 0;
    //     int ans = 0;
    //     int size = height.size();
    //     vector<int> left_max(size), right_max(size);
    //     left_max[0] = height[0];
    //     for (int i = 1; i < size; i++) {
    //         left_max[i] = max(height[i], left_max[i - 1]);
    //     }
    //     right_max[size - 1] = height[size - 1];
    //     for (int i = size - 2; i >= 0; i--) {
    //         right_max[i] = max(height[i], right_max[i + 1]);
    //     }
    //     //使用动态规划，计算出每个柱子的左边和右边的最高的柱子(包括自己)
    //     for (int i = 1; i < size - 1; i++) {
    //         //一个竖块能存多少水等于它两边最高的柱子的高度 - 自己的高度
    //         ans += min(left_max[i], right_max[i]) - height[i];
    //     }
    //     return ans;
    // }
    int trap(vector<int> height) {
        stack<int> st;
        int cur = 0;
        int ans = 0;
        while (cur < height.size()) {
            //维持一个单调递减的单调栈，如果等于小于栈顶元素就入栈，否则一直出栈直到栈顶元素满足
            while (!st.empty() && height[cur] > height[st.top()]) {
                int n = st.top();
                st.pop();
                if(st.empty())
                    //前面已经没有可以挡水的柱子了
                    break;
                int len = cur - st.top() - 1;
                int bound_h = min(height[st.top()], height[cur]) - height[n];
                ans += len * bound_h;
            }
            st.push(cur);
            cur++;
        }

        return ans;
    }
};
