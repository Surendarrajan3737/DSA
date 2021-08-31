#include<bits/stdc++.h>

using namespace std;

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node * root) {
        queue<pair<Node*,int>> q;
        map<int,int> mpp;       //vertical line,Node val;
        
        q.push({root,0});
        
        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                Node* node = q.front().first;
                int vertical = q.front().second;
                q.pop();
                
                if(mpp.find(vertical) == mpp.end()) mpp[vertical] = node->data;
                
                if(node->left != NULL) q.push({node->left,vertical-1});
                if(node->right != NULL) q.push({node->right,vertical+1});        
            }
        }
        
        for(auto x : mpp){
            cout << x.second << ' ';
        }
    }

}; //End of Solution
