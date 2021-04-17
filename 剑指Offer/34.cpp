#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        func(root, sum);
        return ans;
    }

private:
    vector<vector<int>> ans;
    vector<int> now;
    void func(TreeNode* root, int sum){
        if(root == nullptr)
            return;

        now.push_back(root->val);
        sum -= root->val;
        if(sum == 0 && root->left == nullptr && root->right == nullptr)
            ans.push_back(now);
        else{
            func(root->left, sum);
            func(root->right, sum);
        }
        now.pop_back();
    }
};