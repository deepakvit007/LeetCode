class Solution {
public:
    
void solve(vector<int> nums,vector<int>out,vector<vector<int>>&ans)
{
    if(nums.size()==0)
    {
         ans.push_back(out);
         return;
       
    }

    vector<int>out1=out;
    vector<int>out2=out;
    out2.push_back(nums[0]);
    nums.erase(nums.begin()+0);
    
    solve(nums,out1,ans);
    solve(nums,out2,ans);


}

vector<vector<int>> subsets(vector<int>& nums) {

vector<vector<int>>ans;
vector<int>out;
solve(nums,out, ans);
    return ans;
}
};