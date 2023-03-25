class Solution {
public:
    void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &um, int &count) {
        count++;
        vis[node] = 1;
        for (auto nxt : um[node]) {
            if (!vis[nxt]) dfs(nxt, vis, um, count);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        unordered_map<int, vector<int>> um;
        for (auto edge : edges) {
            um[edge[0]].push_back(edge[1]);
            um[edge[1]].push_back(edge[0]);
        }
        vector<int> counts;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int count = 0;
                dfs(i, vis, um, count);
                counts.push_back(count);
            }
        }
        long long res = 0;
        for (auto i : counts) {
            res += (long long)i * (n-i);
            n -= i;
        }
        return res;
    }
};