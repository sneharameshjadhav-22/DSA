/*Given an array arr[], its starting position l and its ending position r. Sort the array using the merge sort algorithm.
Examples:
Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Input: arr[] = [1, 3 , 2]
Output: [1, 2, 3]*/


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
  
  
    void mergeSort(vector<int>& arr, int l, int r) {
        
        mg(arr, l,r);
        // code here
        
    }
};
