class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        long sum = 0;
        int total = 0;
        mp[0]=1;
        for(auto s : nums)
        {
            sum+=s;
            if(mp.find(sum-k)!=mp.end())total+=mp[sum-k];

            mp[sum]++;

        }
        return total;
    }
};