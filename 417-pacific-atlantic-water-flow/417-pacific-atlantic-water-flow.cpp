class Solution {
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
public:   
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		int n = heights.size();
        int m = heights[0].size();
        
        queue<vector<int>> pacific;
        queue<vector<int>> atlantic;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == 0) {
                    pacific.push({i, j});
                }
                
                if (i == n - 1 || j == m - 1) {
                    atlantic.push({i, j});
                } 
            }
        }
        
        vector<vector<int>> pacificReach = BFS(heights, pacific, n, m);
        vector<vector<int>> atlanticReach = BFS(heights, atlantic, n, m);
        
        vector<vector<int>> result;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacificReach[i][j] && atlanticReach[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
    vector<vector<int>> BFS(vector<vector<int>>& heights, queue<vector<int>> srcs, int n, int m) {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        while(!srcs.empty()) {
            int r = srcs.front()[0];
            int c = srcs.front()[1];
            srcs.pop();
                        
            if(visited[r][c] == 1) continue;
            visited[r][c] = 1;
                        
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc] || heights[r][c] > heights[nr][nc]) {
                    continue;
                }
            
                srcs.push({nr, nc});
            }
        }
        
        return visited;
    }
};
