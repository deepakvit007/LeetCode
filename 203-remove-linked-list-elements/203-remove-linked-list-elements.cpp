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
        
        if(head==NULL)return NULL;
        
        
        ListNode* start=head,*temp,*temp2;
        
        while(start!=NULL && start->next!=NULL)
        {
            
             if(start->next->val==val)
            {
            
                temp2=start->next->next;
                delete start->next;
                start->next=temp2;
                
            }
            else
                
               start=start->next;
        }
        if(head->val==val)return head->next;
        
        return head;
        
    }
};