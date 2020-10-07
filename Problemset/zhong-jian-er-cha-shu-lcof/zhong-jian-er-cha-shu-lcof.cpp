
// @Title: 重建二叉树 (重建二叉树 LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-04 21:27:42
// @Runtime: 24 ms
// @Memory: 25.2 MB

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
    TreeNode* bulid(int pre_root, int left_border, int right_border, vector<int>& preorder) {
        if (left_border > right_border) 
            return NULL;
        int in_index = _map[preorder[pre_root]];
        //找到当前的根，在中序遍历中的索引
        TreeNode* root = new TreeNode(preorder[pre_root]);

        root->left = bulid(pre_root + 1, left_border, in_index - 1, preorder);
        int left_tree_size = in_index - left_border;
        root->right = bulid(pre_root + 1 + left_tree_size, in_index + 1, right_border, preorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0;i < inorder.size();i++) {
            _map[inorder[i]] = i;
        }
        //使用哈希表存储中序遍历的索引，便于查找
        return bulid(0, 0, inorder.size() - 1, preorder);
        //先序遍历的根索引，中序遍历的左边界，中序遍历的右边界
    }
    
    unordered_map<int, int> _map;
};
