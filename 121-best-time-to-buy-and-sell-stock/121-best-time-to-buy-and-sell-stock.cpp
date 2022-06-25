class Solution
{
    public:
        int maxProfit(vector<int> &prices)
        {
            int n = prices.size();
            vector<int> nextGrt(n);
            for (int i = n - 1; i >= 0; i--)
            {
                if (i == n - 1)
                    nextGrt[i] = prices[i];
                else
                    nextGrt[i] = max(nextGrt[i + 1], prices[i]);
            }
            int ans = INT_MIN;
            for (int i = 0; i < n; i++)
                ans = max(ans, nextGrt[i] - prices[i]);
            return ans < 0 ? 0 : ans;
        }
};