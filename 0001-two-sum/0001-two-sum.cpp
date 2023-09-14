class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        vector<int> res;
        int len = nums.size();

        for(int i=0; i<len; i++) {
            if(i==0) {
                umap[nums[i]] = i;
                continue;
            }
                
            int b = nums[i];
            int a = target - b;  
                
            if(umap.find(a) != umap.end()) {
                res.push_back(umap[a]);
                res.push_back(i);

                break;
            }

            umap[nums[i]] = i;
        }

        return res;
    }
};