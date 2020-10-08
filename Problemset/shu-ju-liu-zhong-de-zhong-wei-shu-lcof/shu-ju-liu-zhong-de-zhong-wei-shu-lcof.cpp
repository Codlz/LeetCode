
// @Title: 数据流中的中位数 (数据流中的中位数  LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-08 10:26:34
// @Runtime: 224 ms
// @Memory: 40.9 MB

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > l;
    //小顶堆，存较大部分
    priority_queue<int> s;
    //大顶堆，存较小部分
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (l.empty() && s.empty())
            s.push(num);
        else if (l.size() == s.size()) {
            if (num < l.top()) 
                s.push(num);
            else 
                l.push(num);
        }
        else if (s.size() < l.size()) {
            if (num <= l.top()) {
                s.push(num);
            }
            else {
                s.push(l.top());
                l.pop();
                l.push(num);
            }
        }
        else {
            if (num >= s.top()) {
                l.push(num);
            }
            else {
                l.push(s.top());
                s.pop();
                s.push(num);
            }
        }
    }
    
    double findMedian() {
        if (l.size() == s.size()) {
            return (l.top() + s.top()) / 2.0; 
        }
        else if (l.size() < s.size()) {
            return s.top();
        }
        else {
            return l.top();
        }
    }
};
