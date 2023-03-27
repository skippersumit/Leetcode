class Solution {
public:
    int minPathSum(vector<vector<int>>& gr) {
        vector<vector<int>> dp(gr.size(),vector<int>(gr[0].size(),-1));
        for(int i=0;i<gr.size();i++){
            for(int j=0; j<gr[0].size();j++){
                    if(i==0 && j==0) dp[i][j] = gr[i][j];
                    else{
                        int a=1e7,b=1e7;
                        if(i>0)
                            a= dp[i-1][j];
                        if(j>0)
                            b = dp[i][j-1];
                        dp[i][j] = gr[i][j] + min(a,b);
                }
            }
        }
        return dp[gr.size()-1][gr[0].size()-1];
    }
};