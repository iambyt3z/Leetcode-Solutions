class Solution {
public:
    bool isValid(string s){
        int len = s.length();
        if(len%2) return false;
        
        stack<char> st;
        for(int i=0; i<len; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            
            else{
                if(s[i] == ')'){
                    if(!st.size()) return false;
                    
                    if(st.top() == '(')
                        st.pop();

                    else return false;
                }
                
                else if(s[i] == '}'){
                    if(!st.size()) return false;
                    
                    if(st.top() == '{')
                        st.pop();
                    
                    else return false;
                }
                
                else if(s[i] == ']'){
                    if(!st.size()) return false;
                    
                    if(st.top() == '[')
                        st.pop();

                    
                    else return false;
                }
            }
            
            if(i==len-1 && st.size()) return false;
        }
        
        return true;
    }
};