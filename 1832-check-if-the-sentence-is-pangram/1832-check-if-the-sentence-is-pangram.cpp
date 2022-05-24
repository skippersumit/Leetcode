class Solution
{
    public:
        bool checkIfPangram(string sentence)
        {
            unordered_map<char, int> m;
            for (int i = 0; i < sentence.size(); i++)
            {
                m[sentence[i]]++;
            }
            for (char i = ' a'; i <= 'z'; i++)
            {
                if (m[i] == 0)
                {
                    return false;
                }
            }
            return true;
        }
};