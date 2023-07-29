class Solution {
public:
    void solve (int ind,vector<int>ip,vector<int>op,vector<vector<int>>&ans,int k,int sum)
    {
         if(sum==k)
        {
            ans.push_back(op);
            return;
            
        }
        if(ind>=ip.size()||sum>k)
        {
            return;
        }
        
       
      op.push_back(ip[ind]);
         sum+=ip[ind];
       solve(ind+1,ip,op,ans,k,sum);
        op.pop_back();    
        sum-=ip[ind];
           while(ind+1<ip.size() and ip[ind] == ip[ind+1])ind++;
        solve(ind+1,ip,op,ans,k,sum); 
        
      
    
    }
    
    vector<vector<int>> combinationSum2(vector<int>& ip, int target) {
         
        vector<vector<int>>ans2;
        vector<int>op;
        int sum=0;

        sort(ip.begin(),ip.end());
        solve(0,ip,op,ans2,target,sum);
        return ans2;
    }
};