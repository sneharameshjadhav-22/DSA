/*Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= s.length*/

class Solution {
public:
    bool isv(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            return true;
        }else{
            return false;
        }
    }
    int maxVowels(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int len=0;
        int maxi=0;
        int count=0;
        while(r<n){
            if(isv(s[r])){
                count++;
            }
            len=r-l+1;
            while(len>k){
                if(isv(s[l])){
                    count--;
                }
                l++;
                len=r-l+1;
            }
            if(len==k){
                maxi=max(maxi, count);

                
            }
            r++;
            

        }
        return maxi;
        
    }
};
 
