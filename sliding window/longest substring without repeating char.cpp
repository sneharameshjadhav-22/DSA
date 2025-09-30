/*Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        int l=0;
        vector<int>last(256, -1);
        for(int i=0; i<n; i++){
            if(last[s[i]]>=l){
                l=last[s[i]]+1;
            }
            last[s[i]]=i;
            maxi=max(maxi, i-l+1);
            

        }
        return maxi;
       
        
    }
};


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char, int>mp;
        int l=0;
        int maxi=0;
        int r=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end() && mp[s[r]]>=l){
                l=mp[s[r]]+1;
            }
 
            mp[s[r]]=r;
            maxi=max(maxi, r-l+1);
            r++;

        }
        return maxi;
        
    }
};
