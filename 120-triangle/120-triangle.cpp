class Solution
{
    public:
        vector<vector < int>> bo = vector<vector < int>> (200, vector<int> (200, -1));
    int minimumTotal(vector<vector < int>> &triangle)
    {
        int ans = INT_MAX;
        for (int i = 0; i < triangle.size(); i++)
        {
            ans = min(solve(triangle, triangle.size(), i), ans);
        }
        return ans;
    }

    int solve(vector<vector < int>> &tri, int row, int n)
    {
        if (bo[row][n] != -1) return bo[row][n];

        if (row == 1)
        {
            return tri[0][0];
        }

        if (n == 0)
        {
            bo[row][0] = solve(tri, row - 1, n) + tri[row - 1][n];
            return bo[row][0];
        }
        else if (n == tri[row - 1].size() - 1)
        {
            bo[row][n] = solve(tri, row - 1, n - 1) + tri[row - 1][n];
            return bo[row][n];
        }

        bo[row][n] = min(solve(tri, row - 1, n) + tri[row - 1][n], solve(tri, row - 1, n - 1) + tri[row - 1][n]);
        return bo[row][n];
    }
};