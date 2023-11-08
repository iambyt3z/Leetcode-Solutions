class Solution {
public:
    // void dfs(int l, int r, vector<int> &cuts, int &res) {
    //     if(r-l == 1)
    //         return ;

    //     if(l >= cuts[cuts.size()-1] || r <= cuts[0])
    //         return ;

    //     int i = 0, j = cuts.size()-1;
    //     int cutIndex = -1, diffFromMid = r-l;

    //     while(i <= j) {
    //         int mid = i + (j-i)/2;
            
    //         if(cuts[mid] <= l) {
    //             i = mid+1;
    //             continue;
    //         }

    //         if(cuts[mid] >= r) {
    //             j = mid-1;
    //             continue;
    //         }

    //         int diff = l+(r-l)/2 - cuts[mid];
    //         if(abs(diff) < diffFromMid) {
    //             diffFromMid = abs(diff);
    //             cutIndex = mid;
    //         }

    //         if(diff == 0) break;
    //         else if(diff > 0) i = mid+1;
    //         else j = mid-1;
    //     }

    //     if(cutIndex == -1) return ;

    //     res += (r-l); 
    //     dfs(l, cuts[cutIndex], cuts, res);
    //     dfs(cuts[cutIndex], r, cuts, res);
    // }

    map<pair<int, int>, int> dp;

    int solve(int l, int r, vector<int> &cuts) {
        if(r-l == 1) 
            return 0;

        if(l >= cuts[cuts.size()-1] || r <= cuts[0])
            return 0;

        if(dp.find({l, r}) != dp.end()) return dp[{l, r}];

        int res = INT_MAX;
        for(int i=0; i<cuts.size(); i++) {
            if(cuts[i] > l && cuts[i] < r)
                res = min(
                    res, 
                    (r-l) + solve(l, cuts[i], cuts) + solve(cuts[i], r, cuts)
                );
        }

        if(res == INT_MAX)
            res = 0;

        return dp[{l, r}] = res;
    }

    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        dp.clear();

        cout << "break";

        return solve(0, n, cuts);;
    }
};