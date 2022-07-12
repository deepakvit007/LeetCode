// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
     void solve(int index,vector<int>nums, set<vector<int>>&subset,vector<int>out)
    {
        if(index>=nums.size())
        {
            sort(out.begin(),out.end());
            subset.insert(out);
            return;
        }
        
        solve(index+1,nums,subset,out);
        
        out.push_back(nums[index]);
        
        solve(index+1,nums,subset,out);
                      
     }
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> nums, int n)
    {
        vector<vector<int>>ans;
        set<vector<int>>subset;
        vector<int>out;
        solve(0,nums,subset,out);
        
        for(auto x:subset)
        {
            ans.push_back(x);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends