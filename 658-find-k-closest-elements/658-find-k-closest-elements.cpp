class Solution
{
    public:
        vector<int> findClosestElements(vector<int> &arr, int k, int x)
        {
            int n = arr.size();
            vector<pair<int, int>> p(n);
            for (int i = 0; i < arr.size(); i++)
            {
                p[i] = make_pair(abs(x - arr[i]), arr[i]);
            }
            sort(p.begin(), p.end());
            vector<int> ans(k);

            for (int i = 0; i < k; i++)
                ans[i] = p[i].second;

            sort(ans.begin(), ans.end());
            return ans;
        }
};