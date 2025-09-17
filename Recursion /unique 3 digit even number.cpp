/*You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
Example 1:

Input: digits = [1,2,3,4]

Output: 12

Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.
Example 2:
Input: digits = [0,2,2]
Output: 2
Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.
Example 3:
Input: digits = [6,6,6]
Output: 1
Explanation: Only 666 can be formed.

Example 4:

Input: digits = [1,3,5]

Output: 0

Explanation: No even 3-digit numbers can be formed.

 

Constraints:

3 <= digits.length <= 10*/


class Solution {
public:
    void fun(vector<int>& d,  vector<int>& v1, vector<bool>&v,   set<int>&seen ){
        int n=d.size();
        if(v1.size()==3){
            if(v1[2]%2==0){
                 int num = v1[0] * 100 + v1[1] * 10 + v1[2];
                 seen.insert(num);
            }
            return ;
        }
        for(int j=0; j<n; j++){
            if(v[j]){
                continue;
            }
            if(v1.empty() && d[j]==0){
                continue;
            }
            v[j]=true;
            v1.push_back(d[j]);
            fun(d, v1, v, seen);
            v1.pop_back();
            v[j]=false;
        }
        

    }
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int count=0;
        vector<int>v1;
        vector<bool>v(n, false);
        set<int>seen;
       
        fun(digits, v1, v, seen);
        return seen.size();
        
    }
};
0 <= digits[i] <= 9
