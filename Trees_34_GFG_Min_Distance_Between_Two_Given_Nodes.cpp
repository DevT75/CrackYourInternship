/*
Given a binary tree and two node values your task is to find the minimum distance between them.
The given two nodes are guaranteed to be in the binary tree and nodes are numbered from 1 to N.
Please Note that a and b are not always leaf node.
 */

class Solution{
    public:
    Node* lca(Node*root,int a,int b){
        if(!root) return NULL;
        if(root->data == a || root->data == b) return root;
        Node* l = lca(root->left,a,b);
        Node* r = lca(root->right,a,b);
        if(l && r) return root;
        else if(l && !r) return l;
        else if(!l && r) return r;
        else return NULL;
    }
    int d(Node*root,int x){
        if(!root) return 1e9;
        if(root->data == x) return 0;
        int op1 = d(root->left,x);int op2 = d(root->right,x);
        return 1 + min(op1,op2);
    }
    int findDist(Node* root, int a, int b) {
        Node*temp = lca(root,a,b);
        int ans = d(root,a) + d(root,b) - 2*d(root,temp->data);
        return ans;
    }
};