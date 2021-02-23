/*
 * @Author: zb-nju
 * @Date: 2020-09-30 10:36:01
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-09-30 11:07:46
 */
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // if(root){
        //     if(val>root->val)
        //         root->right = insertIntoBST(root->right,val);
        //     else
        //         root->left = insertIntoBST(root->left,val);
        // }
        // else
        //     root = new TreeNode(val);
        // return root;


        // TreeNode* parent = root,*now = root;
        // while(now){
        //     parent = now;
        //     if(val>now->val)
        //         now = now->right;
        //     else
        //         now = now->left;
        // }
        // if(parent){
        //     if(parent->val<val)
        //         parent->right = new TreeNode(val);
        //     else
        //         parent->left = new TreeNode(val);
        // }
        // else
        //     root = new TreeNode(val);
        // return root;

        if(root){
            if(val>root->val)
                root = new 
        }
        else
            root = new TreeNode(val);
        return root;
    }
};