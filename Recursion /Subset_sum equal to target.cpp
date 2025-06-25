/*given an array arr of n integers and an integer target, determine if there is a subset of the given array with a sum equal to the given target.
Examples:
Input: arr = [1, 2, 7, 3], target = 6
Output: True
Explanation: There is a subset (1, 2, 3) with sum 6.
Input: arr = [2, 3, 5], target = 6
Output: False
Explanation: There is no subset with sum 6.
Input: arr = [7, 54, 4, 12, 15, 5], target = 9
True
False
Submit*/

class Solution{
    public:
    void fun(int ind, int sum, vector<int>&arr, int target, vector<int>& sumsubset){
        if(ind==arr.size()){
            sumsubset.push_back(sum);
            return;
        }
        fun(ind+1, sum+arr[ind], arr, target,sumsubset );
        fun(ind+1, sum, arr, target,sumsubset );
    }

public:
    bool isSubsetSum(vector<int>arr, int target){
        vector<int>sumsubset;
        fun(0,0, arr, target,sumsubset );
        for(int s: sumsubset){
            if(s==target){
                return true;
            }

        }
        return false;
    }
};
