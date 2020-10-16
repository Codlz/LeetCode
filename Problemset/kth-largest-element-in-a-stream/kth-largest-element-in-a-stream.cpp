
// @Title: 数据流中的第K大元素 (Kth Largest Element in a Stream)
// @Author: 554216885@qq.com
// @Date: 2020-10-14 23:59:32
// @Runtime: 76 ms
// @Memory: 19.9 MB

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) : k(k) {
        for (int i = 0;i < nums.size();i++) {
            q1.push(nums[i]);
        }
        while (q1.size() > k)
            q1.pop();

    }
    
    int add(int val) {
        q1.push(val);
        if (q1.size() > k)
            q1.pop();
        return q1.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int> > q1;
};
