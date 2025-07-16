/*Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.

Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.
Examples :
Input: s = "a+b*(c^d-e)^(f+g*h)-i"
Output: abcd^e-fgh*+^*+i-
Explanation: After converting the infix expression into postfix expression, the resultant expression will be abcd^e-fgh*+^*+i-
Input: s = "A*(B+C)/D"
Output: ABC+*D/
Explanation: After converting the infix expression into postfix expression, the resultant expression will be ABC+*D/
Input: s = "(a+b)*(c+d)"
Output: ab+cd+**/



class Solution {
    int prec(char c){
        if(c=='^'){
            return 3;
        }
        else if(c=='/'  || c=='*') return 2;
        else if(c=='+'  || c=='-'){
            return 1;
        }else{
            return -1;
        }
    }
  public:
    string infixToPostfix(string& s) {
        // code here
        stack<char>st;
        string res;
        for(int i=0; i<s.length(); i++){
            char c=s[i];
            if(isalnum(c)){
                res+=c;
            }
            else if(c=='('){
                st.push('(');
            }
            else if(c==')'){
                while(st.top()!='('){
                    char r=st.top();
                    res+=r;
                    st.pop();
                }
                st.pop();
               
            }
            else{
               while((!st.empty()) && (prec(c)<=prec(st.top())) && (st.top()!='(') ){
                   char r=st.top();
                   res+=r;
                   st.pop();
               }
               st.push(c);
            }
            
            
        }
        while(!st.empty()){
            char r=st.top();
            res+=r;
            st.pop();
        }
        return res;
        
    }
};

