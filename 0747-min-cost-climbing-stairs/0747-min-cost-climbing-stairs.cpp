class Solution {
public:
    int dp[1001];

    int solve(int i, vector<int>& cost) {
        if(i >= cost.size()) return 0;

        if(dp[i] != -1) return dp[i];

        return dp[i] = min(
            solve(i+1, cost) + cost[i],
            solve(i+2, cost) + cost[i]
        );
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));

        return min(
            solve(0, cost),
            solve(1, cost)
        );
    }
};