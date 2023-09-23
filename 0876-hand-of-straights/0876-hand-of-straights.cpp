class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(groupSize == 1) return true;
        if(hand.size() < groupSize) return false;

        sort(hand.begin(), hand.end());

        while(hand.size()) {
            if(hand.size() < groupSize) return false;

            int ind = 0;
            int prev = hand[0];
            hand.erase(hand.begin());
            int tempGroupSize = 1;

            while(tempGroupSize < groupSize) {
                if(prev == hand[ind]) {
                    ind++;
                    if(ind >= hand.size()) return false;

                    continue;
                }

                if(hand[ind] - prev != 1) return false;

                tempGroupSize++;
                prev = hand[ind];
                hand.erase(hand.begin() + ind);
            }
        }

        return true;
    }
};