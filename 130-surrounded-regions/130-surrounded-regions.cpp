class Solution
{
    public:
        void solve(vector<vector < char>> &board)
        {
            int n = board.size(), m = board[0].size();
            queue<int> q;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == 'O'
                        and(i == 0 or i == n - 1 or j == 0 or j == m - 1))
                    {
                        board[i][j] = '/';
                        q.push(i *m + j);
                    }
                }
            }
            
            vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
            
            while (!q.empty())
            {
                int sz = q.size();

                while (sz--)
                {
                    int curEle = q.front();
                    q.pop();
                    int r = curEle / m, c = curEle % m;
                    for (int i = 0; i < dir.size(); i++)
                    {
                        int nr = r + dir[i][0];
                        int nc = c + dir[i][1];

                        if (nr >= 0 and nr < n and nc >= 0 and nc < m and board[nr][nc] == 'O')
                        {
                            q.push(nr *m + nc);
                            board[nr][nc] = '/';
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == '/')
                        board[i][j] = 'O';
                    else
                        board[i][j] = 'X';
                }
            }
        }
};