/*Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.*/

class Solution {
public:
    void  fun(int i, vector<int>& arr, vector<int>& num, vector<vector<int>>& res){
        int n=num.size();
        if(i>=n){
            res.push_back(arr);
            

            return ;
        }
        arr.push_back(num[i]);
        fun(i+1, arr, num, res);
        arr.pop_back();
        fun(i+1, arr, num, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr;
         vector<vector<int>>res;
        fun(0, arr, nums , res);
        return res;

        
    }
};
