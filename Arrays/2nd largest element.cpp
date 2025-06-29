/*Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.
Note: The second largest element should not be equal to the largest element.
Examples:
Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.*/
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int largest=arr[0];
        int secondlargest=-1;
        for(int i=1; i<n; i++){
            if(arr[i]>largest ){
                secondlargest=largest;
                largest=arr[i];
            }else if(arr[i]<largest && arr[i]>secondlargest){
                secondlargest=arr[i];
            }
            
            
        }
        return secondlargest;
    }
};
