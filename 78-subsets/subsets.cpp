class Solution {
public:
    void solve(vector<int>& input,vector<int>&output,int ind, vector<vector<int>>&ans)
    {
        if(ind>=input.size())
        {
            ans.push_back(output);
            return;
        }

        //pick
        output.push_back(input[ind]);
        solve(input,output,ind+1,ans);
        output.pop_back();

        solve(input,output,ind+1,ans);
    }
    vector<vector<int>> subsets(vector<int>& input) {

        vector<vector<int>>ans;
        vector<int>output;

        solve(input,output,0,ans);
        
        return ans;

        
    }
};