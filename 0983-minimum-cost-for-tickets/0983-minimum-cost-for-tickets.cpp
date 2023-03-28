class Solution {
public:
    vector<int>dp;
    int n;
    int solve(int i,vector<int>& days, vector<int>& costs){
        if(i>=n) return 0;
        else if(dp[i] != -1) return dp[i];
        
        int res = 2e9;
        int cur=days[i];
        res=min(res,costs[2]+solve(upper_bound(days.begin(),days.end(),cur+30-1)-days.begin(),days,costs));
        res=min(res,costs[1]+solve(upper_bound(days.begin(),days.end(),cur+7-1)-days.begin(),days,costs));
        res=min(res,costs[0]+solve(i+1,days,costs));

        return dp[i]=res;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size();
        dp.resize(n+1,-1);
        return solve(0,days,costs);
    }
};