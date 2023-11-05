class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size();
        
        for(int i=0; i<n; i++) {
            int score = 0;
            
            for(int j=0; j<n; j++) {
                if(i==j) continue;
                
                score += grid[i][j];
            }
            
            if(score == n-1) return i;
        }
        
        return -1;
    }
};