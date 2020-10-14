
// @Title: 两两交换链表中的节点 (Swap Nodes in Pairs)
// @Author: 554216885@qq.com
// @Date: 2020-10-13 09:00:23
// @Runtime: 0 ms
// @Memory: 7.4 MB

typedef ListNode* List;
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head)
            return NULL;
        List h = new ListNode;
        h->next = head;
        List p1 = h, p2 = head, p3 = head->next;
        int t = 1;
        while (p3) {
            t++;
            if (t == 2) {
                p2->next = p3->next;
                p3->next = p2;
                p1->next = p3;
                List temp = p2;
                p2 = p3; 
                p3 = temp;
                t = 0;
            }
            p1 = p1->next; p2 = p2 ->next; p3 = p3 -> next;
        }
        return h->next;
    }
};
