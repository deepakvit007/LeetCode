class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string>ans;
        int size=target.size();
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(size>0)
            {
                if(target[k]==i)
                {ans.push_back("Push");
                 size--;
                 k++;
                }
                else
                {   ans.push_back("Push");
                    ans.push_back("Pop");
                }
              
            }
                                  
        }
        return ans;
    }
};