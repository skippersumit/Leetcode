class Solution
{
    public:
        int solver(string word1, string word2, int m, int n, vector<vector < int>> &dp)
        {
            if (m == 0 or n == 0) return 0;
            if (dp[m][n] != -1) return dp[m][n];

            if (word1[m - 1] == word2[n - 1])
            {
                return dp[m][n] = 1 + solver(word1, word2, m - 1, n - 1, dp);
            }
            else
            {
                return dp[m][n] = max(solver(word1, word2, m - 1, n, dp), solver(word1, word2, m, n - 1, dp));
            }
        }
    int minDistance(string word1, string word2)
    {
        int m = word1.length(), n = word2.length();
        vector<vector < int>> dp(m + 1, vector<int> (n + 1, -1));
        int lcs = solver(word1, word2, word1.length(), word2.length(), dp);

        return (m - lcs) + (n - lcs);
    }
};