//{ Driver Code Starts
import java.util.*;
import java.io.*;

class Node{
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
    
}
class GFG{
	static void printList(Node node) 
	{ 
		while (node != null) 
		{ 
			System.out.print(node.data + " "); 
			node = node.next; 
		} 
		System.out.println(); 
	}
    public static void main(String args[]) throws IOException { 
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0){
        	int n = sc.nextInt();
            Node head = new Node(sc.nextInt());
            Node tail = head;
            for(int i=0; i<n-1; i++)
            {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }
            Solution g = new Solution();
            int ans = g.getMiddle(head);
            System.out.println(ans);
            //printList(head); 
            t--;
        }
    } 
} 
   
// } Driver Code Ends


/* Node of a linked list
 class Node {
   int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}
*/

class Solution
{
    int getMiddle(Node head)
    {
         // Your code here.
         int k=0;
        Node ptr=head;
        
        //length
        while(ptr!=null){
            ptr=ptr.next;
            k++;
           
        }
        
             Node temp=head;
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
        
    //     Node fast=head,slow=head;
        
    //     while(fast.next!=null && fast.next.next!=null)
    //     {
    //         fast=fast.next.next;
    //         slow=slow.next;
    //     }
        
    //   if(k%2==0)
    //     {return slow.next.data;}
    //   else
    //   {
    // return slow.data;
    //   }
     return temp.data;
   }
}