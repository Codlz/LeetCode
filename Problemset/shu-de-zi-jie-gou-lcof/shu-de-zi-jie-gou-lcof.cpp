
// @Title: 树的子结构 (树的子结构  LCOF)
// @Author: 554216885@qq.com
// @Date: 2020-10-06 10:25:44
// @Runtime: 76 ms
// @Memory: 32.9 MB

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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if ( A == nullptr || B == nullptr) 
            return false;
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
        //先对当前节点进行比较，若以当前A节点为根的树和B不符合，就继续先序遍历（深搜）的子节点
        //recur用于判断以A节点为根和以B节点为根的树结构是否相同
    }
    bool recur(TreeNode* sub_A, TreeNode* B) {
        if (B == NULL) {
            //没有出现不匹配,B已经搜索完了
            return true;
        } 
        if (sub_A == NULL) {
            
            return false;
        }
        if (sub_A->val == B->val) {
            return recur(sub_A->left, B->left) && recur(sub_A->right, B->right);
        }
        else
        {
            return false;
        }
    }
};
