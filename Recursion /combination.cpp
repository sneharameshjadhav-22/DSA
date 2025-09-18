/*Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
 

Constraints:

1 <= n <= 20
1 <= k <= n*/


class Solution {
public:
    void fun( int curr, int n, int k, set<int>&ans, set<vector<int>>&res){
        if(ans.size()==k){
            res.insert(vector<int>(ans.begin(), ans.end()));
            return;
        }
        for(int i=curr; i<=n; i++){
            ans.insert(i);
            fun(i+1, n, k, ans, res);
            ans.erase(i);    
        }

    }
    vector<vector<int>> combine(int n, int k) {
        set<int>ans;
        set<vector<int>>res;
        fun( 1, n, k, ans, res);
        return vector<vector<int>>(res.begin(), res.end());
        
    }
};


class Solution {
public:
    void fun( int curr, int n, int k, vector<int>&ans, vector<vector<int>>&res){
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        for(int i=curr; i<=(n-(k-ans.size())+1); i++){
            ans.push_back(i);
            fun(i+1, n, k, ans, res);
            ans.pop_back();    
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        vector<vector<int>>res;
        fun( 1, n, k, ans, res);
        return res;
        
    }
};
