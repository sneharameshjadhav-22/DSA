/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"*/



class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>li(256, 0);
        for(int i=0; i<n; i++){
            li[s[i]]=i;
        } 
        vector<bool>seen(256, false);
        stack<char>st;
        for(int i=0; i<n; i++){
            char c=s[i];
            if(seen[c]) continue;
            while(!st.empty() && st.top()>c && li[st.top()]>i){
                seen[st.top()]=false;
                st.pop();
            }
            st.push(c);
            seen[c]=true;

        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;

       
        
    }
};
