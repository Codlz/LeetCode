
// @Title: 股票的最大利润 (股票的最大利润  LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-06 20:37:35
// @Runtime: 12 ms
// @Memory: 12.6 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int i = 1, _min = prices[0], res = 0;
        while (i < prices.size()) {
            if (prices[i] - _min > res) 
                res = prices[i] - _min;
            _min = _min < prices[i] ? _min : prices[i];
            i++;
        }
        return res; 
    }
};
