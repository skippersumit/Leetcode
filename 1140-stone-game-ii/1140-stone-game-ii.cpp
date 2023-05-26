class Solution {

    vector<vector<vector<int>>> dp;

    int DFS(int ind, int M, bool turn, vector<int>& piles)
    {
        if(dp[ind][M][turn] != -1)
            return dp[ind][M][turn];

        int ret = turn ? INT_MIN : INT_MAX;
        
        int sum = 0;
        for(int i = 1; i <= 2*M && ind + i <= piles.size(); i++)
        {
            sum += piles[ind + i - 1];
            if(turn)
                ret = max(ret, sum + DFS(ind + i, max(M, i), false, piles));
            else
                ret = min(ret, -sum + DFS(ind + i, max(M, i), true, piles));
        }

        if(ret == INT_MAX || ret == INT_MIN)
            return dp[ind][M][turn] = 0;
            
        return dp[ind][M][turn] = ret;
    }

public:
    int stoneGameII(vector<int>& piles) {
        
        dp = vector<vector<vector<int>>>(piles.size() + 1, vector<vector<int>>(piles.size() + 1, vector<int>(2, -1)));
        
        return (DFS(0, 1, true, piles) + accumulate(piles.begin(), piles.end(), 0)) / 2;
    }
};