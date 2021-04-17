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
    int maxDepth(TreeNode* root) {
        ans = 0;
        dfs(root, 1);
        return ans;
    }

private:
    int ans;
    void dfs(TreeNode* root, int now){
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr){
            if(now > ans)
                ans = now;
            return;
        }
        if(root->left)
            dfs(root->left, now + 1);
        if(root->right)
            dfs(root->right, now + 1);
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

private:
    int dfs(TreeNode* root){
        if(root == nullptr)
            return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }
};