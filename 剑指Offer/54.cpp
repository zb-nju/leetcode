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
    int kthLargest(TreeNode* root, int k) {
        int now = 0;
        return dfs(root, now, k);
    }

private:
    int dfs(TreeNode* node, int& now, int k){
        if(node == nullptr)
            return -1;
        int temp;
        if((temp = dfs(node->right, now, k)) != -1)
            return temp;
        now++;
        if(now == k)
            return node->val;
        return dfs(node->left, now, k);
    }
};