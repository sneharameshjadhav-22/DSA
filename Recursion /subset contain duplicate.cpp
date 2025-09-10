/*Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10*/



  class Solution {
public:
    void fun(int i, vector<int> & arr, vector<int> &nums,  set<vector<int>> &res  ){
        int n=nums.size();
        if(i>=n){
            res.insert(arr);
            return ;
        }
        arr.push_back(nums[i]);
        fun(i+1, arr, nums, res);
        arr.pop_back();
        fun(i+1, arr, nums, res);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
       
        vector<int>arr;
        set<vector<int>>res;
        fun(0, arr, nums, res);
        return vector<vector<int>>(res.begin(), res.end());


        
    }
};
