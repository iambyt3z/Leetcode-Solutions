class Solution {
public:
    int areaOfIsland(int i, int j, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        int res = 0;
        int rowLen = grid.size(), colLen = grid[0].size();

        while(q.size()) {
            pair<int, int> point = q.front();
            q.pop();
            res++;

            int x = point.first, y = point.second;
            grid[x][y] = 0;
            
            if(x-1 >= 0 && grid[x-1][y]) {
                q.push({x-1, y});
                grid[x-1][y] = 0;
            }

            if(x+1 < rowLen && grid[x+1][y]) {
                q.push({x+1, y});
                grid[x+1][y] = 0;
            }

            if(y-1 >= 0 && grid[x][y-1]) {
                q.push({x, y-1});
                grid[x][y-1] = 0;
            }

            if(y+1 < colLen && grid[x][y+1]) {
                q.push({x, y+1});
                grid[x][y+1] = 0;
            }
        }

        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j]) res = max(res, areaOfIsland(i, j, grid));
            }
        }

        return res;
    }
};