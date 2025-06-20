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
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char, int>map;
        int left=0, right=0;
        int len=0;
        while(right<n){
            char ch=s[right];
            if(map.find(ch)!=map.end()){
                left=max(map[ch]+1, left);
            }
            map[ch]=right;
            
            len=max(len, right-left+1);
            right++;
        }
        return len;
        
    }
};
 
