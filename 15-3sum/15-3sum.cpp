class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
         sort(arr.begin(),arr.end());
        set<vector<int>>dk;
        for(int i=0;i<arr.size();i++)
        {
                int start=i+1;
                int end=arr.size()-1;
                
                while(start<end)
                {
                    int sum=arr[i]+arr[start]+arr[end];
                    
                    if(sum<0)
                    {
                        start++;
                    }
                    else if(sum>0)
                    {
                        end--;
                    }
                    else
                    {
                        dk.insert({arr[i],arr[start],arr[end]});
                        start++;
                        end--;
                    }
                
            }
        }
    vector<vector<int>> ans( dk.begin() , dk.end()) ;
      
      return ans ;
    }
};