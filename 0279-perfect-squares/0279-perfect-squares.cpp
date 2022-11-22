vector<int> dp(10001,-1);
class Solution
{
    
    public:
    
        int solve(int n)
        {
            if (n == 0) return 0;

            int mnCount = INT_MAX;
            if(dp[n] != -1) return dp[n];
            for (int num = 1; num <= sqrt(n); num++)
            {
                int sqNum = num * num;
                int currCount = 1 + solve(n - sqNum);
                mnCount = min(mnCount, currCount);
            }
            return dp[n] = mnCount;
        }
    int numSquares(int n)
    {
        return solve(n);
    }
};