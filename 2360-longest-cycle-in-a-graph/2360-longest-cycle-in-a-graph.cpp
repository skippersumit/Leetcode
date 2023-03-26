class Solution {
    void dfs(int node, vector<int> adj[], vector<int> &vis, unordered_map<int, int> &m, int p, int &ans) {
        vis[node] = 1;
        for(int ad : adj[node]) {
            if(m.find(ad) != m.end()) ans = max(ans, p - m[ad]);
            m[ad] = p++;
            if(!vis[ad]) dfs(ad, adj, vis, m, p, ans);
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1;
        vector<int> adj[n];
        for(int i=0; i<n; i++) {
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }
        vector<int> vis(n);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                unordered_map<int, int> m;
                m[i] = 0;
                dfs(i, adj, vis, m, 1, ans);
            }
        }
        return ans;
    }
};