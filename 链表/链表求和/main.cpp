#include <iostream>
#include <list>

 struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* cur1 = l1, * cur2 = l2;
        ListNode* phead = new ListNode(int());
        ListNode* tail = phead;
        int carry = 0;//ฝ๘ฮป
        int remainder = 0;//ำเสý
        while (cur1 || cur2)
        {
            int val1 = cur1 == nullptr ? 0 : cur1->val;
            int val2 = cur2 == nullptr ? 0 : cur2->val;
            remainder = (val1 + val2 + carry) % 10;
            carry = (val1 + val2 + carry) / 10;
            ListNode* newnode = new ListNode(remainder);
            tail->next = newnode;
            tail = newnode;

            if (cur1)
                cur1 = cur1->next;
            if (cur2)
                cur2 = cur2->next;
        }

        if (carry)
        {
            ListNode* newnode = new ListNode(carry);
            tail->next = newnode;
        }

        return phead->next;
    }
};