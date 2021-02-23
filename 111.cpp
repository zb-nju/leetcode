#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(l==0)
            return r+1;
        if(r==0)
            return l+1;
        return min(l,r)+1;
    }
};