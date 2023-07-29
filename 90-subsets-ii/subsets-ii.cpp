class Solution {
public:
    
     void help(int ind , vector<int>out,vector<int>&nums,  vector<vector<int>>&st)
    {
        if(ind>=nums.size())
        {
            
            st.push_back(out);
            return;
        }
        out.push_back(nums[ind]);
        help(ind+1,out,nums,st);
        out.pop_back();

        while(ind+1<nums.size() and nums[ind] == nums[ind+1])ind++;
        help(ind+1,out,nums,st);
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>out;
        vector<vector<int>>ans;
sort(nums.begin(),nums.end());
        help(0,out,nums,ans);
        
        return ans; 
    }
};