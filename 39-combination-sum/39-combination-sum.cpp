class Solution {
public:
    void solve (int ind,vector<int>ip,vector<int>op,vector<vector<int>>&ans,int k,int sum)
    {
        if(ind>=ip.size()||sum>k)
        {
            return;
        }
        
        if(sum==k)
        {
            ans.push_back(op);
            return;
            
        }
 
           
           
        solve(ind+1,ip,op,ans,k,sum); 
        
       op.push_back(ip[ind]);
        sum+=ip[ind];
       solve(ind,ip,op,ans,k,sum);
     
    }
    
    vector<vector<int>> combinationSum(vector<int>& ip, int target) {
         
        vector<vector<int>>ans;
        vector<int>op;
        int sum=0;
        solve(0,ip,op,ans,target,sum);
        return ans;
    }
};