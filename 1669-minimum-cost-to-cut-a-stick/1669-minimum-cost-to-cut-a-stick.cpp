class Solution {
public:
    map<pair<int, int>, int> dp;

    int solve(int l, int r, int i, int j, vector<int> &cuts) {
        if(r-l == 1) 
            return 0;

        if(l >= cuts[cuts.size()-1] || r <= cuts[0])
            return 0;

        if(dp.find({l, r}) != dp.end()) return dp[{l, r}];

        int res = INT_MAX;

        for(int ind = i; ind <= j; ind++) {
            if(cuts[ind] > l && cuts[ind] < r) {
                res = min (
                    res, 
                    (r-l) + 
                        solve(l, cuts[ind], i, ind, cuts) + 
                        solve(cuts[ind], r, ind, j, cuts)
                ); 
            } 
        }

        if(res == INT_MAX)
            res = 0;

        return dp[{l, r}] = res;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        dp.clear();

        return solve(0, n, 0, cuts.size()-1, cuts);;
    }
};