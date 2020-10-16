
// @Title: 有序数组的平方 (Squares of a Sorted Array)
// @Author: 554216885@qq.com
// @Date: 2020-10-16 11:39:38
// @Runtime: 68 ms
// @Memory: 26.1 MB

class Solution {
public:
    vector<int> sortedSquares(vector<int> A) {
        vector<int> res;
        int min_abs = 0x3f3f3f3f; int min_idx = -1;
        for (int i = 0;i < A.size();i++) {
            if (abs(A[i]) < min_abs) {
                min_idx = i;
                min_abs = abs(A[i]);
            }
        }
        res.push_back(A[min_idx] * A[min_idx]);
        int i = min_idx - 1, j = min_idx + 1;
        while (i >= 0 && j < A.size()) {
            if (abs(A[i]) <= abs(A[j])) {
                res.push_back(A[i] * A[i]);
                i--;
            }
            else
            {
                res.push_back(A[j] * A[j]);
                j++;
            }    
        }
        while (i >= 0) {
            res.push_back(A[i] * A[i]);
            i--;
        }
        while (j < A.size()) {
            res.push_back(A[j] * A[j]);
            j++;
        }

        return res;
    }
};
