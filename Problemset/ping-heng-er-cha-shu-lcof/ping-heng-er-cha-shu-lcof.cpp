
// @Title: 平衡二叉树 (平衡二叉树 LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-06 20:13:48
// @Runtime: 20 ms
// @Memory: 21.4 MB

class Solution {
public:
    
    bool isBalanced(TreeNode* root) {
        return recur(root) != -1;
    }
    int recur(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int l = recur(root->left);
        int r = recur(root->right);
        if (l == -1 || r == -1 || abs(l - r) > 1)
            return -1;
        return 1 + max(l,r);
    }
};
