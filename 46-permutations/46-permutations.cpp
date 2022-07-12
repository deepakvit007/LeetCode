class Solution {
public:
    
    void solve(int index,vector<int>ip,vector<vector<int>> &ans)
    {
        if(index>=ip.size())
        {
            ans.push_back(ip);
            return;
        }
        
      for(int i=index;i<ip.size();i++)
      {
          swap(ip[index],ip[i]);
          solve(index+1,ip,ans);
          //backtrack
          swap(ip[index],ip[i]);
      }
        
        
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        vector<int>op;
        solve(0,nums,ans);
        return ans;
    }
};