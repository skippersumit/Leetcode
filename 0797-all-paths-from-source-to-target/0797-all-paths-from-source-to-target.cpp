class Solution
{
    public:

        void dfs(vector<vector < int>> &graph, vector< vector< int >> &ans, vector< int > path, int src, int des)
        {
            path.push_back(src);
            if (src == des)
            {
                ans.push_back(path);
            }

            for (auto i: graph[src])
            {
                dfs(graph, ans, path, i, des);
            }
        }
    vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
    {
        int n = graph.size();
        vector<vector < int>> ans;

        if (n == 0) return ans;

        vector<int> path;

        dfs(graph, ans, path, 0, n - 1);

        return ans;
    }
};