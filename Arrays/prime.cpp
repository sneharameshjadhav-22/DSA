/*Problem Statement
King Luther has an army with N soldiers, each with an ID between 1 and N. The king wants to know how many soldiers in his army are "brave."

A soldier is considered "brave" if their ID has exactly two factors (or Divisors) and is not a perfect square.
Since King Luther is busy with his duties, he needs your help to count the number of "brave" soldiers in his army.

Your task is to count how many soldiers have "brave" IDs according to the criteria.
Input Format
The input contains only one integer N denoting the number of soldiers in the army.

Output Format
Print the count of brave soldiers in the army.
Constraints
1 ≤ N ≤ 10^6
Sample Testcase 0
Testcase Input
20
Testcase Output
8
Explanation
Only 8 numbers from 1 to 20 follow the brave criteria those are : 
2, 3, 5, 7, 11, 13, 17, 19.
It can be shown no number other than these follows the brave criteria.

Sample Testcase 1
Testcase Input
100
Testcase Output
25
Explanation
Only 25 numbers from 1 to 100 follow the brave criteria those are : 
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97. 
It can be shown no number other than these follows the brave criteria*/
#include <iostream>
#include<vector>
using namespace std;

int count_brave_soldiers(int n) {
    vector<bool>is_prime(n+1, true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2; i*i<=n; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=n; j+=i){
                is_prime[j]=false;
            }
        }
        
    }
    int count=0;
    for(int i=2; i<=n; i++){
        if(is_prime[i]){
            count++;
        }
    }
    return count;
    
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    int result = count_brave_soldiers(n);
    std::cout << result << std::endl;
    return 0;
}


class Solution {
public:
    bool isPrime(int n) {
        //your code goes here
        if(n<=1){
            return false;
        }
        int count=0;
        for(int i=1; i<=sqrt(n); i++){
            if(n%i==0){
                count++;
                if(n/i!=i){
                    count++;
                }
            }
        }
        if(count==2){
            return true;
        }else{
            return false;
        }
    }
};



