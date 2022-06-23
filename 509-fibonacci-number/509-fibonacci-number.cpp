class Solution {
public:
//     int solve(int n,int dp[n+1])
//     {
//          if(n==0||n==1)return n;
        
//         if(dp[n]!=-1)return dp[n];
        
//         dp[n]=fib(n-1)+fib(n-2);
//         return dp[n];
//     }
    
    int fib(int n) {
        
         if(n==0||n==1)return n;

    
       vector<int>dp(n+1);
        
         dp[1]=1;
        dp[0]=0;
       
        
        
        
        for(int i=2;i<=n;i++)
        {
         dp[i] =dp[i-1]+dp[i-2];  
        }
  
        return dp[n];
    }
};