class Solution {
public:
    int dp[101][101];

    int solve(int i, string &s, int sum) {
        if(sum < 0) return 0;

        if(dp[i][sum] != -1) return dp[i][sum];

        if(i == s.length()) return dp[i][sum] = (sum == 0);
        if(s[i] == ')') return dp[i][sum] = solve(i+1, s, sum-1);
        else if(s[i] == '(') return dp[i][sum] = solve(i+1, s, sum+1);

        return dp[i][sum] =
            min (
                1,
                solve(i+1, s, sum-1) +
                solve(i+1, s, sum+1) +
                solve(i+1, s, sum)
            );
    }

    bool checkValidString(string s) {
        if(s[0] == ')') return false;
        
        memset(dp, -1, sizeof(dp));
        return solve(0, s, 0);
    }
};