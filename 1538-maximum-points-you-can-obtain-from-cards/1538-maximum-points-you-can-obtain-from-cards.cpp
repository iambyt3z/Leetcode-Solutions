class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size();
        int windowSum = 0, totalSum = 0;

        for(int i=0; i<len; i++) {
            if(i < len-k) windowSum += cardPoints[i];
            totalSum += cardPoints[i];
        }

        int l=0, r=len-k-1;
        int minWinSum = windowSum;
        while(r < len-1) {
            windowSum -= cardPoints[l];
            l++;
            r++;
            windowSum += cardPoints[r];

            minWinSum = min(minWinSum, windowSum);
        }

        return totalSum-minWinSum;
    }
};