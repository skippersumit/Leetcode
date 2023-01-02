class Solution
{
    public:
        bool detectCapitalUse(string word)
        {
            bool t = 0;
            int cntlower = 0, cntupper = 0;

            if (isupper(word[0]) || islower(word[0]))
            {

                for (int i = 1; i < word.size(); i++)
                {
                    if (islower(word[i]))
                        cntlower++;
                    else if (isupper(word[i]))
                        cntupper++;
                }
                if (cntlower == word.size() - 1 || (cntupper == word.size() - 1 && isupper(word[0])))
                    t = 1;
            }
            if (word.size() == 1)
                t = 1;

            return t;
        }
};