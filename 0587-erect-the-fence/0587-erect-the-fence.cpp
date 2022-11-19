class Solution
{
    public:
        vector<vector < int>> outerTrees(vector<vector < int>> &trees)
        {

            int n = trees.size();
            if (n < 4)
                return trees;

            sort(trees.begin(), trees.end());

            set<int> st;
            int curr = 0;

            do {
                int tmp = (curr + 1) % n;

                for (int i = 0; i < n; i++)
                    if (helper(trees, curr, tmp, i) > 0)
                        tmp = i;

                for (int i = 0; i < n; i++)
                    if (helper(trees, curr, tmp, i) == 0)
                        st.insert(i);

                curr = tmp;
            } while (curr);

            vector<vector < int>> ans;
            for (auto &i: st)
                ans.push_back(trees[i]);

            return ans;
        }

    int helper(vector<vector < int>> &trees, int curr, int tmp, int i)
    {
        return (trees[i][0] - trees[curr][0]) *(trees[tmp][1] - trees[curr][1]) - (trees[tmp][0] - trees[curr][0]) *(trees[i][1] - trees[curr][1]);
    }
};