class Solution
{
    public:
        void solve(vector<vector < int>> &mat, int row, int col, int m, int n)
        {
            vector<int> arr;
            int i = row, j = col;
            while (i < m && j < n)
            {
                arr.push_back(mat[i++][j++]);
            }
            sort(arr.begin(), arr.end());
            i = 0;
            while (row < m && col < n)
            {
                mat[row++][col++] = arr[i++];
            }
        }
    vector<vector < int>> diagonalSort(vector<vector < int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            solve(mat, i, 0, m, n);
        }
        for (int i = 1; i < n; i++)
        {
            solve(mat, 0, i, m, n);
        }
        return mat;
    }
};