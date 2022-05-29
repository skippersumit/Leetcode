class Solution
{
    public:
        bool check(string &a, string &b)
        {
            int i = 0, j = 0;
            while (i < a.length() && j < b.length())
            {
                if (a[i] < b[j]) i++;
                else if (a[i] > b[j]) j++;
                else return false;
            }
            return true;
        }

    int maxProduct(vector<string> &words)
    {
        int n = words.size(), res = 0;
        for (int i = 0; i < n; i++)
        {
            sort(begin(words[i]), end(words[i]));
            for (int j = i - 1; j >= 0; j--)
            {
                if (check(words[i], words[j]))
                {
                    int m = words[i].length() *words[j].length();
                    res = max(res, m);
                }
            }
        }
        return res;
    }
};