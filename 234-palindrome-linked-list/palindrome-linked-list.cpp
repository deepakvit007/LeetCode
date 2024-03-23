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
    bool isPalindrome(ListNode* head) {
     
         ListNode* temp = head;
       string str = "";                  
       while(temp != NULL)
       {
           str += temp->val;
           temp = temp -> next;
       }
       
       int len = str.size();                    
       int low = 0 , high = len-1;
       while(low < high)
       {
           if(str[low]!=str[high])           
           {
               return false;
           }
           low ++;
           high --;
       }
       return true;
    }
};