// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    void solve(stack<int>&s, int k)
    {
        if(k==0)
        {
            s.pop();
            return;
        }
        
        int val=s.top();
        s.pop();
        solve(s,k-1);
        s.push(val);
    }
    
    
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int n)
    {
        if(n==0)return;
        int k;
        if(n%2==0)k=ceil(n+1)/2;
        else
        k=n/2;
        
        solve(s,k);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
  // } Driver Code Ends