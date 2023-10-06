class Solution {
public:
    void dfs(int i, int j, int &n, int &m, vector<vector<char>>& board, map<pair<int, int>, bool> &visited) {
        board[i][j] = 'A';
        visited[{i, j}] = true;

        if(i-1 >=0 && board[i-1][j] == 'O' && !visited[{i-1, j}]) 
            dfs(i-1, j, n, m, board, visited);
        
        if(i+1 <n && board[i+1][j] == 'O' && !visited[{i+1, j}]) 
            dfs(i+1, j, n, m, board, visited);
        
        if(j-1 >=0 && board[i][j-1] == 'O' && !visited[{i, j-1}]) 
            dfs(i, j-1, n, m, board, visited);

        if(j+1<m && board[i][j+1] == 'O' && !visited[{i, j+1}]) 
            dfs(i, j+1, n, m, board, visited);
    }

    void solve(vector<vector<char>>& board) {
        int rowLen = board.size();
        int colLen = board[0].size();
        map<pair<int, int>, bool> visited;

        for(int i=0; i<rowLen; i++) {
            if(board[i][0] == 'O' && !visited[{i, 0}]) 
                dfs(i, 0, rowLen, colLen, board, visited);
            
            if(board[i][colLen-1] == 'O' && !visited[{i, colLen-1}]) 
                dfs(i, colLen-1, rowLen, colLen, board, visited);
        }

        for(int j=0; j<colLen; j++) {
            if(board[0][j] == 'O' && !visited[{0, j}]) 
                dfs(0, j, rowLen, colLen, board, visited);
            
            if(board[rowLen-1][j] == 'O' && !visited[{rowLen-1, j}]) 
                dfs(rowLen-1, j, rowLen, colLen, board, visited);
        }

        for(int i=0; i<rowLen; i++) {
            for(int j=0; j<colLen; j++) {
                if(board[i][j] == 'A') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};