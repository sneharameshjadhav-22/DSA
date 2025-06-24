/*Given an array of integers, determine if it exhibits a continuous mountain and valley pattern.
A continuous mountain and valley pattern means that the array elements strictly alternate between increasing and decreasing. That is:
Either a[0] < a[1] > a[2] < a[3] > a[4] ..., or
a[0] > a[1] < a[2] > a[3] < a[4] ....
Note:
If the array has only one element, return 1.
Input Format
The first line contains an integer n, the number of elements in the array.
The second line contains n space-separated integers.
Output Format
Print 1 if the array follows the continuous mountain and valley pattern, otherwise print 0.
Constraints
1 <= n <= 4 *10^3
0 <=elements  <= 10^4
Sample Testcase 0
Testcase Input
5
1 2 3 2 1
Testcase Output
0
Explanation
1 -> 2 -> 3 -> 2 -> 1
As 1 to 3 is increasing, that means values consistently do not alternate between increasing and decreasing. So the answer is 0.
Sample Testcase 1
Testcase Input
5
1 2 1 2 1
Testcase Output
1
Explanation
1 -> 2 -> 1 -> 2 -> 1
As values consistently alternate between increasing and decreasing. So the answer is 1*/



#include <iostream>
#include <vector>
using namespace std;

int isMountainValleyPattern(const std::vector<int>& arr) {

    // Implement your logic here
    int n=arr.size();
    if(n==1) return 1;
    if(arr[0]==arr[1]) return 0;
    bool isIncreasing=arr[0]<arr[1];
    for(int i=1; i<n-1; i++){
        if(arr[i]==arr[i+1]) return 0;
        if(isIncreasing){
            if(arr[i]<=arr[i+1]) return 0;
        }else{
            if(arr[i]>=arr[i+1]) return 0;
        }
        isIncreasing=!isIncreasing;
    }
    return 1;


    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    int result = isMountainValleyPattern(arr);
    std::cout << result << std::endl;
    return 0;
}
