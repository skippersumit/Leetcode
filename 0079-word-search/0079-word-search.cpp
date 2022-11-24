class Solution
{
    public:
   
    bool dfs(vector<vector < char>> &board, string word, int i, int j, int count)
    {
        if (count == word.length()) return true;
        
        if(i<0 or i>= board.size() or j<0 or j>=board[i].size() or board[i][j] != word[count]) return false;

        char ch = board[i][j];
        board[i][j] = ' ';	//change
        
        bool found = dfs(board,word,i+1,j,count+1)
            or dfs(board,word,i-1,j,count+1)
            or dfs(board,word,i,j-1,count+1)
            or dfs(board,word,i,j+1,count+1);
        
        board[i][j] = ch;
        return found;
            
    }
    bool exist(vector<vector < char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0] and dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
};