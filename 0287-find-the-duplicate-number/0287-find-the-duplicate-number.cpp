class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int num = abs(nums[i]);
            nums[num-1] *= -1;

            if(nums[num-1] > 0) return num;
        }

        return -1;
    }
};