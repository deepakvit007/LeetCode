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
    int length(ListNode* head)
    {      
        int size = 0;
          while(head!=NULL)
          {
             head=head->next;
             size++;
          }

          return size;
    }
    ListNode * rem(ListNode* head, int ind)
    {
        if(head == NULL)
        return head;
        if(ind == 1 and head->next!=NULL)
        {
          head->next=head->next->next;
          return head;
        }

        return rem (head->next,ind -1);

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==NULL || head->next == NULL)return NULL;
        int size = length(head);
        int ind  = size - n  ;

        if(n == size )
        {
           return head->next;
        }

        ListNode*temp2 = head;
        while(ind>1)
        {
            head=head->next;
            ind--;
        }

        ListNode * temp = head->next->next;

        head->next = temp;

        return temp2;
    }
};