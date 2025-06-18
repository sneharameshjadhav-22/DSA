/*Given a 2D matrix matrix, handle multiple queries of the following type:
Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
Implement the NumMatrix class:
NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
You must design an algorithm where sumRegion works on O(1) time complexity.
Example 1:
Input
["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
Output
[null, 8, 11, 12]*/

class NumMatrix {
    vector<vector<int>>prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        prefix=vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                prefix[i][j]=matrix[i-1][j-1]
                             +prefix[i][j-1]
                             +prefix[i-1][j]
                             -prefix[i-1][j-1];  


            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return  prefix[row2+1][col2+1]
               -prefix[row1] [col2+1]
               -prefix[row2+1] [col1]
               +prefix[row1][col1];
        
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
