class Solution {
public:
    int solve(int n, int last_square) {
        int dp[n+1][last_square+1];
        memset(dp, -1, sizeof(dp));

        for(int j=1; j<=last_square; j++)
            dp[0][j] = 0;

        for(int i=1; i<=n; i++)
            dp[i][1] = i;

        for(int i=1; i<=n; i++) {
            for(int j=2; j<=last_square; j++) {
                if(j*j <= i)
                    dp[i][j] = min(dp[i-j*j][j] + 1, dp[i][j-1]);
                else
                    dp[i][j] = dp[i][j-1];
            }
        }

        return dp[n][last_square];
    }

    int numSquares(int n) {
        int i=0;
        while(i*i < n) i++;

        return solve(n, i);
    }
};