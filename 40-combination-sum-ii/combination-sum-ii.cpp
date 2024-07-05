class Solution
{
    public:
        void solve(int ind, vector<int> &input, vector<int> &output, int target, vector< vector< int>> &ans)
        {
            if (target == 0)
            {
                ans.push_back(output);
                return;	//very imp
            }
            if (ind >= input.size() || target < 0)
            {
                return;
            }

           	//take
            output.push_back(input[ind]);
            solve(ind + 1, input, output, target - input[ind], ans);
            output.pop_back();
            while (ind + 1 < input.size() and input[ind] == input[ind + 1]) ind++;
           	//not take
            solve(ind + 1, input, output, target, ans);
        }
    vector<vector < int>> combinationSum2(vector<int> &nums, int target)
    {
        vector<vector < int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end());
        solve(0, nums, output, target, ans);

        return ans;
    }
};