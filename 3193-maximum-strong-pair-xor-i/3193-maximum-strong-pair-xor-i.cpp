class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int len = nums.size();
        int res = 0;

        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                if(i == j) continue;

                if(abs(nums[i]-nums[j]) <= min(nums[i], nums[j])) {
                    res = max(res, nums[i]^nums[j]);
                }
            }
        }

        return res;
    }
};