class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> in(n, 0);
        for(auto edge : edges){
            in[edge[1]]++; 
        }
        vector<int> ret;
        for(int i=0; i<n; i++)
            if(!in[i]) ret.push_back(i);
        return ret;
    }
};