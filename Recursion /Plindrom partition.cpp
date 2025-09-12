/*Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.*/


class Solution {
public:
    bool isplin(string & s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void fun(  int i, string & r,   vector<string> &arr,  vector<vector<string>>&res){
        int n=r.size();
        int start;
        int end;
        
        if(i==n){
            res.push_back(arr);
            return;
        }
        for(int j=i; j<n; j++){
            start=i;
            end=j;
            if(isplin(r, start, end)){
                arr.push_back(r.substr(i, j-i+1));
                fun(j+1, r, arr, res);
                arr.pop_back();

            }
        }   
    }
    vector<vector<string>> partition(string s) {
        vector<string>arr;
        vector<vector<string>>res;
        fun(0, s, arr, res); 
        return res;   
    }
};


