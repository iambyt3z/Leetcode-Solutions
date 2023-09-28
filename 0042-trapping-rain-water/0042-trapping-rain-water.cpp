class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len <= 2) return 0;
        
        vector<int> largestOnLeft(len, 0), largestOnRight(len, 0);

        int temp = 0;
        for(int i=0; i<len; i++) {
            int largest = max(temp, height[i]);
            largestOnLeft[i] = largest;
            temp = largest;
        }

        temp = 0;
        for(int i=len-1; i>=0; i--) {
            int largest = max(temp, height[i]);
            largestOnRight[i] = largest;
            temp = largest;
        }

        int res = 0;
        for(int i=0; i<len; i++) {
            res += min(largestOnLeft[i], largestOnRight[i]) - height[i];
        }

        return res;
    }
};