/*Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10*/


class Solution {
public:
    void fun(vector<int>&curr, vector<int>&ans, set<vector<int>>&res, vector<bool>&used){
        int n=curr.size();
        if(ans.size()==n){
            res.insert(ans);
            return ;
        }
        for(int i=0; i<n; i++){
            if(used[i]){
                continue;
            }
            used[i]=true;
            ans.push_back(curr[i]);
            fun(curr, ans, res, used);
            ans.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        set<vector<int>>res;
        vector<bool>used(n, false);
        fun(nums, ans, res, used);
        return  vector<vector<int>>(res.begin(), res.end());
        
    }
};
