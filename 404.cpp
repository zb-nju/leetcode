/*
 * @Author: your name
 * @Date: 2020-09-19 10:29:40
 * @LastEditTime: 2020-09-19 10:36:24
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\404.cpp
 */
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int ans;
public:
    int sumOfLeftLeaves(TreeNode* root) {
        ans=0;
        if(root)
            dfs(root,false);
        return ans;
    }

    void dfs(TreeNode*root,bool isLeft){
        if(root->left==nullptr&&root->right==nullptr){
            if(isLeft)
                ans+=root->val;
            return;
        }
        if(root->left)
            dfs(root->left,true);
        if(root->right)
            dfs(root->right,false);
    }
};