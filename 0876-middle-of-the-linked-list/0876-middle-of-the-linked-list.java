/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        
        int k=0;
        ListNode ptr=head;
        
        //length
        while(ptr!=null){
            ptr=ptr.next;
            k++;
           
        }
        
             ListNode temp=head;
        int i=0;
        if(k%2==0){
            
            
        while(i<k/2){
            temp=temp.next;
            i++;
        }
        //temp=temp.next;
            
        }
        else{
            
            while(i<k/2){
                temp=temp.next;
                i++;
            }
        }
        
        
        return temp;
        
    }
}