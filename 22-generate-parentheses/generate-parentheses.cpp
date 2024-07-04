class Solution
{
    public:
        void solve(int open, int close, int n, string output, vector<string> &ans)
        {
            if (open == 0 and close == 0)
            {
                ans.push_back(output);
                return;
            }

            if (open == close)
            {
                solve(open - 1, close, n, output + '(', ans);
            }
            else if (open == 0)
            {
                solve(open, close - 1, n, output + ')', ans);
            }
            else if (close > open)
            {
                solve(open, close - 1, n, output + ')', ans);
                solve(open - 1, close, n, output + '(', ans);
            }
        }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        int open = n;
        int close = n;
        string output="";
        solve(open, close, n, output, ans);
        return ans;
    }
};