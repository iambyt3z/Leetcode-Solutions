class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> mp;
        int len = s.length();
        for(int i=0; i<len; i++) {
            mp[s[i]] = i;
        }

        int i = 0;
        int range = 0, covered = 0;
        vector<int> res;

        while(i < len) {
            if(i > range) {
                res.push_back(i - covered);
                covered = i;
            }

            range = max(range, mp[s[i]]);
            i++;
        }

        res.push_back(i - covered);
        
        return res;
    }
};