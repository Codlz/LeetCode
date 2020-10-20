
// @Title: 重排链表 (Reorder List)
// @Author: 554216885@qq.com
// @Date: 2020-10-20 11:19:49
// @Runtime: 76 ms
// @Memory: 19 MB

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        
        if (head == NULL or head->next == NULL or head->next->next == NULL)
        //只有一个或两个节点
            return;
        ListNode* p = head->next;
        vector<ListNode*> v;
        int cnt = 0;
        while (p->next != NULL) {
            //在Ln停下
            v.push_back(p);
            ++cnt;
            p = p->next;
        }
        head->next = p;
        int i = 0, j = cnt - 1;
        while (i < j) {
            p->next = v[i];
            i++;
            p = p->next;
            p->next = v[j];
            j--;
            p = p->next;
        }
        p->next = NULL;
        if (i == j)
            //奇数个情况
            p->next = v[i];
        v[i]->next = NULL;

        return;
    }
};
