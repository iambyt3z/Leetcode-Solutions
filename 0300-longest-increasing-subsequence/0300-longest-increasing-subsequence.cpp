class Solution {
public:
    int dp[2500][2500];

    int solve(int end, int i, vector<int>& nums) {
        if(i >= nums.size()) return 0;

        if(dp[end+1][i] != -1) return dp[end+1][i];

        if(end == -1) return dp[end+1][i] = max(solve(end, i+1, nums), solve(i, i+1, nums) + 1);

        if(nums[i] > nums[end])
            return dp[end+1][i] = max(solve(end, i+1, nums), solve(i, i+1, nums) + 1);

        return dp[end+1][i] = solve(end, i+1, nums);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(-1, 0, nums);
    }
};