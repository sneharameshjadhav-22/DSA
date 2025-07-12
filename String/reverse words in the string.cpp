/*given a string s, reverse the string without reversing its individual words. Words are separated by spaces.
Note: The string may contain leading or trailing spaces, or multiple spaces between two words. The returned string should only have a single space separating the words, and no extra spaces should be included.
Examples :
Input: s = " i like this program very much "
Output: "much very program this like i"
Explanation: After removing extra spaces and reversing the whole string (not individual words), the input string becomes "much very program this like i". 
Input: s = " pqr  mno "
Output: "mno pqr"
Explanation: After removing extra spaces and reversing the whole string, the input string becomes "mno pqr". 
Input: s = " a "
Output: "a"
Explanation: The input string contains only one word with extra spaces around it. After removing the extra spaces, the output is "a".*/


class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        int n=s.size();
        vector<string>words;
        int i=0;
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i>=n){
                break;
            }
            string w="";
            while(i<n && s[i]!=' '){
                w += s[i];
                i++;
                
            }
            words.push_back(w);
        }
        reverse(words.begin(), words.end());
        string result="";
        for(int j=0; j<words.size(); j++){
            result+=words[j];
            if(j!=words.size()-1){
                result+=' ';
                
            }
        }
        return result;
        
    }
};
