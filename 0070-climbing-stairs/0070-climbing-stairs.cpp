class Solution {
public:
    // int solve(int i, int n) {
    //     if(i==0) return 0;
    //     if(i==1) return 1;

    //     return 
    // }

    int climbStairs(int n) {
        if(n==1) return 1;

        int dp[n+1];
        for(int i=0; i<=n; i++)
            dp[i]=1;

        dp[1]=1;
        for(int i=2; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};