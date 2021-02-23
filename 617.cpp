/*
 * @Author: your name
 * @Date: 2020-09-23 13:44:35
 * @LastEditTime: 2020-09-24 14:51:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\617.cpp
 */
/*
 * @Author: your name
 * @Date: 2020-09-23 13:44:35
 * @LastEditTime: 2020-09-23 16:40:30
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\617.cpp
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1&&t2){
            t1->val+=t2->val;
            t1->left = mergeTrees(t1->left,t2->left);
            t1->right = mergeTrees(t1->right,t2->right);
            return t1;
        }
        else if(t1){
            return t1;
        }
        else if(t2){
            return t2;
        }
        return nullptr;
    }

};