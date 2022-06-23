class Solution {
public:
    
void solve(vector<int> nums,int index,vector<int>out,vector<vector<int>>&ans)
{
    if(index>nums.size()-1)
    {
         ans.push_back(out);
         return;
       
    }

    solve(nums,index+1,out,ans);

    int element=nums[index];
    out.push_back(element);

    solve(nums,index+1,out,ans);

 

}

vector<vector<int>> subsets(vector<int>& nums) {

vector<vector<int>>ans;
int index=0;
vector<int>out;
solve(nums,index,out, ans);
    return ans;
}
};