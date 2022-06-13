class Solution
{
    public:
        vector<vector < int>> updateMatrix(vector<vector < int>> &mat)
        {
            int n = mat.size();
            int m = mat[0].size();

            queue<int> q;
            vector<vector < int>> ans(n, vector<int> (m));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (mat[i][j] == 0)
                    {
                        ans[i][j] = 0;
                        q.push(i *m + j);
                    }
                    else
                    {
                        ans[i][j] = -1;
                    }
                }
            }
            
            vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};

            int level = 0;
            while (!q.empty())
            {
                int sz = q.size();
                while (sz--)
                {
                    int curCell = q.front();
                    q.pop();
                    int r = curCell / m, c = curCell % m;
                    for (int k = 0; k < dir.size(); k++)
                    {
                        int nr = r + dir[k][0];
                        int nc = c + dir[k][1];

                        if (nr >= 0 and nr < n and nc >= 0 and nc < m and ans[nr][nc] == -1)
                        {
                            q.push(nr *m + nc);
                            ans[nr][nc] = level + 1;
                        }
                    }
                }
                level++;
            }

            return ans;
        }
};