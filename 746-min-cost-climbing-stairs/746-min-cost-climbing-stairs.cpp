class Solution
{
    public:
        vector<int> dp;
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        dp.assign(n + 1, -1);
        return min(minCostUtil(cost, n - 1), minCostUtil(cost, n - 2));
    }
    int minCostUtil(vector<int> &cost, int n)
    {
        if (n < 0) return 0;
        if (n == 0 or n == 1) return cost[n];

        if (dp[n] != -1) return dp[n];

        dp[n] = cost[n] + min(minCostUtil(cost, n - 1), minCostUtil(cost, n - 2));

        return dp[n];
    }
};