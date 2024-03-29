class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int nodes = colors.size(),n=nodes,res=0;
        vector<int> adjList[n];
        vector<int> indegree(n,0);
        vector<vector<int>> colorCount(n,vector<int>(26,0));
        queue<int> Q;

        for(auto &it : edges)
            adjList[it[0]].push_back(it[1]),++indegree[it[1]];
        
        for(int i=0;i<n;i++)
            if(indegree[i]==0) Q.push(i), --nodes;
        
        while(!Q.empty()){
            int top = Q.front();Q.pop();
            colorCount[top][colors[top]-'a']++;
            res = max(res, colorCount[top][colors[top]-'a']);
            for(auto &adjNode : adjList[top]){
                for(int i=0;i<26;i++){
                    colorCount[adjNode][i] = max(colorCount[adjNode][i],colorCount[top][i]);
                    res = max(res, colorCount[adjNode][i]);
                }
                --indegree[adjNode];
                if(indegree[adjNode]==0)
                    Q.push(adjNode),--nodes;
            }
        }
        return nodes == 0 ? res : -1;
    }
};