
#define mod 1000000007
class Solution
{
    public:
        int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
        {
            int maxHDiff = 0;
            horizontalCuts.emplace_back(0);
            horizontalCuts.emplace_back(h);
            sort(horizontalCuts.begin(), horizontalCuts.end());
            for (int i = 1; i < horizontalCuts.size(); i++)
            {
                maxHDiff = max(horizontalCuts[i] - horizontalCuts[i - 1], maxHDiff);
            }

            int maxWDiff = 0;
            verticalCuts.emplace_back(0);
            verticalCuts.emplace_back(w);
            sort(verticalCuts.begin(), verticalCuts.end());
            for (int i = 1; i < verticalCuts.size(); i++)
            {
                maxWDiff = max(verticalCuts[i] - verticalCuts[i - 1], maxWDiff);
            }
            
            long long ans = (long long)maxHDiff *maxWDiff;
            

            return ans % mod;
        }
};