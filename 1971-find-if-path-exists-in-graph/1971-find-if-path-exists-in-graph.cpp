class Solution
{
    public:
        bool validPath(int n, vector<vector < int>> &edges, int source, int destination)
        {
            vector<int> adj[n];
            for (int i = 0; i < edges.size(); i++)
            {
                int u = edges[i][0];
                int v = edges[i][1];

                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
            vector<int> vis(n, 0);
            for (int i = 0; i < n; i++)
                if (vis[i] == 0)
                    if (dfs(adj, vis, source, destination))
                        return true;

            return false;
        }
    bool dfs(vector<int> adj[], vector<int> &vis, int source, int destination)
    {
        if (destination == source)
            return true;
        vis[source] = 1;
        for (auto it: adj[source])
            if (vis[it] == 0)
                if (dfs(adj, vis, it, destination))
                    return true;

        return false;
    }
};