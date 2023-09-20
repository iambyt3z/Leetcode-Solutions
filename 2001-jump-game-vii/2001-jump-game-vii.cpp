class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int len = s.length();
        queue<int> q;
        int maxReached = 0;
        q.push(0);

        while(q.size()) {
            int ind = q.front();
            q.pop();
            int start = max(ind+minJump, maxReached+1);
            int end = min(ind+maxJump, len-1);

            for(int i = start; i <= end; i++) {
                if(s[i] == '0') {
                    if(i == len-1) return true;
                    q.push(i);
                }
            }

            maxReached = end;
        }

        return false;
    }
};