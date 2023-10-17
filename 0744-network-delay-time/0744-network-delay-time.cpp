class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(vector<int> time: times) {
            if(adj.find(time[0]) == adj.end()) adj[time[0]] = {};

            adj[time[0]].push_back({time[1], time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> shortestPath(n+1, INT_MAX);
        vector<bool> visited(n+1, false);
        minHeap.push({0, k});

        while(minHeap.size()) {
            pair<int, int> p = minHeap.top();
            minHeap.pop();
            if(visited[p.second])
                continue;

            visited[p.second] = true;
            shortestPath[p.second] = p.first;
            vector<pair<int, int>> neighbors = adj[p.second];

            for(pair<int, int> n: neighbors)
                minHeap.push({p.first + n.second, n.first});
        }

        int res = 0;
        for(int i=1; i<=n; i++)
            res = max(res, shortestPath[i]);

        if(res == INT_MAX) return -1;

        return res;
    }
};