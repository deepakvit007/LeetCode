class Solution {
public:
    int solve2(vector<int>&cost,int n,vector<int>&dp){
// BASE CASE
if(n==0)
    return cost[0];
if(n==1)
    return cost[1];
// step3:
if(dp[n]!=-1)
    return dp[n];
// step2

dp[n]=cost[n]+min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
return dp[n];
}

int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size();
  // STEP1
  vector<int> dp(n+1,-1);
  int ans= min(solve2(cost,n-1,dp),solve2(cost,n-2,dp));
   return ans;
          
    }
};