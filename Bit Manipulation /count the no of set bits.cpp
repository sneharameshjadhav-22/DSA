/*Given a positive integer n. Your task is to return the count of set bits.

Examples:

Input: n = 6
Output: 2
Explanation: Binary representation is '110', so the count of the set bit is 2.
Input: n = 8
Output: 1
Explanation: Binary representation is '1000', so the count of the set bit is 1.
Input: n = 3
Output: 2
Constraints:
1 ≤ n ≤ 109*/


  class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        while( n>0){
            if(n%2==1){
                count++;
            }
            n=n/2;
        }
        return count;
    }
};



class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
       int count=0;
       while(n!=0){
           n=n & (n-1);
           count++;
       }
       return count;
    }
};
