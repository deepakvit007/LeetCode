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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head->next==NULL)
        {delete head ;
         return NULL;
        }
        // if(head->next->next==NULL)
        // {
        //     delete head->next;
        //     head->next=NULL;
        //     return head;
        // }
        
         ListNode* fast=head,*slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;//1 moves
            fast=fast->next->next;// 2 moves 
        }
        
        ListNode *temp;
       if(slow->next!=NULL)
       {
           swap(slow->val,slow->next->val);
           temp=slow->next->next;
           delete slow->next;
           slow->next=temp;
       }
        else
        { delete slow->next;
            head->next=NULL;
        }
        
        return head;
        
    }
};