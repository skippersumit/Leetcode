class Solution {
public:
    int dp[402][402] =  {};
    int dfs(vector<int>&cuts, int i, int j){
        if(j-i <= 1) return 0;
        if(!dp[i][j]){
            dp[i][j] = INT_MAX;
            for(int k=i+1;k<j;k++){
                dp[i][j] = min( dp[i][j], 
                               cuts[j] - cuts[i] + dfs(cuts, i,k) + dfs(cuts,k,j));
            }
        }
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.emplace_back(0);
        cuts.emplace_back(n);
        sort(cuts.begin(),cuts.end());
        
        return dfs(cuts, 0, cuts.size()-1);
    }
};