class Solution
{
public:
    void solve(int ind, vector<int> &input, vector<int> output, int target, vector< vector< int>> &ans)
    {
        if (ind >= input.size() || target < 0)
        {
            return;
        }
        
        if (target == 0)
        {
            ans.push_back(output);
            return;	//very imp
        }

        //take (we can take unlimited numbers so no need to increase index)
        output.push_back(input[ind]);
        solve(ind, input, output, target - input[ind], ans);
        output.pop_back();
        
        //not take
        solve(ind + 1, input, output, target, ans);
    }
    vector<vector < int>> combinationSum(vector<int> &input, int target)
    {
        vector<vector < int>> ans;
        vector<int> output;
        solve(0, input, output, target, ans);

        return ans;
    }
};