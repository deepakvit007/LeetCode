class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        set<vector<int>>dk;
        long long halfsum=0;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int start=j+1;
                int end=arr.size()-1;
                
                 halfsum=(long long)k-arr[i]-arr[j];
                
                while(start<end)
                {
                    int sum=arr[start]+arr[end];
                    
                    if(sum<halfsum)
                    {
                        start++;
                    }
                    else if(sum>halfsum)
                    {
                        end--;
                    }
                    else
                    {
                        dk.insert({arr[i],arr[j],arr[start],arr[end]});
                        start++;
                        end--;
                    }
                }
            
                
            }
        }
    vector<vector<int>> ans( dk.begin() , dk.end()) ;
      
      return ans ;
    }
};