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
        if(head == NULL)return head;
        ListNode*temp = head;
        while(temp!=NULL and temp->next!=   NULL)
        {
          if(temp->next->val == val)
          {
             
                  //swap(temp->val, temp->next->val);
                    ListNode*temp2 = temp->next->next;
                  temp->next = temp2;
             
            //   else
            //   {
            //       temp = NULL;
                  
            //       return head;
            //   }
          }
          else
          temp=temp->next;
        }
        if(head->val==val)return head->next;

        return head;
    }
};