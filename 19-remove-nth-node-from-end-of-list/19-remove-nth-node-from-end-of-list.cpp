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
    int count(ListNode* head)
    {
        int count =0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
            
        }
        return count;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
            
       int m=count(head);
        if(m==1)return NULL;
        if(n==m)return head->next;
        ListNode* current=head;
      int val=m-n;
        ListNode* prev;
        int i=1;
        while(i!=val)
        {
             current=current->next;
            i++;
        }
       current->next=current->next->next;
          
        return head;
        
    }
};