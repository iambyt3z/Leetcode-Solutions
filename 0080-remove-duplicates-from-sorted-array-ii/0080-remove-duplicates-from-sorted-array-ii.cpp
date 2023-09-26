class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res;
        int lastSeen = nums[0], seenTimes = 1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] != lastSeen) {
                lastSeen = nums[i];
                seenTimes = 1;
            }

            else {
                seenTimes++;

                if(seenTimes > 2) {
                    nums.erase(nums.begin() + i);
                    i--;
                    seenTimes--;
                }
            }
        }

        return nums.size();
    }
};