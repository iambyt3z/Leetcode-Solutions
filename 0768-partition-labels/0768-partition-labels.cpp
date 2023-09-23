class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp;
        for(int i=0; i<s.length(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                mp[s[i]] = {i, i};
                continue;
            }

            mp[s[i]].second = i;
        }

        int i = 0;
        int range = 0, covered = 0;
        vector<int> res;

        while(i < s.length()) {
            cout<<"s["<<i<<"] = "<<s[i]<<", range = "<<range<<", covered = "<<covered<<endl;

            if(i > range) {
                cout<<(i - covered)<<" Pushed in res"<<endl;
                res.push_back(i - covered);
                covered = i;
            }

            range = max(range, mp[s[i]].second);
            i++;
        }

        res.push_back(i - covered);
        
        return res;
    }
};