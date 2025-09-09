/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
] 
Constraints:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30*/


class Solution {
public:
    void fun(int i, vector<int>&arr, vector<int>&nums, vector<vector<int>> & res, int sum, int t ){
        int n=nums.size();
        if(sum>t){
            return;
        }
        if(sum==t){
            res.push_back(arr);
            return;
        }
        if(i>=n){
            return;
        }
        for(int index=i; index<n; index++){
            if(index>i && nums[index]==nums[index-1]){
                continue;
                
            }
            arr.push_back(nums[index]);
            fun(index+1, arr, nums, res, sum+nums[index], t);
            arr.pop_back();
            

        }
       
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(), candidates.end());
       
        vector<int>arr;
        vector<vector<int>>res;
        fun(0, arr, candidates, res, 0, target);
        return res;

        
    }
};
