class Solution
{
    public:
        void fun(vector<int> &candidates, int target, int id, vector<int> temp, vector< vector< int>> &ans)
        {
            if (0 == target)
            {
                ans.push_back(temp);
                return;
            }
            if(target<0) return;
            
            for(int i=id;i<candidates.size();i++){
                if(i == id or candidates[i] != candidates[i-1]){
                    temp.push_back(candidates[i]);
                    fun(candidates,target-candidates[i],i+1,temp,ans);
                    temp.pop_back();
                }
            }
        }
    vector<vector < int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        fun(candidates, target, 0, temp, ans);
        return ans;
    }
};