class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if(points.size() <= 1) return 0;
        
        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_map<int, bool> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<points.size(); i++) {
            adj[i] = {};

            for(int j=0; j<points.size(); j++) {
                if(i == j) continue;

                int manDist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, manDist});
            }
        }

        pq.push({0, 0});
        int res = 0;

        while(visited.size() < points.size()) {
            int point = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if(visited[point]) continue;

            res += cost;
            visited[point] = true;

            for(auto &[nei_point, nei_cost]: adj[point]) {
                if(visited.find(nei_point) == visited.end()) {
                    pq.push({nei_cost, nei_point});
                }
            }
        }

        return res;
    }
};