/*Given two binary strings a and b, return their sum as a binary string.

 
Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.*/



  class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        string binary(string a){
            while(a!=1){
                if(a%2==1){
                    res+='1';

                }
                a=a/2;
            }

        }
        reverse(res.begin(), res.end());
         string res1="";
        string binary( int b){
            while(b!=1){
                if(b%2==1){
                    res1+='1';

                }
                b=b/2;
            }

        }
        reverse(res1.begin(), res1.end());
        string ans=  res+res1;
        return ans;
    }
};
