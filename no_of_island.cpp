class Solution {
public:
    void dfs(int i,int j,int row,int col,vector<vector<char>>& grid){
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] != '1')
            return;
        
        grid[i][j] = '2';               // Doing this to avoid recheck of that same land
        
        dfs(i+1,j,row,col,grid);        //Down
        dfs(i,j-1,row,col,grid);        //Left
        dfs(i,j+1,row,col,grid);        //Right
        dfs(i-1,j,row,col,grid);        //Up
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        
        int col = grid[0].size();
        
        int cnt = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i,j,row,col,grid);
                }
                
            }
        }
        
        return cnt;
    }
};
