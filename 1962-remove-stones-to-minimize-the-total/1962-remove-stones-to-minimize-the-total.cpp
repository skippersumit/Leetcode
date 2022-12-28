class Solution
{
    public:
        int minStoneSum(vector<int> &piles, int k)
        {
            priority_queue<int> q;
            for (int i = 0; i < piles.size(); i++)
            {
                q.push(piles[i]);
            }
            for (int i = 0; i < k; i++)
            {
                int a = q.top();
                q.pop();
                a = a - floor(a / 2);
                q.push(a);
            }
            int sum = 0;
            while (!q.empty())
            {
                sum += q.top();
                q.pop();
            }

            return sum;
        }
};