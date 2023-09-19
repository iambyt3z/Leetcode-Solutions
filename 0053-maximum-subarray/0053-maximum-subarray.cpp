class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();

        vector<int> dp(len, nums[0]);
        int res = nums[0];

        for(int i=1; i<len; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            res = max(res, dp[i]);
        }

        return res;
    }
};