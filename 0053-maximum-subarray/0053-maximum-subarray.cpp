class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int len = nums.size();
        vector<int> arr(len, -1);
        int max_sum = INT_MIN;
        
        for(int i=0; i<len; i++){
            if(i==0) arr[i] = nums[0];
            else arr[i] = max(arr[i-1] + nums[i], nums[i]);
            
            max_sum = max(max_sum, arr[i]);
        }
        
        return max_sum;
    }
};