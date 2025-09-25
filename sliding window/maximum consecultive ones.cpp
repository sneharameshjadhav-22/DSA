/*Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
Example 2:

Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
0 <= k <= nums.length*/


class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int zero=0;
        int len=0;
        int l=0;
        int r=0;
        while(r<n){
            if(nums[r]==0){
                zero++;

            }
            if(zero>k){
                if(nums[l]==0){
                    zero--;
                   
                }
                l++;
            }
            if(zero<=k){
                len=r-l+1;
                maxi=max(maxi, len);

            }
            r++;
        }
        return maxi;
        
    }
};
