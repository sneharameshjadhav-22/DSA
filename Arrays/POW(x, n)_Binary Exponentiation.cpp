/*Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000
Start: x = 2.0, N = 5, ans = 1.0
N = 5 → odd →
ans = ans * x = 1.0 * 2.0 = 2.0
N = 4
N = 4 → even →
x = x * x = 2.0 * 2.0 = 4.0
N = 2

N = 2 → even →
x = 4.0 * 4.0 = 16.0
N = 1

N = 1 → odd →
ans = 2.0 * 16.0 = 32.0
N = 0

✅ Done! Final result: 2^5 = 32*/

class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        double ans=1.0;
        if(N<0){
            N= -1* N;
            x=1/x;
        }
        while(N>0){
            if(N%2==1){
                ans=ans*x;
                N=N-1;

            }else{
                x=x*x;
                N=N/2;
            }
        }
        return ans ;
        
        
    }
};
