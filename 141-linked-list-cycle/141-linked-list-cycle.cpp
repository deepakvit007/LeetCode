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
        
        if(head==NULL)return false;
        map<ListNode*,bool>visit;
        
        while(head!=NULL)
        {
            if(visit[head]==true)
            {
                return true;
            }
            visit[head]=true;
            head=head->next;
        }
        return false;
    }
};