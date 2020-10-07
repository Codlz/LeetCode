
// @Title: 队列的最大值 (队列的最大值 LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-06 23:47:15
// @Runtime: 272 ms
// @Memory: 47.9 MB

class MaxQueue {
public:
    queue<int> _q;
    deque<int> max_q;
    MaxQueue() {
    
    }
    
    int max_value() {
        if (max_q.empty())
            return -1;
        return max_q.front();
    }
    
    void push_back(int value) {
        while (!max_q.empty() && max_q.back() < value)
            max_q.pop_back();
        max_q.push_back(value);
        _q.push(value);
    }
    
    int pop_front() {
        if (_q.empty())
            return -1;
        int val = _q.front();
        _q.pop();
        if (val == max_q.front())
            max_q.pop_front();
        return val;
    }
};
