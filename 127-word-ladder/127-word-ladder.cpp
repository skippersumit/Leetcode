class Solution
{
    public:
        int ladderLength(string beginWord, string endWord, vector<string> &wordList)
        {
            set<string> vis;
            for (auto i: wordList)
            {
                vis.insert(i);
            }
            queue<pair<string, int>> q;
            q.push({ beginWord,1 });
            while (!q.empty())
            {
                string word = q.front().first;
                int lvl = q.front().second;
                q.pop();
                if (word == endWord) return lvl;
                for (int i = 0; i < word.size(); i++)
                {
                    string temp = word;
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp[i] = ch;
                        if (temp == word) continue;
                        if (vis.find(temp) != vis.end())
                        {
                            vis.erase(temp);
                            q.push({ temp, lvl + 1 });
                        }
                    }
                }
            }
            return 0;
        }
};