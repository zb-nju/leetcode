/*
 * @Author: your name
 * @Date: 2020-07-06 23:53:19
 * @LastEditTime: 2020-07-07 00:42:32
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\1367.cpp
 */ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root==nullptr)
            return false;
        return func(head,root)||isSubPath(head,root->right)||isSubPath(head,root->left);
    }

    bool func(ListNode* p, TreeNode* root){
        if(p==nullptr)
            return true;
        if(root == nullptr)
            return false;
        if(p->val!=root->val)
            return false;
        else
            return func(p->next,root->left)||func(p->next,root->right);
}
};

