class Solution {
public:
    void solve (int ind,vector<int>ip,vector<int>op,vector<vector<int>>&ans,int k,int sum,int s)
    { if(sum==k && op.size()==s)
         {
             ans.push_back(op);
              return;
         }
         if(sum==k && op.size()==s)
         {
             ans.push_back(op);
              return;
         }
        if(ind>=ip.size()||sum>k)
        {
           return;
        }
         
        solve(ind+1,ip,op,ans,k,sum,s);
        op.push_back(ip[ind]);
        sum+=ip[ind];
        solve(ind+1,ip,op,ans,k,sum,s);
            
         
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int>ip;
      for (int i=1;i<10;i++)ip.push_back(i);
        vector<vector<int>>ans;
        vector<int>op;
        solve(0,ip,op,ans,n,0,k);
    
        return ans;
    }
};