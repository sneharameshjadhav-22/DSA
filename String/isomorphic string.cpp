/*Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.
Example 3:
Input: s = "paper", t = "title"
Output: true*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m=s.size();
        int n=t.size();
        unordered_map<char, char>mapst;
        unordered_map<char, char>mapts;
        for(int i=0; i<m; i++){
            char c1=s[i];
            char c2=t[i];
            if((mapst.count(c1) && mapst[c1]!=c2 ) || (mapts.count(c2) && mapts[c2]!=c1)){
                return false;
            }
            mapst[c1]=c2;
            mapts[c2]=c1;

        }
        return true;

        
    }
};
