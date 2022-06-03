class Solution
{
    public:
        int trap(vector<int> &heights)
        {
            int n = heights.size();
            if (n < 3) return 0;
            
            int lHeight = heights[0];
            int rHeight = heights[n - 1];

            int l = 0, r = n - 1, sum = 0;
            while (l < r)
            {
                lHeight = max(lHeight, heights[l]);
                rHeight = max(rHeight, heights[r]);

                if (lHeight < rHeight)
                {
                    sum += lHeight - heights[l];
                    l++;
                }
                else
                {
                    sum += rHeight - heights[r];
                    r--;
                }
            }

            return sum;
        }
};