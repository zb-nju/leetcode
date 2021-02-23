/*
 * @Author: your name
 * @Date: 2020-07-28 10:25:16
 * @LastEditTime: 2020-07-28 10:25:16
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\104.cpp
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int l=maxDepth(root->left),r=maxDepth(root->right);
        return (l>r?l:r)+1;
    }
};