// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
   void solve(string op,int n,int zero,int one, vector<string>&ans,const int x)
{
    if(n==0)
    {
        ans.push_back(op);
        return;
    }
    
    if(one!=x)
    {
        string op1=op;
        op1.push_back('1');
        solve(op1,n-1,zero,one+1,ans,x);
    }
    if(one>zero)
    {
        string op2=op;
        op2.push_back('0');
        solve(op2,n-1,zero+1,one,ans,x);
    }
}



	vector<string> NBitBinary(int N)
	{
	 vector<string>ans;
	 int zero=0;
	 int one=0;
	 string op="";
	 const int x=N;
	 solve(op,N,zero,one,ans,x);
	 return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}  // } Driver Code Ends