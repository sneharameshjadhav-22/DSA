/*The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int el;
        for(int i=0; i<n ; i++){
            if(count==0){
                count=1;
                el=nums[i];
            }
            else if(el==nums[i]){
                count++;
            }else{
                count--;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]==el){
                count++;
            }
            if(count>(n/2)){
                return el;
            }
            
        }
        return -1;
    }
};
