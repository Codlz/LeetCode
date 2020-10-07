
// @Title: 两数相加 (Add Two Numbers)
// @Author: 554216885@qq.com
// @Date: 2020-10-04 22:07:13
// @Runtime: 88 ms
// @Memory: 69.8 MB

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* p = head, * p1 = l1, *p2 = l2;

        int sum; bool iscarry = false;
        while (p1 && p2) {
            sum = p1->val + p2-> val;
            if (iscarry) {
                sum++;
                iscarry = false;
            }
            if (sum >= 10) {
                iscarry = true;
                sum -= 10;
            }
            ListNode* node = new ListNode(sum);
            p->next = node;
            p = node; p1 = p1->next; p2 = p2->next;
        }
        while (p1) {
            sum = p1->val;
            if (iscarry) {
                sum++;
                iscarry = false;
            }
            if (sum >= 10) {
                iscarry = true;
                sum -= 10;
            }
            ListNode* node = new ListNode(sum);
            p->next = node; 
            p = node;
            p1 = p1->next;
        }
        while (p2) {
            sum = p2->val;
            if (iscarry) {
                sum++;
                iscarry = false;
            }
            if (sum >= 10) {
                iscarry = true;
                sum -= 10;
            }
            ListNode* node = new ListNode(sum);
            p->next = node; 
            p = node;
            p2 = p2->next;
        }
        if (iscarry) {
            //最后还有进位
            p->next = new ListNode(1);
        }
        return head->next;
    }
};
