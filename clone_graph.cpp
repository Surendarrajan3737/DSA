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
    
    unordered_map<Node*,Node*> map;     // To map the respective node with the clone
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        return dfs(node);
    }
    
    Node* dfs(Node* node){
        if(map.find(node) != map.end()) return map[node];           // if that node is already visited  then return already created cloned node reference
        Node* clone = new Node(node->val); // We passed only the value not the adjacent nodes
        map[node] = clone;        // mapped the clones one to the respective node
        for(Node* x : node->neighbors){     // cloning all the adjacent nodes as refernce
            clone->neighbors.push_back(dfs(x));
        }
        return clone;
    }
};
