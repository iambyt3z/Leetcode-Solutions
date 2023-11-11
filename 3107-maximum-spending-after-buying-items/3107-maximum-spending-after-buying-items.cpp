class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long res = 0;
        long long d = 1;
        int n = values.size(), m = values[0].size();
        long long prod = n*m;

        while(d <= prod) {
            int min_price = INT_MAX;
            int min_ind = -1;

            for(int i=0; i<n; i++) {
                if(values[i].size() && values[i][values[i].size()-1] < min_price) {
                    min_price = values[i][values[i].size()-1];
                    min_ind = i;
                }
            }

            values[min_ind].pop_back();
            res += (long long) d*min_price;
            d++;
        }

        return res;
    }
};