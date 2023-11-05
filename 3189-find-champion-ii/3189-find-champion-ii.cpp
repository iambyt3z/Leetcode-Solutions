class Solution {
public:
    void dfs(int n, unordered_map<int, vector<int>> &adj, vector<int> &loses) {
        loses[n] = 1;
        
        for(int &nei: adj[n])
            if(loses[nei] != 1) 
                dfs(nei, adj, loses);
    }
    
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> loses(n, -1);
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<edges.size(); i++) {
            if(adj.find(edges[i][0]) == adj.end())
                adj[edges[i][0]] = {};
            
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        for(int i=0; i<n; i++) {
            if(loses[i] == -1) {
                dfs(i, adj, loses);
                loses[i] = 0;
            }   
        }
        
        int count=0, res=-1;
        for(int i=0; i<n; i++) {
            if(loses[i] == 0) {
                count++;
                res = i;
            }
        }
            
        
        if(count > 1 || count == 0) return -1;
        
        return res;
    }
};