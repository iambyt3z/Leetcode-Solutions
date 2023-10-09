class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;
        map<pair<int, int>, bool> visited;

        for(int i=0; i<rowLen; i++) {
            for(int j=0; j<colLen; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if(grid[i][j] == 1)
                    freshOranges++;
            }
        }

        if(freshOranges == 0) return 0;

        int res = -1;
        while(q.size()) {
            int qLen = q.size();

            while(qLen--) {
                pair<int, int> point = q.front();
                q.pop();
                int x = point.first, y = point.second;
                grid[x][y] = 2;
                
                if(x+1 < rowLen && grid[x+1][y] == 1 && !visited[{x+1, y}]) {
                    q.push({x+1, y});
                    visited[{x+1, y}] = true;
                }

                if(x-1 >= 0 && grid[x-1][y] == 1  && !visited[{x-1, y}]) {
                    q.push({x-1, y});
                    visited[{x-1, y}] = true;
                }

                if(y+1 < colLen && grid[x][y+1] == 1 && !visited[{x, y+1}]) {
                    q.push({x, y+1});
                    visited[{x, y+1}] = true;
                }

                if(y-1 >= 0 && grid[x][y-1] == 1 && !visited[{x, y-1}]) {
                    q.push({x, y-1});
                    visited[{x, y-1}] = true;
                }
            }

            res++;
        }

        for(int i=0; i<rowLen; i++) {
            for(int j=0; j<colLen; j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return res;
    }
};