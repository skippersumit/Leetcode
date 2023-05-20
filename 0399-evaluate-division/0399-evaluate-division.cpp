class Solution {
    bool dfs(string src , string &dest ,   unordered_map<string , vector<pair<string , double>>> &mpp , double curr , double &ans ,  unordered_map<string  , bool> &vis)
    {
        if(src == dest)
        {
            ans = curr;
            return true;
        }

        for(auto i:mpp[src])
        {
            string next = i.first;
            double val = i.second;

            if(vis[next] == false)
            {
                vis[next] = true;
                dfs(next , dest , mpp , curr * val , ans , vis);
                vis[next] = false;
            }
        }
        return false;

    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , vector<pair<string , double>>> mpp;
        for(int i=0 ; i<equations.size() ; i++)
        {
            mpp[equations[i][0]].push_back({equations[i][1] , values[i]});
            mpp[equations[i][1]].push_back({equations[i][0] , 1/values[i]});
        }
        vector<double> ans;
        unordered_map<string  , bool> vis;

        for(int i=0 ; i<queries.size() ; i++)
        {
            string src = queries[i][0];
            string dest = queries[i][1];

            double ele = -1;
            double curr = 1;
            
            vis[src] = true;
            if(mpp.find(src) != mpp.end() && mpp.find(dest) != mpp.end())   dfs(src , dest , mpp , curr , ele , vis);
            vis[src] = false;
            ans.push_back(ele);
        }
        return ans;
    }
};