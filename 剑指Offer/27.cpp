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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        TreeNode* left = mirrorTree(root->right), *right = mirrorTree(root->left);
        root->left = left;
        root->right = right;
        return root;
    }
};