/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:
Input: s = "leetcode"
Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.*/


class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        map<char, int>fre;
        for(char c: s){
            fre[c]++;
        }
        for(int i=0; i<n; i++){
            if(fre[s[i]]==1){
                return i;
                break;

            }
        }
        return -1;
       

        
    }
};



class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        queue<int>q;
        vector<int>fre(26, 0);
        for(int i=0; i<n; i++){
            char c =s[i];
            fre[c-'a']++;
            q.push(i);
            while(!q.empty() && fre[s[q.front()]-'a']>1){
                q.pop();
            }

        }
        if(q.empty()){
            return -1;
        }else{
            return q.front();
        }
       

        
    }
};
