class Solution {
public:
    void dfs(vector<int> adj[], vector<bool> &visited, int src){
        visited[src] = true;
        for(auto i: adj[src]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& arr) {
        int len = arr.size();
        if(len < n-1) return -1;
        vector<int>adj[n];
        for(auto v : arr){
            adj[v[0]].emplace_back(v[1]);
            adj[v[1]].emplace_back(v[0]);
        }
        vector<bool>vis(n,false);
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                ans++;
            }
        }

        return ans-1;
    }
};