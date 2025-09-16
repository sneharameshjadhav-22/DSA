/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:
Input: n = 1
Output: ["()"]
Constraints:

1 <= n <= 8*/



class Solution {
public:
    void fun(int open, int close, int n, string s,  vector<string> & res){
        if(s.size()==2*n){
            res.push_back(s);
            return;
        }
        if(open<n){
            fun(open+1, close, n, s+'(', res);
        }
        if(close<open){
            fun(open, close+1, n, s+')', res);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        fun(0,0, n, "", res);
        return res;
        
    }
};
