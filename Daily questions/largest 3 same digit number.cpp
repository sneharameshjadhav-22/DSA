/*You are given a string num representing a large integer. An integer is good if it meets the following conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
 

Example 1:

Input: num = "6777133339"
Output: "777"
Explanation: There are two distinct good integers: "777" and "333".
"777" is the largest, so we return "777".
Example 2:

Input: num = "2300019"
Output: "000"
Explanation: "000" is the only good integer.
Example 3:

Input: num = "42352338"
Output: ""
Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.*/







class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int l=0;
        int r=1;
        int maxi=-1;
        int cnt=1;
        
        while(r<n){
            while(num[l]==num[r] && r<n){
                cnt++;
                r++;
            }
            if(cnt>=3){
                string s="";
                s+=num[r-1];
                s+=num[r-1];
                s+=num[r-1];
                maxi=max(maxi, stoi(s));
            }
            cnt=1;
            l=r;
            r++;
        }
        if(maxi==0){
            return "000";
        }
        if(maxi==-1){
            return "";
        }
        return to_string(maxi);
    }    
      
};
