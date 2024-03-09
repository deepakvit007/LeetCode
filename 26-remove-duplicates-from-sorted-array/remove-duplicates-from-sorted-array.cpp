class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      map<int,int>mp;

       for(auto s : nums)
       {
          mp[s]++;
       } 
       int k=0;
       for(auto [key,val] : mp)
       {
           nums[k++] = key;
       }

       return k;
    }
};