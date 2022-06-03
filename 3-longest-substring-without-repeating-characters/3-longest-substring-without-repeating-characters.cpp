class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            unordered_set<char> set;
            int length = s.size();
            int l = 0;
            int r = 0;
            int mx = 0;
            while (r < length)
            {
                if (set.count(s[r]) == 0)
                {
                    set.insert(s[r++]);
                    int t = set.size();
                    mx = max(t, mx);
                }
                else
                {
                    set.erase(s[l++]);
                }
            }
            return mx;
        }
};