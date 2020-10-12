
// @Title: 环形链表 II (Linked List Cycle II)
// @Author: 554216885@qq.com
// @Date: 2020-10-10 19:02:52
// @Runtime: 8 ms
// @Memory: 7.5 MB

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* p1, * p2;
        p1 = head; p2 = head;
        while (true) {
            if (p2) {
                p2 = p2->next;
                if (p2)
                    p2 = p2->next;
                else return nullptr ;
            }
            else return nullptr;
            p1 = p1->next;
            if (p1 == p2)
                break;
        }
        ListNode* p3 = head;
        while (p3 != p1) {
            p3 = p3->next;
            p1 = p1->next;
        }   
        return p3;
    }
};
