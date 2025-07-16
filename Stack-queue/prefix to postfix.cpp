You are given a string that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.
Example:
Input: 
*-A/BC-/AKL
Output: 
ABC/-AK/L-*
Explanation: 
The above output is its valid postfix form.
Your Task:
Complete the function preToPost(string pre_exp), which takes a prefix string as input and returns its postfix form.



  // User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string>st;
        for(int i=pre_exp.size()-1; i>=0; i--){
            char c=pre_exp[i];
            
            if(isalnum(c)){
                st.push(string(1, c));
            }else{
                string op1=st.top(); st.pop();
                string op2=st.top(); st.pop();
                string res=op1+""+op2+""+c;
                st.push(res);
            }
        }
        return st.top();
        
        
    }
};

 
