/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.*/
class Solution {
    private:
    void swap(vector<int>& arr1 ,vector<int>& arr2, int ind1, int ind2){
        if(arr1[ind1]>arr2[ind2]){
            std::swap(arr1[ind1], arr2[ind2]);
        }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len=m+n;
        int gap=(len/2) +(len%2);
        while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
                if(left<m && right>=m){
                    swap(nums1, nums2, left, right-m );
                }else if(left>=m){
                    swap(nums2, nums2, left-m, right-m);

                }else{
                    swap(nums1, nums1, left, right);

                }
                left++;
                right++;
            }
            if(gap==1)break;
            gap=(gap/2) + (gap%2);
        }
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        
    }
};


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0; i<n; i++){
            int val=nums2[i];
            bool ptrr=false;
            for(int j=0; j<m; j++){
                if(val <=nums1[j]){
                    nums1.insert(nums1.begin()+j, val);
                    nums1.pop_back();
                    ptrr=true;
                    m++;
                    break;
                }
            }
            if(!ptrr){
            nums1[m]=val;
            m++;

        }
        }
        
        
    }
};


