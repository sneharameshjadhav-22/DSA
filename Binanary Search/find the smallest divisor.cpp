/*283. Find the Smallest Divisor Given a Threshold
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.
Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44*/



 class Solution {
public:
    int sumof(vector<int> & nums, int div){
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=ceil((double) nums[i]  / (double) (div));

        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans=-1;
        int n=nums.size();
        if(n> threshold) return -1;
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        while(low<=high){
            int mid= (low+high)/2;
            if(sumof(nums, mid) <=threshold){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};
