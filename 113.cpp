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
    vector<vector<int>> ans;
    vector<int> now;
    int nowSum;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        nowSum = 0;
        if(root)
            func(root,sum);
        return ans;
    }
    void func(TreeNode* root,int& sum){
        nowSum+=root->val;
        now.push_back(root->val);
        if(!root->left&&!root->right){
            if(nowSum==sum){
                ans.push_back(now);
            }
        }
        if(root->left)
            func(root->left,sum);
        if(root->right)
            func(root->right,sum);
        now.pop_back();
        nowSum-=root->val;
    }
};