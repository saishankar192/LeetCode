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
    Node* creatNode(int val){
        Node* newNode = new Node(val);
        return newNode;
    }

    Node* bfs(Node* node){
        queue<Node*> q;
        q.push(node);

        unordered_map<Node*, Node*> um;
        Node* root = creatNode(node->val);
        
        um[node] = root;

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
          
            for(auto x: temp->neighbors){
                if(um.find(x)==um.end()){
                    q.push(x);
                    um[x]  = creatNode(x->val);
                }
                um[temp]->neighbors.push_back(um[x]);
            }
        }
        return root;
    }

    Node* cloneGraph(Node* node) {
        if(node)
            return bfs(node);
        return node;
    }
};