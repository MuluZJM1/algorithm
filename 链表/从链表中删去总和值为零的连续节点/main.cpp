#include <iostream>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        ListNode* phead = new ListNode(int());
        phead->next = head;
        ListNode* cur = phead;
        while (cur)
        {
            ListNode* tail = cur->next;
            int sum = 0;
            while (tail)
            {
                sum += tail->val;
                if (tail && sum == 0)
                {
                    cur->next = tail->next;
                }
                tail = tail->next;
            }
            cur = cur->next;
        }

        return phead->next;
    }
};