class Solution {
public:
    vector<int> res = {};

    int findParent(int node, vector<int> &parent) {
        int res = node;
        while(res != parent[res]) {
            res = parent[res];
        }

        return res;
    }

    void join(vector<int> &edge, vector<int> &parent, vector<int> &rank) {
        int p1 = findParent(edge[0], parent);
        int p2 = findParent(edge[1], parent);

        if(p1 == p2) {
            res = edge;
            return ;
        }

        if(rank[p2] > rank[p1]) {
            rank[p2] += rank[p1];
            parent[p1] = p2;
        } else {
            rank[p1] += rank[p2];
            parent[p2] = p1;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size() + 1);
        iota(parent.begin(), parent.end(), 0);
        vector<int> rank(edges.size() + 1, 1);

        for(vector<int> edge: edges) {
            join(edge, parent, rank);
            
            if(res.size()) break;
        }

        return res;
    }
};