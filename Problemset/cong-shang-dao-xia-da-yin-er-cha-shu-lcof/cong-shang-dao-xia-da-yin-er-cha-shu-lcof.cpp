
// @Title: 从上到下打印二叉树 (从上到下打印二叉树 LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-06 20:19:51
// @Runtime: 8 ms
// @Memory: 11.9 MB

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
    vector<int> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            res.push_back(cur->val);
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        return res;
    }
};
