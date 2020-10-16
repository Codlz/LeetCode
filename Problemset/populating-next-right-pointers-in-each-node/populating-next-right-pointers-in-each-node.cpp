
// @Title: 填充每个节点的下一个右侧节点指针 (Populating Next Right Pointers in Each Node)
// @Author: 554216885@qq.com
// @Date: 2020-10-15 09:23:35
// @Runtime: 32 ms
// @Memory: 16.7 MB

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root, NULL, 0);

        return root;
    }
    void dfs(Node* root, Node* parent, int type) {
        //0代表根节点，1是左节点，2是右节点
        if (root == NULL)
            return;
        if (type == 0) {
        }
        else if (type == 1) {
            //左节点的next一定是父节点的右节点
            root->next = parent->right;
        }
        else if (type == 2) {
            if (parent->next != NULL) {
                root->next = parent->next->left;
            }
        }
        dfs(root->left, root, 1);
        dfs(root->right, root, 2);
    }
};
