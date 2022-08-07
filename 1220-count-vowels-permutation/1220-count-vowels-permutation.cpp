class Solution
{
    public:
        int countVowelPermutation(int n)
        {
            long long a = 1, e = 1, i = 1, o = 1, u = 1;
            int mod = 1e9 + 7;
            for (int k = 1; k < n; k++)
            {
                long long a1 = (e + i + u) % mod;
                long long e1 = (a + i) % mod;
                long long i1 = (e + o) % mod;
                long long o1 = (i) % mod;
                long long u1 = (i + o) % mod;
                a = a1;
                e = e1;
                i = i1;
                o = o1;
                u = u1;
            }
            return (a + e + i + o + u) % mod;
        }
};