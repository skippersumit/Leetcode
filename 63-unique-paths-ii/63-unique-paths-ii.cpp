class Solution
{
    public:
        long long dp[101][101] = { 0 };

    int dfs(int i, int j, vector<vector < int>> &grid)
    {
        if (i == 0 && j == 0) return 1;
        if (i < 0 || j < 0 || grid[i][j] == 1) return 0;
        if (dp[i][j] != 0)
            return dp[i][j];
        int val = 0;
        val += dfs(i, j - 1, grid);
        val += dfs(i - 1, j, grid);
        return dp[i][j] += val;
    }
    int uniquePathsWithObstacles(vector<vector < int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;
        if (n == 1 && m == 1) return 1;
        dfs(n - 1, m - 1, grid);
        return dp[n - 1][m - 1];
    }
};