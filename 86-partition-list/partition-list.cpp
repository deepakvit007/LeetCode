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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL )return NULL;
         if(head->next==NULL )return head;
        ListNode * list1 = NULL;
        ListNode * list2 = NULL;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL)
        {
           if(temp->val<x)
           {
                ListNode *newNode = new ListNode(temp->val);
               if(list1 == NULL)
               {
                   list1 = newNode;

               }
               else
               {
              
                ListNode *ptr = list1;

                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
               }
                prev = newNode;
               
           } 
           else if(temp->val>=x)
           {
               if(list2 == NULL)
               {
                   list2 = new ListNode(temp->val);

               }
               else
               {
               ListNode *newNode = new ListNode(temp->val);
                ListNode *ptr = list2;

                while(ptr->next!=NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newNode;
               }

           }

           temp = temp->next;
        }
       if(list1!=NULL)prev->next = list2;
    else
    return list2;
       return list1;
    }
};