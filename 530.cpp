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
    int last;
    int ans;
    int getMinimumDifference(TreeNode* root) {
        last = -1;
        ans = 2147483647;
        func(root);
        return ans;
    }

    void func(TreeNode*root){
        if(!root)
            return;
        func(root->left);
        if(last>=0){
            int t = abs(root->val-last);
            if(t<ans)
                ans = t;
        }
        last = root->val;
        func(root->right);
    }
};