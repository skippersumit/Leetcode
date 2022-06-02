class Solution
{
    public:
        int thirdMax(vector<int> &nums)
        {
            long long int fM, sM, tM;
            fM = sM = tM = LLONG_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                int ele = nums[i];
                if (ele > fM)
                {
                    tM = sM;
                    sM = fM;
                    fM = ele;
                }
                else if (ele < fM and ele > sM)
                {
                    tM = sM;
                    sM = ele;
                }
                else if (ele < sM and ele > tM)
                {
                    tM = ele;
                }
            }
            cout << fM << " " << sM << " " << tM << endl;
            return tM == LLONG_MIN ? fM : tM;
        }
};