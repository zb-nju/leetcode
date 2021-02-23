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
    int now=0;

    TreeNode* convertBST(TreeNode* root) {
        if(root){
            convertBST(root->right);
            root->val+=now;
            now=root->val;
            convertBST(root->left);
        }
        return root;
    }
};