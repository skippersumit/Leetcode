class Solution {
private:
    int bfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        queue<pair<int,int>>q;
        int n = grid.size();
        
        q.push({i,j});
        vis[i][j] = 0;
        grid[i][j] = 2;
        
        vector<pair<int,int>> move = {
            {1,0},{1,1},{0,1},{-1,0},{-1,1},{-1,-1},{1,-1},{0,-1}
        };
        
        while(!q.empty()){
            pair<int,int>p = q.front(); q.pop();
            int cx = p.first, cy = p.second;
            
            for(int k=0;k<8;k++){
                int x = cx + move[k].first;
                int y = cy + move[k].second;
                
                if(x<0 or x>=n or y<0 or y>=n or grid[x][y] != 0)
                    continue;
                q.push({x,y});
                grid[x][y]=2;
                
                vis[x][y] = vis[cx][cy] + 1;
            }
        }
        return vis[n-1][n-1];
    }
public:
    const int INF = 1e9 + 9;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,INF));
        if(grid[0][0] == 1) return -1;
        
        int ans = bfs(0,0,grid,vis);
        
        if(ans == INF)
            return -1;
        
        return ans+1;
    }
};