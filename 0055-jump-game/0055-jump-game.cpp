class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return true;

        int maxReach = nums[0];
        int i=0;

        while(i<=maxReach && i<len) {
            maxReach = max(maxReach, i+nums[i]);
            
            if(maxReach >= len-1)
                return true;

            i++;
        }

        return false;
    }
};