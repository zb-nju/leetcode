/*
 * @Author: your name
 * @Date: 2020-07-13 17:57:56
 * @LastEditTime: 2020-07-13 18:09:53
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\129.cpp
 */ 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int ans=0;
        func(root,0,ans);
        return ans;
    }
    
    void func(TreeNode*p,int now,int&ans){
        now=now*10+p->val;
        if(p->left==nullptr&&p->right==nullptr){
            ans+=now;
            return;
        }
        if(p->left!=nullptr)
            func(p->left,now,ans);
        if(p->right!=nullptr)
            func(p->right,now,ans);
    }