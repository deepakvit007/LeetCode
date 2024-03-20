/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
        {
            if(list1 == NULL || list2 == NULL)return list1;

            ListNode *start = list1;
            int counter = 0;

            ListNode *begin = NULL, *end = NULL;

            while (start != NULL)
            {
                if (counter == a - 1)
                {
                    begin = start;
                }
                if (counter == b + 1)
                {
                    end = start;
                    break;
                }
                start = start->next;
                counter++ ;
            }

            begin->next = list2;

            while (list2->next != NULL)
            {
                list2 = list2->next;
            }

            list2->next = end;

            return list1;
        }
};