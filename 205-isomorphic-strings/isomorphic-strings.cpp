class Solution {
public:
    bool isIsomorphic(string s, string t) {
       
        char str1[127]={0};
        char str2[127]={0};
        
        for(int i=0;i<s.size();i++)
        {
            if(str1[s[i]]!=str2[t[i]])return false;
            
            str1[s[i]]=str2[t[i]]=i+1;
                
                
        }
        return true;
        
    }
};