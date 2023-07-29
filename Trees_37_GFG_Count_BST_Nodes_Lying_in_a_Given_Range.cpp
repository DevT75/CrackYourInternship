class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here
      if(!root) return 0;
      if(root->data < l) return getCount(root->right,l,h);
      if(root->data > h) return getCount(root->left,l,h);
      int left = getCount(root->left,l,h);
      int right = getCount(root->right,l,h);
      return 1 + left + right;
    }
};