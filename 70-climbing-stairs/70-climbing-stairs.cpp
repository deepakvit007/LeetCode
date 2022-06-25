class Solution {
public:
//     int solve(int n,vector<int>&dp)
//     {
//         if(n<0)return 0;
//         if(n==0)return 1;
        
//         if(dp[n]!=-1)return dp[n];
        
//         return dp[n]=solve(n-1,dp)+solve(n-2,dp);
        
//     }
   
    
    int climbStairs(int n) {
        //vector<int>dp(n+1,-1);
//         return solve2(n,dp);
        
        // if(n==0||n==1)return n;

    
       //vector<int>dp(n+1);
        
//          dp[1]=1;
//         dp[0]=0;
       int prev1,prev2,curr;
        
        prev1=1;
        prev2=1;
        
        for(int i=2;i<=n;i++)
        {
         //dp[i] =dp[i-1]+dp[i-2]; 
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
  
        return prev1;
    }
        
    
};