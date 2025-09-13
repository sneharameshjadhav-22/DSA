/*You are given a string s consisting of lowercase English letters ('a' to 'z').
Your task is to:
Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
Find the consonant (all other letters excluding vowels) with the maximum frequency.
Return the sum of the two frequencies.
Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.
The frequency of a letter x is the number of times it occurs in the string.
Example 1:
Input: s = "successes"
Output: 6

Explanation:

The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
The output is 2 + 4 = 6.
Example 2:

Input: s = "aeiaeia"

Output: 3

Explanation:

The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). The maximum frequency is 3.
There are no consonants in s. Hence, maximum consonant frequency = 0.
The output is 3 + 0 = 3.
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters only.*/
class Solution {
public:
    bool isvowel(char c){
        char d=tolower(c);
        if(d=='a' || d=='e' || d=='i' || d=='o' || d=='u'){
            return true;
        }
        return false;

    }
    int maxFreqSum(string s) {
        int count=0;
        int n=s.size();
        map<char, int>fre;
        for(int i=0; i<n; i++){
            if(isvowel(s[i])){
                fre[s[i]]++;
            }

        }
        int max=0;
        for(auto & p:fre){
            if(p.second>max){
                max=p.second;
            }
        }
        count+=max;
        map<char, int>freq;
         for(int i=0; i<n; i++){
            if(!isvowel(s[i])){
                freq[s[i]]++;
            }

        }
        int maxi=0;
        for(auto & p:freq){
            if(p.second>maxi){
                maxi=p.second;
            }
        }
        count+=maxi;
        return count;


        
        
    }
};

