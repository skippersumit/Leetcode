
class Solution
{
    int find_matches(string w1, string w2)
    {
        int count = 0;
        for (int i = 0; i < 6; i++)
        {
            if (w1[i] == w2[i]) count++;
        }
        return count;
    }
    public:
        void findSecretWord(vector<string> &words, Master &master)
        {
            srand(time(0));
            vector<string> candidates;
            for (int i = 0; i < words.size(); i++)
            {
                candidates.push_back(words[i]);
            }
            while (!candidates.empty())
            {
                string word = candidates[rand() % candidates.size()];
                int match = master.guess(word);
                if (match == 6) return;
                vector<string> temp;
                for (string w: candidates)
                {
                    if (find_matches(w, word) == match) temp.push_back(w);
                }
                candidates = temp;
            }
        }
};