class Solution {
public:
    bool dfs(
        int node, 
        vector<vector<int>>& graph, 
        unordered_map<int, bool> &isSafeNode,
        unordered_map<int, bool> &visited
    ) {
        visited[node] = true;

        if(isSafeNode.find(node) != isSafeNode.end())
            return isSafeNode[node];
        
        if(graph[node].size() == 0) {
            isSafeNode[node] = true;
            return true;
        }

        vector<int> neighbors = graph[node];
        bool isSafe = true;

        for(int i=0; i<neighbors.size(); i++) {
            int neighbor = neighbors[i];

            if(isSafeNode.find(neighbor) != isSafeNode.end()) {
                isSafe = isSafe && isSafeNode[neighbor];
                continue;
            }

            if(visited[neighbor]) {
                isSafe = false;
                continue;
            }

            isSafe = isSafe && dfs(neighbor, graph, isSafeNode, visited);
        }

        isSafeNode[node] = isSafe;
        return isSafe;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> isSafeNode;
        unordered_map<int, bool> visited;
        vector<int> res;

        for(int i=0; i<graph.size(); i++) {
            if(dfs(i, graph, isSafeNode, visited))
                res.push_back(i);
        }

        return res;
    }
};