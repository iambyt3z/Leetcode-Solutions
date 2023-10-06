class Solution {
public:
    void bfs(int i, int j, map<pair<int, int>, bool> &visited, vector<vector<char>>& grid) {
        if(visited[{i, j}]) return ;

        visited[{i, j}] = true;
        int rowLen = grid.size(), colLen = grid[i].size();

        if(i-1 >= 0 && grid[i-1][j] == '1') bfs(i-1, j, visited, grid);
        if(i+1 < rowLen && grid[i+1][j] == '1') bfs(i+1, j, visited, grid);
        if(j-1 >= 0 && grid[i][j-1] == '1') bfs(i, j-1, visited, grid);
        if(j+1 < colLen && grid[i][j+1] == '1') bfs(i, j+1, visited, grid);

        grid[i][j] = '0';
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        map<pair<int, int>, bool> visited;

        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                if(grid[i][j] == '1' && !visited[{i, j}]) {
                    cout<<"entered"<<endl;
                    bfs(i, j, visited, grid);
                    res++;
                }
            }
        }

        return res;
    }
};