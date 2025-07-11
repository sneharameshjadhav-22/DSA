/*you are given 2 numbers n and m, the task is to find n√m (nth root of m). If the root is not integer then returns -1.

Examples :

Input: n = 2, m = 9
Output: 3
Explanation: 32 = 9
Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.
Input: n = 1, m = 14
Output: 14*/


class Solution {
  public:
    int f(int mid, int n){
       long long ans=1;
       for(int i=0; i<n; i++){
           ans*=mid;
           
       }
       return ans;
        
    }
    
    int nthRoot(int n, int m) {
        
        // Code here.
       
       int low=1;
       int high=m;
       while(low<=high){
           int mid=(low+high)/2;
           if(f(mid, n)==m){
               return mid;
           }
           else if(f(mid, n)< m){
               low=mid+1;
           }else{
               high=mid-1;
           }
       }
       return -1;
        
    }
};
