class Solution
{
    public:
        vector<vector < int>> adj;	//neighbours nodes of the tree
    vector<map<int, pair<int, int>>> mp;	//pair<#total distance till this node, #total_nodes_till>

    void fun(int node, int par)
    {
        int total_nodes = 0;
        int total_dist = 0;

        for (int j = 0; j < adj[node].size(); j++)
        {
            if (adj[node][j] == par) continue;
            if (mp[node].find(adj[node][j]) == mp[node].end())
            {
                fun(adj[node][j], node);
            }
            total_nodes += mp[node][adj[node][j]].second;
            total_dist += mp[node][adj[node][j]].first;
        }

        total_dist += total_nodes;
        total_nodes++;
        mp[par][node] = { total_dist,
            total_nodes
        };
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector < int>> &edges)
    {
        adj.resize(n);
        vector<int> ans(n, 0);
        mp.resize(n);

        for (auto e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (mp[i].find(adj[i][j]) == mp[i].end())
                {
                    fun(adj[i][j], i);
                }
                ans[i] += mp[i][adj[i][j]].first;
                ans[i] += mp[i][adj[i][j]].second;
            }
        }

        return ans;
    }
};