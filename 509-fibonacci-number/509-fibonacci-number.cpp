class Solution {
public:
    int solve(int n,int dp[n+1])
    {
         if(n==0||n==1)return n;
        
        if(dp[n]!=-1)return dp[n];
        
        dp[n]=fib(n-1)+fib(n-2);
        return dp[n];
    }
    
    int fib(int n) {
    
       int dp[n+1];
        for(int i=0;i<=n;i++)
        {
         dp[i] =-1;  
        }
        int ans=solve(n,dp);
        return ans;
    }
};