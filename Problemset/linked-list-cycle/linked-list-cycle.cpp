
// @Title: 环形链表 (Linked List Cycle)
// @Author: 554216885@qq.com
// @Date: 2020-10-09 10:03:51
// @Runtime: 12 ms
// @Memory: 7.6 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1, *p2;
        p1 = head; p2 = head;
        while (p1 != nullptr && p2 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
            if (p2) 
                p2 = p2->next;
            else 
                break;
            if (p1 == p2) {
                return true;
            }
        }
        return false;
    }
};
