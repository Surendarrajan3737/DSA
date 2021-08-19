class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size() == 0) return -1;
        queue<pair<int,int>> q;
        int n = grid.size(),m = grid[0].size(),cnt=0,tot=0,days=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] != 0)
                    tot++;
            }
        }
        
//      Used to give the all four directions "DLRU"
        int dx[4] = {1,0,0,-1};
        int dy[4] = {0,-1,1,0};
        
        
        while(!q.empty()){
            int k = q.size();
            cnt += k;
            while(k--){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
            
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1 ) continue;
                    grid[nx][ny] = 2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) days++;
        }
        if(cnt == tot) return days;
        return -1;
    }
};
