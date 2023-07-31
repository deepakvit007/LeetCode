class Solution {
public:
    int help(int i,int j,string &s1, string &s2,  vector<vector<int>>&dp)
    {
       if(i <0 and j < 0)return 0;

       if(i < 0 )
       {
           return s2[j] + help(i,j-1,s1,s2,dp);
       }
       else if(j<0)
       {
           return s1[i] + help(i-1,j,s1,s2,dp);
       }
       
       if(dp[i][j]!=-1)return dp[i][j];
       if(s1[i] == s2[j])
       {
          return dp[i][j] = 0 + help(i-1,j-1,s1,s2,dp);
       }
       else
       {
       int delete1 = s1[i] + help(i-1,j,s1,s2,dp);
       int delete2 = s2[j] + help(i,j-1,s1,s2,dp);

       return dp[i][j] = min(delete1,delete2);

       }
       return 0;

    }
    int minimumDeleteSum(string s1, string s2) {
       int n = s1.size();
       int m = s2.size(); 
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return help(n-1,m-1,s1,s2,dp);
    }
};