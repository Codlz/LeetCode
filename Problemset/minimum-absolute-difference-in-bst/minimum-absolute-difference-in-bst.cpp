
// @Title: 二叉搜索树的最小绝对差 (Minimum Absolute Difference in BST)
// @Author: 554216885@qq.com
// @Date: 2020-10-12 09:21:05
// @Runtime: 24 ms
// @Memory: 24.4 MB

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int min; int pre;
    
    int getMinimumDifference(TreeNode* root) {
        //搜索二叉树的中序遍历是一个递增的序列
        min = 0x3f3f3f, pre = 0x3f3f3f;
        dfs(root);

        return min;
    }
    void dfs(TreeNode* root) {
        if (!root)
            return;
        dfs(root->left);
        int s = abs(pre - root->val);
        min = min < s ? min : s;
        pre = root->val;
        dfs(root->right);
    }
};
