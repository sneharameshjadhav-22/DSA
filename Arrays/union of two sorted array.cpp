/*Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 3, 4, 5], b[] = [1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1], b[] = [2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.*/


class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        int n1=a.size();
        int n2=b.size();
        int i=0;
        int j=0;
        vector<int>unionarr;
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                if(unionarr.size()==0 || unionarr.back()!=a[i] ){
                    unionarr.push_back(a[i]);
                }
                i++;
                
            }
            else{
                if(unionarr.size()==0 || unionarr.back()!=b[j] ){
                    unionarr.push_back(b[j]);
                }
                j++;
                
            }
        }
        while(i<n1){
            if(unionarr.size()==0 || unionarr.back()!=a[i] ){
                    unionarr.push_back(a[i]);
                }
                i++;
            
        }
        while(j<n2){
            if(unionarr.size()==0 || unionarr.back()!=b[j] ){
                    unionarr.push_back(b[j]);
                }
                j++;
                
            
        }
        return unionarr;
        
        // return vector with correct order of elements
    }
};
