#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct HelpTreeNode {
    int have;
    int notHave;
    HelpTreeNode *left;
    HelpTreeNode *right;
    HelpTreeNode() : have(0), notHave(0), left(NULL), right(NULL) {}
};


class Solution {
public:
    int ans;
    int minCameraCover(TreeNode* root) {
        ans = 0;
        HelpTreeNode* helpRoot = new HelpTreeNode;
        if(root)
            func(root, helpRoot);
        return ans;
    }

    bool func(TreeNode* root,HelpTreeNode*& helpRoot){
        bool sonIsCover = true, thisIsCover = false;
        if(root->left){
            helpRoot->left=new HelpTreeNode;
            sonIsCover &&=func(root->left,helpRoot->left);
            thisIsCover ||= root->left->val;
        }
        if(root->right){
            helpRoot->right=new HelpTreeNode;
            sonIsCover &&=func(root->right,helpRoot->right);
            thisIsCover ||= root->right->val;
        }
        if(!sonIsCover){
            root->val = 1;
            
        }
    }
};