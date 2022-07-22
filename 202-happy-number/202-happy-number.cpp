
class Solution {
public:
    bool isHappy(int n) {
        
        map<int,int>mp1;
        int sum=n;
        mp1[n]++;
        while(true){
            int t=n,te=0;
            for(char i:to_string(t)){
                int x=i-'0';
                te+=x*x;
            }
            if(te==1){
                return true;
            }
            
            mp1[te]++;
            
            if(mp1[te]>1){
                return false;
            }
            n=te;
        }
    }
};