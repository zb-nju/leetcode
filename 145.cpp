#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct NodeAndFlag
{
    TreeNode* node;
    bool flag;
    NodeAndFlag(TreeNode*p):node(p),flag(flase){}
};


class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        func(root);
        return ans;
    }

    void func(TreeNode*root){
        if(root){
            func(root->left);
            func(root->right);
            ans.push_back(root->val);
        }
    }
};