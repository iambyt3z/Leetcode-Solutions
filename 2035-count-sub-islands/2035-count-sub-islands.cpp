class Solution {
public:
    bool isSubIsland(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, map<pair<int, int>, bool> &visited) {
        int rowLen = grid2.size(), colLen = grid2[0].size();
        bool res = true;
        visited[{i, j}] = true;

        if(grid1[i][j] != 1) res = false;
        
        if(i-1 >= 0 && grid2[i-1][j] && !visited[{i-1, j}]) 
            res = (isSubIsland(i-1, j, grid1, grid2, visited) && res);
        
        if(i+1 < rowLen && grid2[i+1][j] && !visited[{i+1, j}]) 
            res = (isSubIsland(i+1, j, grid1, grid2, visited) && res);
        
        if(j-1 >= 0 && grid2[i][j-1] && !visited[{i, j-1}]) 
            res = (isSubIsland(i, j-1, grid1, grid2, visited) && res);
        
        if(j+1 < colLen && grid2[i][j+1] && !visited[{i, j+1}]) 
            res = (isSubIsland(i, j+1, grid1, grid2, visited) && res);

        return res;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        map<pair<int, int>, bool> visited;

        for(int i=0; i<grid2.size(); i++) {
            for(int j=0; j<grid2[0].size(); j++) {
                if (
                    grid2[i][j] && 
                    !visited[{i, j}] && 
                    isSubIsland(i, j, grid1, grid2, visited)
                ) {
                    res++;
                }
            }
        }

        return res;
    }
};