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
        
        /*FLLOYD CYCLE DETECTION ALGORITHM*/
         if(head==NULL)return false;
        
        ListNode* fast=head,*slow=head;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            
            
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
            
        }
        return false;
        /*Normal Method*/
        
       
//         map<ListNode*,bool>visit;
        
//         while(head!=NULL)
//         {
//             if(visit[head]==true)
//             {
//                 return true;
//             }
//             visit[head]=true;
//             head=head->next;
//         }
//         return false;
        
        
    }
};