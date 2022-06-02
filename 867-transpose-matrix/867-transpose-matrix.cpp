class Solution
{
    public:
        vector<vector < int>> transpose(vector<vector < int>> &matrix)
        {
            int n = matrix.size();
            int m = matrix[0].size();
            vector<vector < int>> mat(m, vector<int> (n, 0));

            for (int i = 0; i < n * m; i++)
                mat[i % m][i / m] = matrix[i / m][i % m];

            return mat;
        }
};