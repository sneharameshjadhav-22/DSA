/*Given two integers n and k, split the number n into exactly k positive integers such that the product of these integers is equal to n.

Return any one split in which the maximum difference between any two numbers is minimized. You may return the result in any order.

 /*
Example 1:
Input: n = 100, k = 2
Output: [10,10]
Explanation:
The split [10, 10] yields 10 * 10 = 100 and a max-min difference of 0, which is minimal.
Example 2:
Input: n = 44, k = 3

Output: [2,2,11]

Explanation:
Split [1, 1, 44] yields a difference of 43
Split [1, 2, 22] yields a difference of 21
Split [1, 4, 11] yields a difference of 10
Split [2, 2, 11] yields a difference of 9
Therefore, [2, 2, 11] is the optimal split with the smallest difference 9.
Constraints:

4 <= n <= 105
2 <= k <= 5
k is strictly less than the total number of positive divisors of n.

Note: Please do not copy the description during the contest to maintain the integrity of your submissions.*/



class Solution {
public:
    vector<int>res;
    int maxdiff=INT_MAX;
    void update(vector<int>curr){
        int maxi=0;
        int mini=INT_MAX;
        for(int e:curr){
            maxi=max(maxi, e);
            mini=min(mini, e);
            
        }
        if(maxdiff > (maxi-mini)){
            res=curr;
            maxdiff=maxi-mini;
        }
    }
    
    void fun(int n, int k , int factor, vector<int>curr){
        if(k==1){
            curr.push_back(n);
            update(curr);
            curr.pop_back();
            return ;      
        }
        for(int i=factor; i<=n; i++){
            if(n%i==0){
                curr.push_back(i);
                fun(n/i, k-1, i, curr);
                curr.pop_back();
            }
        }
        
    }
    vector<int> minDifference(int n, int k) {
        vector<int>curr;
        fun(n, k, 1, curr);
        return res;
        
        
        
    }
};
