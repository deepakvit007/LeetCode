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
    pair<ListNode*,ListNode*> middle (ListNode * head)
    {
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = NULL;

        while(fast!=NULL and fast->next!=NULL)
        {   
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return {head,slow};
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        
        ListNode *start = new ListNode(0);
        ListNode *tail = start;

        if(list1==NULL)return list2;
        if(list2==NULL)return list1;

        while(list1!=NULL and list2!=NULL)
        {
            if(list1->val <= list2->val)
            {
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else if(list1->val > list2->val)
            {
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }

            
        }

        if(list1==NULL)tail->next = list2;
        else
        tail->next = list1;

        return start->next;

    }
    ListNode* mergeSort(ListNode* head)
    {
        if(head == NULL || head->next == NULL)return head ;

        auto mid = middle(head);
        ListNode *l1 = mid.first;
        ListNode *l2 = mid.second;

       l1 =  mergeSort(l1);
        l2 = mergeSort(l2);

        return merge(l1,l2);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);

    
    }
};