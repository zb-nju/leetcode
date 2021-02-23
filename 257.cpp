/*
 * @Author: your name
 * @Date: 2020-09-04 14:55:56
 * @LastEditTime: 2020-09-05 15:10:18
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\257.cpp
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int>s;
    vector<string> ans;

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root!=nullptr)
            dfs(root);
        return ans;
    }

    void dfs(TreeNode* p){
        s.push_back(p->val);
        if(p->left==nullptr&&p->right==nullptr)
            generateAns();
        if(p->left!=nullptr)
            dfs(p->left);
        if(p->right!=nullptr)
            dfs(p->right);
        s.pop_back();
    }

    void generateAns(){
        int n=s.size();
        string t;
        for(int i=0;i<n-1;i++){
            t+=to_string(s[i]);
            t+='-';
            t+='>';
        }
        t+=to_string(s[n-1]);
        ans.push_back(t);
    }
};