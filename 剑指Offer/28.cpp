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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        return func(root->left, root->right);
    }

private:
    bool func(TreeNode* p1, TreeNode* p2){
        if(p1 == nullptr)
            return p2 == nullptr;
        if(p2 == nullptr)
            return p1 == nullptr;
        if(p1->val == p2->val)
            return func(p1->left, p2->right) && func(p1-> right, p2->left);
        return false;
    }
};