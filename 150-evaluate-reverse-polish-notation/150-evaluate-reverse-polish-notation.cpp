class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        if(n==1) return stoi(tokens[0]);
       if(n<2) return 0;
        stack<int> st;
        st.push(stoi(tokens[0]));
        st.push(stoi(tokens[1]));
            int ans2=0,ans1=0;
    for(int i=2;i<n;i++){
        if(tokens[i]=="+"){
            ans2=st.top();
            st.pop();
            ans1=st.top();
            st.pop();
            ans1=ans1+ans2;
            st.push(ans1);
        }
        else  if(tokens[i]=="-"){
            ans2=st.top();
            st.pop();
            ans1=st.top();
            st.pop();
            ans1=ans1-ans2;
            st.push(ans1);
        }
        else  if(tokens[i]=="*"){
            ans2=st.top();
            st.pop();
            ans1=st.top();
            st.pop();
            ans1=ans1*ans2;
            st.push(ans1);
        }
        else  if(tokens[i]=="/"){
            ans2=st.top();
            st.pop();
            ans1=st.top();
            st.pop();
            ans1=ans1/ans2;
            st.push(ans1);
        }
        else
            st.push(stoi(tokens[i]));
        
    }
        int ans=st.top();
        return ans;
    }
};