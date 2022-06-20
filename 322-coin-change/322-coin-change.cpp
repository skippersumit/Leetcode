class Solution
{
    public:
        int dp[13][10001];
    Solution()
    {
        memset(dp, -1, sizeof(dp));
    }
    int help(int i, vector<int> &coins, int amount)
    {
        if (i >= coins.size())
        {
            if (amount == 0) return 0;
            return 1e9;
        }
        if (dp[i][amount] != -1) return dp[i][amount];
        
        int total = INT_MAX;
        
        if (coins[i] <= amount)
            total = 1 + help(i, coins, amount - coins[i]);
        
        total = min(total, help(i + 1, coins, amount));
        
        return dp[i][amount] = total;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        sort(coins.begin(), coins.end());
        int ans = help(0, coins, amount);
        return (ans == 1e9) ? -1 : ans;
    }
};