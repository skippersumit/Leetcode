class Solution
{
    public:
        int romanToInt(string s)
        {
            int n = s.size();
            unordered_map<char, int> table = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (i == n - 1)
                {
                    sum += table[s[i]];
                }
                else
                {
                    if (table[s[i]] >= table[s[i + 1]])
                    {
                        sum += table[s[i]];
                    }
                    else
                    {
                        sum += table[s[i + 1]] - table[s[i]];
                        i = i + 1;
                    }
                }
            }
            return sum;
        }
};