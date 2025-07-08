/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:
Input: nums = [], target = 0
Output: [-1,-1]*/
class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
        int n=nums.size();
        int ans=n;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high) /2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;

            }else{
                low=mid+1;
            }    
        }
        return ans;
    }
    int upperbound(vector<int>& nums, int target){
        int n=nums.size();
        int ans=n;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high) /2;
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;

            }else{
                low=mid+1;
            }  
        }
        return ans;

    
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerbound(nums,target);
        if(lb==n || nums[lb]!=target)  return {-1, -1};
        return {lb , upperbound(nums, target)-1};     
    }
};





class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int first=-1;
        int last=-1;
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                if(first==-1)  first=i;
                last= i;
            }
        }
        return {first, last};
        
    }
};



class Solution {
public:
    int lowerbound(vector<int>& nums, int target){
        int n=nums.size();
        int first=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high) /2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;

            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return first;
    }
    int upperbound(vector<int>& nums, int target){
        int n=nums.size();
        int last=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high) /2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;

            }else if( nums[mid]< target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return last;

    
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerbound(nums,target);
        int up=upperbound(nums, target);
        return {lb, up};
    }
};
