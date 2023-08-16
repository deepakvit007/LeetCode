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

        ListNode* reverse(ListNode* head) {
        if(head==NULL)return head;
        ListNode * prev = NULL;
        ListNode * curr = head;//5
        ListNode * nex = head->next;//4

        while(curr!=NULL)
        {
            curr->next = prev;

            prev = curr;
            curr = nex;
            if(nex!=NULL)nex = nex->next;

        }
       head=prev;
       return head;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        ListNode*ptr = head;
        while(head->next!=NULL)
        {
            if(head->val > head->next->val)
            {
                head->next = head->next->next;
            }
            else
            {
                head=head->next;
            }
        }

        head = reverse(ptr);
        return head;
    }
};