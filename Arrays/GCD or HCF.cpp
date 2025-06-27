/*You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.
A prime number is a number which has no divisors except 1 and itself.
Examples:
Input: n = 5
Output: true
Explanation: The only divisors of 5 are 1 and 5 , So the number 5 is prime.
Input: n = 8
Output: false
Explanation: The divisors of 8 are 1, 2, 4, 8, thus it is not a prime number*/


class Solution {
public:
    int GCD(int n1,int n2) {
        while(n1>0 && n2>0){
            if(n1>n2)  n1=n1%n2;
            else{
                n2=n2%n1;
            }
        
        }
        if(n1==0){
            return n2;
        }else{
            return n1;
        }

    }
};
