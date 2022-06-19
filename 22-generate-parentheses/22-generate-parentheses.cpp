class Solution
{
    public:

        void solve(int curOpen, int curClose, int remainOpen, int remainClose, string &op, vector<string> &rs)
        {
            if (remainOpen == 0 && remainClose == 0)
            {
                rs.push_back(op);
                return;
            }

            if (remainOpen > 0)
            {
                op.push_back('(');
                solve(curOpen + 1, curClose, remainOpen - 1, remainClose, op, rs);
                op.pop_back();
            }

            if (remainClose > 0 && curOpen > curClose)
            {
                op.push_back(')');
                solve(curOpen, curClose + 1, remainOpen, remainClose - 1, op, rs);
                op.pop_back();
            }
        }
    vector<string> generateParenthesis(int n)
    {
        vector<string> rs;

        string op = "(";
        int curOpen = 1;
        int curClose = 0;
        int remainOpen = n - 1;
        int remainClose = n;
        solve(curOpen, curClose, remainOpen, remainClose, op, rs);
        return rs;
    }
};