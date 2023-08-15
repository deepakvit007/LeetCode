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
    void insertAtEnd(ListNode*& head, ListNode * newNode)
    {
        
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
        ListNode * temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        }

    }
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL )return NULL;
        if(head->next==NULL )return head;
        ListNode * list1 = NULL;
        ListNode * list2 = NULL;
        
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp!=NULL)
        {
            ListNode * newNode = new ListNode(temp->val);
            if(temp->val < x )
            {
                insertAtEnd(list1,newNode);
                prev = newNode;
            }
            else if(temp->val>=x)
            {
                insertAtEnd(list2,newNode);
            }

            temp = temp->next;
        }

        if(list1!=NULL)
        {prev->next = list2;
        return list1;
        }

        return list2;

    }

};