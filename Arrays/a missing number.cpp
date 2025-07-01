/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
Example 1:
Input: nums = [3,0,1]
Output: 2
Explanation:
n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:
Input: nums = [0,1]
Output: 2*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum= (n*(n+1)) / 2;
        int sum1=0;
        for(int i=0; i<n; i++){
            sum1=sum1+nums[i];
        }
        return sum-sum1;
        
    }
};


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xor1= 0;
        int xor2=0;
        for(int i=0; i<n; i++){
            xor2=xor2^nums[i];
            xor1=xor1 ^ i;
        }
        xor1= xor1 ^ n;
        return xor1 ^ xor2;
    }
};



class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n=arr.size()+1;
       long long sum=(n*1LL* (n+1)) /2;
       int sum1=0;
       for(int i=0; i<n-1; i++){
           sum1+=arr[i];
       }
       return sum-sum1;
    }
};

