/*Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.
Examples:
Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.
Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.
Input: s = "aabbccc"
Output: -1
Explanation: All the characters in the given string are repeating.*/



class Solution {
  public:
    char nonRepeatingChar(string &s) {
        // Your code here
        
        unordered_map<char, int>count;
        for(char c: s){
            count[c]++;
           
        }
        for(char c: s){
            if(count[c]==1){
                return c;
            }
        }
        
        return '$';
        
    }
};
