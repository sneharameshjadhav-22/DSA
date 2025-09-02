/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
Example 1:
Input: nums = [2,2,1]
Output: 1
Example 2:
Input: nums = [4,1,2,1,2]
Output: 4
Example 3:
Input: nums = [1]
Output: 1*/


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n =nums.size();
        int xorr= 0;
        for(int i=0; i<n; i++){
            xorr =xorr ^ nums[i];
        }
        return xorr;
        
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int, int >mp;
        for(int num : nums){
           mp[num]++;
        }
        for(auto it : mp){
            if(it.second < 2){
                return it.first;
            }


            
        }
        return -1;
        
    }
};
 
