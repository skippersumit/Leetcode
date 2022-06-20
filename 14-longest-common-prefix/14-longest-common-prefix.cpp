class Solution
{
    public:
        string longestCommonPrefix(vector<string> &strs)
        {
            string longestCommonPrefix = "";
            if (strs.size() == 0) return longestCommonPrefix;

            int index = 0;
            for (char c: strs[0])
            {
                for (int i = 1; i < strs.size(); i++)
                {
                    if (index >= strs[i].length() || c != strs[i][index])
                        return longestCommonPrefix;
                }
                longestCommonPrefix += c;
                index++;
            }

            return longestCommonPrefix;
        }
};