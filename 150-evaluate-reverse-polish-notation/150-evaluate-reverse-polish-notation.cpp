class Solution {
public:
   int evalRPN(vector<string>& tokens) {
      stack<int>s;
        
        for(const string& str : tokens){            
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                
                int right = s.top();
                s.pop();
                int left =  s.top(); 
                s.pop();
            
                if(str == "+")      s.push((left+right));
                else if(str == "-") s.push((left-right));
                else if(str == "*") s.push((left*right));
                else                s.push((left/right));
                
            } else 
                s.push(stoi(str)); // convert string to int
        }
        
        return s.top(); 
        
    }
};