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
class cmp
{
    public:
     bool operator()(ListNode*a,ListNode*b)
    {
        return a->val > b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {

      priority_queue<ListNode*,vector<ListNode*>,cmp>pq;

      for(auto node : lists)
      {
         if(node!=NULL) pq.push(node);
      }
      ListNode* start = new ListNode(0);
      ListNode *tail = start;
      while(!pq.empty())
      {
          auto temp = pq.top();
          pq.pop();
          tail->next = temp;
          tail = temp;

          if(temp->next!=NULL)
          { 
              pq.push(temp->next);

          }
      }
     return start->next;
    }
};