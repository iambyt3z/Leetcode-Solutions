class Solution {
public:
    int toMinutes(string s) {
        int n = stoi(s);
        int res = (n/100 * 60) + (n%100);

        return res;
    }

    bool isHighAccess(vector<int> &accessTimes) {
        int l=0, r=0;

        while(r < accessTimes.size()) {
            if(
                accessTimes[r] - accessTimes[l] < 60 && 
                r-l+1 >= 3
            ) return true;

            if(accessTimes[r] - accessTimes[l] < 60)
                r++;

            else
                l++;

        }

        return false;
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        if(access_times.size() < 3) return {};

        sort(access_times.begin(), access_times.end());

        unordered_map<string, vector<int>> map;
        int len = access_times.size();

        for(int i=0; i<len; i++) {
            if(map.find(access_times[i][0]) == map.end())
                map[access_times[i][0]] = {};

            map[access_times[i][0]].push_back( toMinutes(access_times[i][1]) );
        }

        vector<string> res;
        for(auto &[name, ats]: map) {
            if(isHighAccess(ats))
                res.push_back(name);
        }

        return res;
    }
};