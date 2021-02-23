/*
 * @Author: your name
 * @Date: 2020-08-05 00:03:59
 * @LastEditTime: 2020-08-05 16:56:07
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\337.cpp
 */
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
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int* ans=func(root);
        return max(ans[0],ans[1]);
    }

    int* func(TreeNode* root){
        int *l,*r;
        int *ans=new int[2];
        if(!root->left){
            if(!root->right){
                ans[0]=0;
                ans[1]=root->val;
                return ans;
            }
            else{
                r=func(root->right);
                ans[0]=max(r[0],r[1]);
                ans[1]=root->val+r[0];
                return ans;
            }
        }
        if(!root->right){
            l=func(root->left);
            ans[0]=max(l[0],l[1]);
            ans[1]=root->val+l[0];
            return ans;
        }
        l=func(root->left);
        r=func(root->right);
        ans[0]=max(r[0],r[1])+max(l[0],l[1]);
        ans[1]=root->val+r[0]+l[0];
        return ans;
    }
};