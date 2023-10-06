/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<int, pair<bool, Node*>> &visited) {
        if(visited[node->val].first) return visited[node->val].second;

        Node* newNode = new Node(node->val);
        visited[node->val] = {true, newNode};
        vector<Node*> neighbors_tmp = node->neighbors;

        for(int i=0; i<neighbors_tmp.size(); i++) {
            Node* neighbor_tmp = neighbors_tmp[i];
            Node* new_neighbor = dfs(neighbor_tmp, visited);

            bool alreadyAdded = false;
            vector<Node*> new_neighbors = newNode->neighbors;
            for(int j=0; j<new_neighbors.size(); j++) {
                if(new_neighbors[j] == new_neighbor) alreadyAdded = true;
            }

            if(!alreadyAdded) {
                newNode->neighbors.push_back(new_neighbor);
                new_neighbor->neighbors.push_back(newNode);
            }
        }

        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_map<int, pair<bool, Node*>> visited;

        return dfs(node, visited);
    }
};