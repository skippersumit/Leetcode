class Solution
{
    public:
        string mostCommonWord(string paragraph, vector<string> &banned)
        {
            unordered_map<string, int> m;
            for (int i = 0; i < banned.size(); i++)
            {
                m[banned[i]]++;
            }
            int maxfreq = 0;
            string ans = "";
            unordered_map<string, int> mp;
            for (int i = 0; i < paragraph.length(); i++)
            {
                string word = "";
                while (i < paragraph.length() && isalpha(paragraph[i]))
                {
                    paragraph[i] = tolower(paragraph[i]);
                    word.push_back(paragraph[i]);
                    i++;
                }
                if (m.find(word) == m.end() && word != "")
                {
                    mp[word]++;
                    if (mp[word] > maxfreq)
                    {
                        maxfreq = mp[word];
                        ans = word;
                    }
                }
            }
            return ans;
        }
};