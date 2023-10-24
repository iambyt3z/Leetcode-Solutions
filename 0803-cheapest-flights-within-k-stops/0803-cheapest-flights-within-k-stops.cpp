class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        k++;

        while(k--) {
            vector<int> tmp(prices.begin(), prices.end());

            for(int i=0; i<flights.size(); i++) {
                if(prices[flights[i][0]] == INT_MAX)
                    continue;

                if(prices[flights[i][0]] + flights[i][2] < tmp[flights[i][1]])
                    tmp[flights[i][1]] = prices[flights[i][0]] + flights[i][2];
            }

            copy(tmp.begin(), tmp.end(), prices.begin());
        }

        if(prices[dst] == INT_MAX)
            return -1;

        return prices[dst]; 
    }
};