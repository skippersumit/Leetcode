class Solution
{
    public:
        vector<vector < string>> findDuplicate(vector<string> &paths)
        {
            unordered_map<string, vector < string>> mp;
            for (auto it: paths)
            {
                string str = "";	// To maintain the file path
                int i = 0;
                int mark = 0;	// To distinguish different file in  a string
                while (i < it.length())
                {
                    if (it[i] == ' ')
                    {
                        str += '/';
                        mark = str.length() - 1;
                    }	// Mark the start of the file
                    else if (it[i] == '(')
                    {
                        i++;
                        string temp = "";
                        while (it[i] != ')')
                        {
                            temp += it[i];
                            i++;
                        }
                        mp[temp].push_back(str);	// store the file
                        str = str.substr(0, mark);	// taking only the path of the files in a string
                    }
                    else
                    {
                        str += it[i];
                    }
                    i++;
                }
            }
            vector<vector < string>> ans;
            for (auto it: mp)
            {
                if (it.second.size() > 1) ans.push_back(it.second);
            }
            return ans;
        }
};