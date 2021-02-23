/*
 * @Author: your name
 * @Date: 2020-09-16 14:41:44
 * @LastEditTime: 2020-09-17 10:32:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\226.cpp
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
public:
    TreeNode* invertTree(TreeNode* root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode*p){
        if(!p)
            return;
        TreeNode*t=p->left;
        p->left=p->right;
        p->right=t;
        dfs(p->left);
        dfs(p->right);
    }
};