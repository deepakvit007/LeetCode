class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         vector<vector<int>> ans;
        if(m*n!=original.size())
            return ans;
        
        vector<int> t;
        for(int k=0;k<original.size();k++)
        {
            t.push_back(original[k]);
            if(t.size()==n)
            {
                ans.push_back(t);
                t.clear();
            }
        }
        return ans;
    }
};