/*You are given a string S of size N that represents the prefix form of a valid mathematical expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are +, -, *, /, %, and ^.Convert it to its infix form.
Example 1;
Input: 
*-A/BC-/AKL
Output: 
((A-(B/C))*((A/K)-L))
Explanation: 
The above output is its valid infix form.
Your Task:
Your task is to complete the function string preToInfix(string pre_exp), which takes a prefix string as input and return its infix form.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Constraints:
3<=|S|<=104*/


// User function Template for C++

class Solution {
    bool isoperator(char c){
        return (c=='+'  || c=='*' || c=='-' || c=='/');
        
    }
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        stack<string>st;
        for(int i=pre_exp.size()-1; i>=0; i--){
            char c=pre_exp[i];
            if(isoperator(c)){
                string op1=st.top(); st.pop();
                string op2=st.top();  st.pop();
                string ex="("+ op1+ c+ op2+")";
                st.push(ex);
            }else{
                st.push(string(1, c));
                
            }
            
        }
        return st.top();
       
        
    }
};
