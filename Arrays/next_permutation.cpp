A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            reverse(nums.begin(), nums.end());
            return ;
        }
        for(int i=n-1; i>ind; i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
                
            }
        }
        reverse(nums.begin() +ind+1,nums.end());
        return ;

        
    }
};
