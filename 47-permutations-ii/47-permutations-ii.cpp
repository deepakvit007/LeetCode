class Solution {
public:
  
    void solve(int index,vector<int>ip,set<vector<int>>&ans)
    {
        if(index>=ip.size())
        {
            ans.insert(ip);
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
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      
        vector<vector<int>>ans2;
        set<vector<int>>ans;
        vector<int>op;
        solve(0,nums,ans);
        for(auto s:ans)
        {
            ans2.push_back(s);
        }
        return ans2;   
    }
};