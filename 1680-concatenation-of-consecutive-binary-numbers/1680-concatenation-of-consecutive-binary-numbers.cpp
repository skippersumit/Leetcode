class Solution
{
    public:
        int concatenatedBinary(int n)
        {
            long long mod = 1000000007;
            if (n == 1)
                return 1;

            long long val = concatenatedBinary(n - 1) *pow(2, ceil(log2(n + 1)));
            return (val + n) % mod;
        }
};