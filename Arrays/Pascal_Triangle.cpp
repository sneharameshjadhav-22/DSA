Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1; i<=numRows; i++){
            long long val=1;
            vector<int>ansrow;
            
            for(int col=1; col<=i; col++){
                ansrow.push_back(val);
                val=val*(i-col);
                val=val/(col);
                
            }
            
            ans.push_back(ansrow);
        }
        return ans;  
    }
};
