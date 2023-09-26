class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;

        int l=0, r=k-1, res=INT_MAX;
        sort(nums.begin(), nums.end());

        while(r < nums.size()) {
            res = min(res, nums[r] - nums[l]);
            r++;
            l++;
        }

        return res;
    }
};