class Solution
{
    public:
        unordered_map<string, int> mp;

   	// checking if one string is a subsequence of another
    bool isSubsequence(string &s, string &t)
    {
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = t.size();
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++,
                j++;
            }
            else
            {
                j++;
            }
        }
        return i == n;
    }
    int numMatchingSubseq(string s, vector<string> &words)
    {
        int cnt = 0;
        for (auto word: words)
        {
           	// if answer for some word is already computed then just use it
            if (mp.find(word) != mp.end()) cnt += mp[word];
            else
            {
                mp[word] = isSubsequence(word, s);
                cnt += mp[word];
            }
        }
        return cnt;
    }
};