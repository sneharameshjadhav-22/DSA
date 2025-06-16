/*Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int sum=0; 
        int left=0;
        int minlen=INT_MAX;
        for(int right=0; right<n; right++){
            sum+=nums[right];
            while(sum>=target){
                minlen=min(minlen, right-left+1);
                sum-=nums[left];
                left++;
            }
        }
        if(minlen==INT_MAX){
            return 0;
        }else{
            return minlen;
        }

    }
};
