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
        return dfs(root) != -1;
    }

private:
    int dfs(TreeNode* root){
        if(root == nullptr)
            return 0;
        int l = dfs(root->left), r = dfs(root->right);
        if(abs(l - r) > 1 || l == -1 || r == -1)
            return -1;
        return max(l, r) + 1;
    }
};