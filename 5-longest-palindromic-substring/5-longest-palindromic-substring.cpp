class Solution
{
    public:
        string longestPalindrome(string s)
        {
            string ans = "";
            for (int i = 0; i < s.size(); i++)
            {
                int l = i;
                int r = i;
                while (l >= 0 && r < s.size() && s[l] == s[r])
                {
                    if (ans.size() < r - l + 1)
                        ans = s.substr(l, r - l + 1);
                    l -= 1;
                    r += 1;
                }
                l = i;
                r = i + 1;
                while (l >= 0 && r < s.size() && s[l] == s[r])
                {
                    if (ans.size() < r - l + 1)
                        ans = s.substr(l, r - l + 1);
                    l -= 1;
                    r += 1;
                }
            }
            return ans;
        }
};