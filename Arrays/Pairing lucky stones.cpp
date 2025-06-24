/*Problem Statement
In a peaceful village, the wise sage decided to introduce a new challenge at the annual harvest festival. He handed out numbered stones to the villagers and told them the task: find pairs of stones such that each numbers were divisible by either of two special numbers, N and M.

The villagers quickly grouped the stones, checking which ones met the criteria. They worked together, carefully pairing up the stones that were divisible by either N or M, making sure no pair was repeated and a pair must contain different stone.

By the end of the day, they had discovered several unique pairs, and the sage was pleased with their effort and the count they got.
Input Format
The first line contains three space-separated integers P, N, and M, where P is the number of stones in the village and N and M are the special numbers used to identify lucky stones.

The second line contains P space-separated integers, each representing the number on a stone.
Output Format
Output a single integer representing the number of pairs the villagers got at the end of the day.
Constraints
1 ≤ P ≤ 10^3
1 ≤ N, M ≤ 10^5

1 ≤ Ai ≤ 10^5
duplicate numbers are treated as different as they are present on different stones.
Sample Testcase 0
Testcase Input
5 2 3
6 9 12 15 18
Testcase Output
10
Explanation
The valid pairs of stone, where the each number is divisible by either 2 or 3 are (6,9); (6,12); (6,15); (6,18); (9,12); (9,15); (9,18); (12,15); (12,18) and (15,18). The count is 10.

Sample Testcase 1
Testcase Input
4 4 4
2 5 5 8
Testcase Output
0*/


#include <iostream>
#include <vector>


int find_lucky_stone_pairs(int p, int n, int m, std::vector<int>& stones) {
    // Write your logic here.
    int count=0;
    for(int i=0; i<p; i++){
        bool valid_i=(stones[i]%n==0 || stones[i]%m==0 );
        if(!valid_i)  continue;

        for(int j=i+1; j<p; j++){
            bool valid_j=(stones[j]%n==0 || stones[j]%m==0);
            if(valid_j){
                count++;
            }

        }
    }
    return count;
    return 0;
}

int main() {
    int p, n, m;
    std::cin >> p >> n >> m;
    std::vector<int> stones(p);
    for (int i = 0; i < p; ++i) {
        std::cin >> stones[i];
    }
    int result = find_lucky_stone_pairs(p, n, m, stones);
    std::cout << result << std::endl;
    return 0;
}
