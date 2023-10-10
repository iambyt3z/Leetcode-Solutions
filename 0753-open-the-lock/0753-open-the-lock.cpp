class Solution {
public:
    vector<string> calcChildren(string s) {
        vector<string> res = {};

        for(int i=0; i<4; i++) {
            string tmp1 = s;
            string tmp2 = s;
            int num = s[i] - '0';

            int n = (num + 1 + 10)%10;
            tmp1[i] = n + '0';
            res.push_back(tmp1);

            n = (num - 1 + 10)%10;
            tmp2[i] = n + '0';
            res.push_back(tmp2);
        }

        return res;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> visited;
        for(int i=0; i<deadends.size(); i++) {
            if(deadends[i] == "0000") return -1;

            visited[deadends[i]] = true;
        }
            

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visited["0000"] = true;

        while(q.size()) {
            string code = q.front().first;
            int count = q.front().second;
            q.pop();

            if(code == target) return count;

            vector<string> children = calcChildren(code);
            for(string &child: children) {
                if(!visited[child]) {
                    visited[child] = true;
                    q.push({child, count+1});
                } 
            }
        }

        return -1;
    }
};