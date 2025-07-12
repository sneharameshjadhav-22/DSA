/*Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(), strs.end());
        string  first=strs.front();
        string last=strs.back();
        int minlen=min(first.size(), last.size());
        int i=0;
        while(i<minlen && first[i]==last[i]){
            i++;
        }
        return first.substr(0, i);


        
    }
};
