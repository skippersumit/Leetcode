class Solution
{
    public:
        bool isVowel(char c)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                return true;

            return false;
        }

    bool halvesAreAlike(string s)
    {
        int v1 = 0, v2 = 0, start = 0, end = s.size() - 1;

        while (start < end)
        {
            if (isVowel(s[start])) v1++;
            if (isVowel(s[end])) v2++;

            start++;
            end--;
        }

        return (v1 == v2);
    }
};