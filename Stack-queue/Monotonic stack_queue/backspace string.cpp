/*Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".*/


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
                
            }else{
                st.push(s[i]);
            }
            

        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        stack<char>st1;
        for(int i=0; i<m; i++){
            if(t[i]=='#'){
                if(!st1.empty()){
                    st1.pop();
                }
                
            }
            else{
                st1.push(t[i]);
            }
            

        }
        string res="";
        while(!st1.empty()){
            res+=st1.top();
            st1.pop();
        }
        if(ans==res){
            return true;
        }
        else{
            return false;
        }
        
    }
};
