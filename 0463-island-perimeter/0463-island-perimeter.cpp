class Solution {
public:
    int cellPerimeter(int i, int j, vector<vector<int>>& grid) {
        int rowlen = grid.size();
        int collen = grid[i].size();
        int res = 0;

        if(i-1 < 0) res++;
        else if(grid[i-1][j] == 0) res++;

        if(i+1 > rowlen-1) res++;
        else if(grid[i+1][j] == 0) res++;

        if(j-1 < 0) res++;
        else if(grid[i][j-1] == 0) res++;

        if(j+1 > collen-1) res++;
        else if(grid[i][j+1] == 0) res++;

        return res;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int res = 0;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j]) res += cellPerimeter(i, j, grid);
            }
        }

        return res;
    }
};