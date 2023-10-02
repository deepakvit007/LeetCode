class Solution {
public:
    int topDown(vector<int>&arr,int tar,vector<long long>&dp)
{
    if(tar == 0)
    {
        return 1;
    }
    if(tar<0)
    return 0;
    if(dp[tar]!=-1)return dp[tar];
    long long res = 0;
    for(int i=0;i<arr.size();i++)
    {
        long long ans  = topDown(arr,tar-arr[i],dp);
        res+=ans;
        
    }

    return dp[tar]=res;

}
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long>dp(target+1,-1);
        return topDown(nums,target,dp);
    }
};