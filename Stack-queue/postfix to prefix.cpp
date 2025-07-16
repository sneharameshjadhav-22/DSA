/*You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.
Example 1:
Input: 
ABC/-AK/L-*
Output: 
*-A/BC-/AKL
Explanation: 
The above output is its valid prefix form.
Example 2:
Input: 
ab+
Output: 
+ab
Explanation: 
The above output is its valid prefix form.
Your Task:
Complete the function string postToPre(string post_exp), which takes a postfix string as input and returns its prefix form.
Expected Time Complexity: O(post_exp.length()).
Expected Auxiliary Space: O(post_exp.length()).
Constraints:
3<=post_exp.length()<=16000*/


// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string>st;
        for(int i=0; i<post_exp.size(); i++){
            char s=post_exp[i];
            if(isalnum(s)){
                st.push(string(1, s));
            }else{
                string op1=st.top(); st.pop();
                string op2=st.top(); st.pop();
                string res=s+op2+op1;
                st.push(res);
            }
        }
        return st.top();
    }
};A
