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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == nullptr || A == nullptr)
            return false;
        return func(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool func(TreeNode* A, TreeNode* B){
        if(A == nullptr)
            return B == nullptr;
        else if (B == nullptr)
            return true;
        else if(B->val == A->val)
            return func(A->left, B->left) && func(A->right, B->right);
        else
            return false;
    }
};