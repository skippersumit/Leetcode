class Solution
{
    public:
        bool equationsPossible(vector<string> &equations)
        {
            map<char, int> map;
            int count = 0;
            for (auto &p: equations)
            {
                if (p[1] == '=')
                {
                    if (map.find(p[0]) == map.end())
                        map[p[0]] = count++;
                    if (map.find(p[3]) == map.end())
                        map[p[3]] = map[p[0]];
                    else
                    {
                        int val = map[p[3]];
                        for (auto &e: map)
                            if (e.second == val)
                                e.second = map[p[0]];
                    }
                }
            }
            for (auto &p: equations)
            {
                if (p[1] == '!')
                {
                    if (map.find(p[0]) == map.end())
                        map[p[0]] = count++;
                    if (map.find(p[3]) == map.end())
                        map[p[3]] = count++;
                    if (map[p[0]] == map[p[3]])
                        return false;
                }
            }
            return true;
        }
};