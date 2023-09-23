class Solution {
public:
    int dp[101][51][51];

    int solve(int i, int a, int b, vector<vector<int>>& costs) {
        if(dp[i][a][b] != -1) return dp[i][a][b];

        if(i == costs.size()) return dp[i][a][b] = 0;
        if(a == costs.size()/2) return dp[i][a][b] = solve(i+1, a, b+1, costs) + costs[i][1];
        if(b == costs.size()/2) return dp[i][a][b] = solve(i+1, a+1, b, costs) + costs[i][0];

        return dp[i][a][b] = min(
            solve(i+1, a+1, b, costs) + costs[i][0],
            solve(i+1, a, b+1, costs) + costs[i][1]
        );
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, costs);
    }
};