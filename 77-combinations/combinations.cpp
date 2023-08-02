class Solution {
public:

    void solve(int ind,int k,vector<int>&temp,vector<vector<int>>&ans,int n)
    {
        if(k == 0)
        {
            ans.push_back(temp);
            return;
        }

        //if(ind >n )return ;
       for(int i = ind;i<=n;i++)
       {

       
        temp.push_back(i);
        solve(i+1,k - 1,temp,ans,n);
        temp.pop_back();
       }
       // solve(ind+1,k,temp,ans,n);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(1,k,temp,ans,n);
        return ans;  
    }
};