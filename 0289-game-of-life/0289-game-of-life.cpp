class Solution {
public:
    int isAlive(int i, int j, vector<vector<int>>& board) {
        int len = board.size();
        if(i < 0 || i >= len) return 0;

        len = board[i].size();
        if(j < 0 || j >= len) return 0;

        int state = board[i][j];
        if(state == 0) return 0;
        if(state == 1) return 1;
        
        return (state > 0);
    }

    int calculateAlive(int &i, int &j, vector<vector<int>>& board) {
        return
            isAlive(i, j+1, board) +
            isAlive(i, j-1, board) +
            isAlive(i+1, j+1, board) +
            isAlive(i+1, j-1, board) +
            isAlive(i-1, j+1, board) +
            isAlive(i-1, j-1, board) +
            isAlive(i+1, j, board) +
            isAlive(i-1, j, board);
    }

    void gameOfLife(vector<vector<int>>& board) {
        int len=board.size();
        for(int i=0; i<len; i++) {
            for(int j=0; j<board[i].size(); j++) {
                int numOfAlive = calculateAlive(i, j, board);
                int prev = 0;
                if(board[i][j] == 0) prev = -1;
                else if(board[i][j] == 1) prev = 1;

                if(board[i][j] == 1) {
                    if(numOfAlive < 2 || numOfAlive > 3) board[i][j] = prev * 2;
                    else if(numOfAlive == 2 || numOfAlive == 3) board[i][j] = prev * 3;
                }

                if(board[i][j] == 0) {
                    if(numOfAlive == 3) board[i][j] = prev * 3;
                }
            }
        }

        for(int i=0; i<len; i++) {
            for(int j=0; j<board[i].size(); j++) {
                board[i][j] = (abs(board[i][j]) == 3);
            }
        }      
    }
};