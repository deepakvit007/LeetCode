class Solution {
public:
    void solve(vector<int>nums, set<vector<int>>&subset,vector<int>out)
    {
        if(nums.size()==0)
        {
            sort(out.begin(),out.end());
            subset.insert(out);
            return;
        }
        
        vector<int>out1=out;
        vector<int>out2=out;
        
        out2.push_back(nums[0]);
        nums.erase(nums.begin()+0);
        solve(nums,subset,out1);
        solve(nums,subset,out2);
                      
     }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>>ans;
        set<vector<int>>subset;
        vector<int>out;
        solve(nums,subset,out);
        
        for(auto it = subset.begin();it!=subset.end();it++)
        {
            ans.push_back(*it);
        }
        return ans;
        
    }
};