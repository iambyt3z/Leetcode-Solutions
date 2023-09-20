class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int maxReach = nums[0];
        int jumps = 0;
        int ind = 0;
       
        while(ind < len-1) {
            int temp = maxReach;
            jumps++;

            while(temp > ind && ind < len-1) {
                ind++;
                maxReach = max(maxReach, ind+nums[ind]);
            }
        }

        return jumps;
    }
};