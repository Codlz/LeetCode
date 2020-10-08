
// @Title: 三等分 (Three Equal Parts)
// @Author: 554216885@qq.com
// @Date: 2020-10-08 21:08:34
// @Runtime: 104 ms
// @Memory: 37.6 MB

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int> A) {
        int n = A.size();
        int sum_one[30001];

        sum_one[0] = A[0];
        for (int i = 1;i < A.size();i++) {
            //计算到第i位一共有多少个1
            sum_one[i] = sum_one[i - 1] + A[i];
        }
        if (sum_one[n - 1] % 3 != 0) {
            return {-1, -1};
        }
        if (sum_one[n - 1] == 0)
            return {0, n - 1};
        int one = sum_one[n - 1] / 3; //每一部分1的数量

        int back_zero = 0;
        for (int i = n - 1;A[i] == 0;i--) {
            //计算第三部分的后缀0个数
            back_zero++;
        }

        int end1 = search(0, n - 1, one, sum_one) + back_zero; //第一部分的结尾
        int start3 = search(end1 + 1, n - 1, one * 2, sum_one) + back_zero + 1; //第三部分的开始
        if (start3 == -1 || start3 > n - 1)
            return {-1, -1};
        int i = end1; int j = start3 - 1; int k = n - 1;
        while (i >= 0 && j > end1 && k >= start3) {
            if (A[i] == A[j] && A[j] == A[k]) {
                i--; j--; k--;
            }
            else {
                return {-1, -1};
            }
        }
        return {end1, start3};
    }
    int search(int begin, int end, int target, int* arr) {
        for (int i = 0;i < end;i++) {
            if (arr[i] == target)
                return i;
        }
        return -1;
    }
};
