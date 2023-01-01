class Solution
{
    public:
        bool wordPattern(string pattern, string s)
        {
            int spaces = 0;
            for (auto it: s)
            {
                if (it == ' ')
                    spaces++;
            }
            if (spaces != pattern.size() - 1)
                return false;

            string ans = "";
            unordered_map<string, char> mp;
            unordered_set<char> st;
            int j = 0;
            for (int i = 0; i < pattern.size(); i++)
            {
                string temp = "";
                while (j < s.size() && s[j] != ' ')
                {
                    temp += s[j++];
                }
                j++;
                if (mp.find(temp) != mp.end())
                {
                    ans += mp[temp];
                }
                else
                {
                    if (st.find(pattern[i]) != st.end())
                    {
                        return false;
                    }
                    else
                    {
                        mp[temp] = pattern[i];
                        ans += pattern[i];
                        st.insert(pattern[i]);
                    }
                }
            }
            if (ans == pattern)
                return true;
            return false;
        }
};