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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode * dummy  = new ListNode(0);
        ListNode * tail = dummy;
        
        dummy->next = head;

        while(tail->next!=NULL)
        {
            if(tail->next->val == val)
            {
                tail->next = tail->next->next;
            }
            else
            {
                tail = tail->next;
            }
        }

        return dummy->next;
    }
};