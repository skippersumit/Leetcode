class Solution
{
    public:
        vector<int> ans;
    void rec(string a, int n, int k)
    {
        if (a.size() == n)
        {
            ans.push_back(stoi(a));
            return;
        }
        for (int i = 0; i <= 9; i++)
        {
            if (abs(i - (a[a.size() - 1] - '0')) == k)
            {
                a.push_back((i + '0'));
                rec(a, n, k);
                a.pop_back();
            }
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        string a = "";
        for (int i = 1; i <= 9; i++)
        {
            a = i + '0';
            rec(a, n, k);
        }
        return ans;
    }
};