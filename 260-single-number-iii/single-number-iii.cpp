class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        long long bitmask = 0;

        for(int num : nums)
        bitmask^=num;

        long long diff = bitmask & (-bitmask);

        long long x=0;

        for(int num:nums)
        {
            if((num&diff)!=0)
            x^=num;
        }
        long long y = bitmask^x;
        return vector<int>{(int)x,(int)y};
    }
};