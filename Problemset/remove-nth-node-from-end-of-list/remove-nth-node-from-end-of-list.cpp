
// @Title: 删除链表的倒数第N个节点 (Remove Nth Node From End of List)
// @Author: 554216885@qq.com
// @Date: 2020-10-18 18:58:11
// @Runtime: 4 ms
// @Memory: 10.8 MB

class Solution
{
    typedef ListNode* ptr;
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ptr nh = new ListNode;
        nh->next = head;
        int len = 0;
        ptr p1 = nh, p2 = nh;
        while (p2->next != NULL) {
            len++;
            p2 = p2->next;
            if (len > n)
                p1 = p1->next;
                //p1比p2落后n个，当p2到达尾部时，p1在倒数第n+1个
        }
        p1->next = p1->next->next;

        return nh->next;
    }
};
