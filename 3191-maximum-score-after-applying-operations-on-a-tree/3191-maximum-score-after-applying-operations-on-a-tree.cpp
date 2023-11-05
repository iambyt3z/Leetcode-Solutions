class Solution {
public:
    long long calcSum(
        int node,
        int parent,
        vector<int> &values, 
        unordered_map<int, vector<int>> &adj,
        vector<long long> &sum
    ) {
        if(adj[node].size() == 1 && adj[node][0] == parent) {
            sum[node] = (long long) values[node];
            return (long long) values[node];
        }

        long long totalSum = (long long) values[node];

        for(int ni: adj[node]) {
            if(ni == parent) continue;
            totalSum += calcSum(ni, node, values, adj, sum);
        }     

        sum[node] = totalSum;
        return totalSum;
    }

    long long solve(
        int node,
        int parent,
        vector<int> &values, 
        unordered_map<int, vector<int>> &adj,
        vector<long long> &sum
    ) {
        if(adj[node].size() == 1 && adj[node][0] == parent)
            return 0;

        long long skipSum = 0;
        for(int n: adj[node]) {
            if(n == parent) continue;

            skipSum += sum[n];
        }
            

        long long notSkipSum = values[node];
        for(int &n: adj[node]) {
            if(n == parent) continue;
            
            notSkipSum += solve(n, node, values, adj, sum);
        }

        return max(skipSum, notSkipSum);
    }

    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();

        vector<long long> sum(n, -1);
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<edges.size(); i++) {
            if(adj.find(edges[i][0]) == adj.end())
                adj[edges[i][0]] = {};

            if(adj.find(edges[i][1]) == adj.end())
                adj[edges[i][1]] = {};

            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }


        calcSum(0, -1, values, adj, sum);
        for(int i=0; i<n; i++)
            cout<<sum[i]<<" ";


        return solve(0, -1, values, adj, sum);
    }
};