class Solution
{
    public:
        vector<int> dx={-1,0,0,1};
        vector<int> dy={0,-1,1,0};
    
        int dfs(int x, int y, vector<vector < int>> &grid, int r, int c, int &count)
        {

            grid[x][y] = 0;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == 1)
                {
                    count++;
                    dfs(nx, ny, grid, r, c, count);
                }
            }
            return count;
        }

    int maxAreaOfIsland(vector<vector < int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        int max_area = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    int count = 1;
                    max_area = max(max_area, dfs(i, j, grid, r, c, count));
                }
            }
        }

        return max_area;
    }
};