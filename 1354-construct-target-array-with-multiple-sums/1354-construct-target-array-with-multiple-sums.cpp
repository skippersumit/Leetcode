typedef long long int ll;
class Solution
{
    public:
        bool isPossible(vector<int> &target)
        {
            if (target.size() == 1 && target[0] != 1) return false;
            priority_queue<ll> pq;
            ll sum = 0;
            for (int num: target)
            {
                pq.push(num);
                sum += num;
            }
            while (1)
            {
                ll val = pq.top();
                pq.pop();
                ll diff = sum - val;
                if (diff == 1 || val == 1) return true;
                ll curr = val % diff;
                if (val - diff <= 0 || curr == 0) return false;
                pq.push(curr);
                sum = diff + (curr);
            }
            return true;
        }
};