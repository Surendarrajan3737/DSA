class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();
        
        vector<vector<int>> dp(rows,vector<int> (col));
        
//         Tabulation Method : 
        
        dp[0][0] = grid[0][0];
        
//         for first row we  can reach them only through one way i.e from left to right
        for(int i=1;i<col;i++){
            dp[0][i] = dp[0][i-1] + grid[0][i]; 
        }
        
//         for first col we  can reach them only through one way i.e from right to left
        for(int j=1;j<rows;j++){
            dp[j][0] = dp[j-1][0] + grid[j][0];
        }
        
//      For rest of the rows and col
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<col;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[rows-1][col-1];
    }
};
