/*givou are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.
Example:
Input:
ab*c+ 
Output: 
((a*b)+c)
Explanation: 
The above output is its valid infix form.
Your Task:
Complete the function string postToInfix(string post_exp), which takes a postfix string as input and returns its infix form.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).*/


// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        for(int i=0; i<exp.size(); i++){
            char c=exp[i];
            if(isalnum(c)){
                st.push(string(1, c));
            }else{
                string op1=st.top(); st.pop();
                string op2=st.top(); st.pop();
                string res="("+op2+c+op1+")";
                st.push(res);
            }
        }
        return st.top();
        
    }
};
