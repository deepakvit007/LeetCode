class Solution {
public:
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(i>j)return 0;

        if(i == j)return nums[i];
        if(dp[i][j]!=-1)return dp[i][j];
        int takei = nums[i] + min(solve(i+2,j,nums,dp),solve(i+1,j-1,nums,dp));
        int takej = nums[j] + min(solve(i+1,j-1,nums,dp),solve(i,j-2,nums,dp));

        return dp[i][j] = max(takei,takej);
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n =  nums.size();
         vector<vector<int>>dp(n,vector<int>(n,-1));
        int sum = accumulate(nums.begin(),nums.end(),0);
        int player1 = solve(0,n-1,nums,dp);

        int player2 = sum - player1;

        if(player2>player1)return false;


        return true;

    }
};