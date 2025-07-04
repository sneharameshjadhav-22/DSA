/*Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.
  */
 class Solution {
public:
     void merge(vector<int>& arr, int low, int mid,int  high){
        int l=low;
        int r=mid+1;
        vector<int>temp;
        while(l<=mid && r<=high){
            if(arr[l]<=arr[r]){
                temp.push_back(arr[l]);
                l++;
                
                
            }
            else{
                temp.push_back(arr[r]);
                r++;
            }
        }
        while(l<=mid){
            temp.push_back(arr[l]);
            l++;
        }
        while(r<=high){
            temp.push_back(arr[r]);
            r++;
        }
        for(int i=low ; i<=high; i++){
            arr[i]=temp[i-low];
        }
        
    }
    void mg(vector<int> & arr , int low, int high){
        if(low>=high) return;
        int mid=(low+high)/2;
        mg(arr, low, mid);
        
        
        
        mg(arr, mid+1, high);
        merge(arr, low, mid, high);
        
        
    }
    vector<int> sortArray(vector<int>& nums) {
        mg(nums, 0, nums.size()-1);
        return nums;
           
    }
};
