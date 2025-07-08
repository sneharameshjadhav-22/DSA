/*Given a sorted array arr with possibly some duplicates, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.
Examples:
Input: arr[] = [1, 3, 5, 5, 5, 5, 67, 123, 125], x = 5
Output: [2, 5]
Explanation: First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5
Input: arr[] = [1, 3, 5, 5, 5, 5, 7, 123, 125], x = 7
Output: [6, 6]
Explanation: First and last occurrence of 7 is at index 6*/



class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int l=lower_bound(arr.begin(), arr.end(), target) -arr.begin();
        int r=upper_bound(arr.begin(), arr.end(), target) -arr.begin();
        return r-l;
    }
};
