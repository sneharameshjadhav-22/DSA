/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]*/

class Solution {
public:
    void fun( vector<int>& curr, vector<int>& ans, vector<bool>&used,  vector<vector<int>>& res){
        int n=curr.size();
        if(ans.size()==n){
            res.push_back(ans);
            return ;
        }
        for(int i=0; i<n; i++){
            if(used[i]==true){
                continue;
            }
            used[i]=true;
            ans.push_back(curr[i]);
            fun(curr, ans, used, res);
            ans.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        vector<vector<int>>res;
        vector<bool>used(n, false);
        fun( nums, ans, used,  res);
        return res;


        
    }
};
