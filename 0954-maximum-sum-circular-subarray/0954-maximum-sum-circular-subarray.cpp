class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int len = nums.size();
        int cmin = 0, gmin = nums[0];
        int cmax = 0, gmax = nums[0];
        int total = 0;

        for(int i=0; i<len; i++) {
            total += nums[i];
            cmin = min(nums[i], cmin + nums[i]);
            cmax = max(nums[i], cmax + nums[i]);
            gmin = min(gmin, cmin);
            gmax = max(gmax, cmax);
        }

        if(total != gmin) return max(gmax, total-gmin);
        return gmax;
    }
};