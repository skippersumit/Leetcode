class Solution
{
    public:
        struct node
        {
            int timeFrame;
            int x, y;
            node(int t, int a, int b)
            {
                timeFrame = t;
                x = a;
                y = b;
            }
        };

    bool isValid(int x, int y, int row, int col)
    {
        if (x < 0 || x >= row || y < 0 || y >= col)
            return false;
        return true;
    }

    int orangesRotting(vector<vector < int>> &grid)
    {

       	//FAST IO
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        queue<node> my_q;
        int rows = grid.size();
        int columns = grid[0].size();

       	//Scan all the elements for rotten oranges 
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i][j] == 2)
                    my_q.push(node(0, i, j));
            }
        }

       	//Process all the node from queue 
        int result_time = 0;

        while (!my_q.empty())
        {
            result_time = my_q.front().timeFrame;
            int x1 = my_q.front().x;
            int y1 = my_q.front().y;
            my_q.pop();
           	//Generate all cordintates 
            if (isValid(x1 + 1, y1, rows, columns) && grid[x1 + 1][y1] == 1)
            {
                grid[x1 + 1][y1] = 2;
                my_q.push(node(result_time + 1, x1 + 1, y1));
            }

            if (isValid(x1, y1 + 1, rows, columns) && grid[x1][y1 + 1] == 1)
            {
                grid[x1][y1 + 1] = 2;
                my_q.push(node(result_time + 1, x1, y1 + 1));
            }

            if (isValid(x1 - 1, y1, rows, columns) && grid[x1 - 1][y1] == 1)
            {
                grid[x1 - 1][y1] = 2;
                my_q.push(node(result_time + 1, x1 - 1, y1));
            }

            if (isValid(x1, y1 - 1, rows, columns) && grid[x1][y1 - 1] == 1)
            {
                grid[x1][y1 - 1] = 2;
                my_q.push(node(result_time + 1, x1, y1 - 1));
            }
        }

       	//Check if any orange is not rotten after BFS 
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return result_time;
    }
};