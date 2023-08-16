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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*,int>mp;
        
        while(headA!=NULL)
        {
            mp[headA]++;
            headA=headA->next;
        }
        
        while(headB!=NULL)
        {
            if(mp.find(headB)!=mp.end())return headB;
            headB=headB->next;
        }

      return NULL;
    }
};