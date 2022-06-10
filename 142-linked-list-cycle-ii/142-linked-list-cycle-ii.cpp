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
    ListNode*meetPoint(ListNode*head)
    {
        /*FLLOYD CYCLE DETECTION ALGORITHM*/
         if(head==NULL)return NULL;
        
        ListNode* fast=head,*slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return slow;
            
        }
        return NULL;
        /*Normal Method*/
        
       
//         map<ListNode*,bool>visit;
        
//         while(head!=NULL)
//         {
//             if(visit[head]==true)
//             {
//                 return head->val;
//             }
//             visit[head]=true;
//             head=head->next;
//         }
//         return NULL;
        
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)return NULL;
        ListNode *meet=meetPoint(head),*start=head;
        
        if(meet==NULL)return NULL;
        
        while(start!=meet)
        {
            start=start->next;
            meet=meet->next;
        }
        return start;
        
        
    }
};