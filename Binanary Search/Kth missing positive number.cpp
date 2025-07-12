/*Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array
Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
Example 2:

Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.*/
 




class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int count=0;
        int curr=0;
        unordered_set<int>s(arr.begin(), arr.end());
        while(count<k){
            curr++;
            if(s.find(curr)==s.end()){
                count++;
            }
        }
        return curr;
        
    }
};


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=n-1;
        int result=n+k;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>mid+k){
                result=mid+k;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
      
    }
};
