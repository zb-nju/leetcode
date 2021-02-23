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
    bool isBalanced(TreeNode* root) {
        return func(root)!=-1;

    }

    int func(TreeNode*root){
        if(root==nullptr)
            return 0;
        int l,r,s;
        if((l=func(root->left))<0)
            return -1;
        if((r=func(root->right))<0)
            return -1;
        s=l-r;
        if(s>1||s<-1)
            return -1;
        return max(l,r)+1;
    }
};