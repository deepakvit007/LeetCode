class Solution
{
public:
    // Recursive approach with memoization
    int solve(int i, int j, string text1, string text2, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0) return text1[i] == text2[j]; // Base case for single characters
        if (i < 0 || j < 0) return 0; // Out of bounds
        if (dp[i][j] != -1) return dp[i][j]; // Memoization check

        if (text1[i] == text2[j]) // Matching characters, add 1 to the result
            return dp[i][j] = 1 + solve(i - 1, j - 1, text1, text2, dp);
        else
            return dp[i][j] = max(solve(i, j - 1, text1, text2, dp), solve(i - 1, j, text1, text2, dp)); // Max of two possible options
    }

    // Tabulation (bottom-up) approach
    int tab(int n, int m, string text1, string text2, vector<vector<int>> &dp)
    {
        // // Initialize first row and first column for base cases
        // for (int i = 0; i <= n; i++) dp[i][0] = 0;  // If text2 is empty
        // for (int j = 0; j <= m; j++) dp[0][j] = 0;  // If text1 is empty

        // Fill the dp table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1]) // If characters match, add 1 to the diagonal value
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else // Otherwise, take the max of left and top cell
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[n][m]; // The last cell will contain the LCS length
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // Create DP table initialized to 0
        return tab(n, m, text1, text2, dp); // Call tabulation function
    }
};
