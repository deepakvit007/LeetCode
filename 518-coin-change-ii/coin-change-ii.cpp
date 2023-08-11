class Solution {
public:
 int help(int ind,vector<int>& coins,int tar,vector<vector<int>>&dp)
    {
        if(ind == 0)
        {
           if(tar % coins[ind] == 0)
           {
               return 1;
           }
           else
           {
               return 0;
           }
        }
        
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int pick = 0;
        if(coins[ind] <= tar)
        pick = help(ind ,coins,tar - coins[ind],dp);

        int npick = help(ind - 1, coins,tar,dp);

       
      return dp[ind][tar] = pick+npick;
      
    }
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>>dp(coins.size() ,vector<int>(amount + 1,-1));
        int ans = help(coins.size()-1,coins,amount,dp);
        
        //if(ans >= 1e9)return -1;
        
        return ans;
    }
};