#include<iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//40ms
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==nullptr)
//             return nullptr;
//         else if(p->val<root->val&&q->val<root->val)
//             return lowestCommonAncestor(root->left,p,q);
//         else if(p->val>root->val&&q->val>root->val)
//             return lowestCommonAncestor(root->right,p,q);
//         else
//             return root;
//     }
// };

//28ms
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         ios::sync_with_stdio(0);
//         TreeNode*pr=root;
//         while(1)
//         {
//             if(p->val<pr->val&&q->val<pr->val)
//                 pr=pr->left;
//             else if(p->val>pr->val&&q->val>pr->val)
//                 pr=pr->right;
//             else
//                 break;
//         }
//         return pr;
//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min=p->val<q->val?p->val:q->val;
        int max=p->val>q->val?p->val:q->val;
        while(1)
        {
            if(root->val>max)
                root=root->left;
            else if(root->val<min)
                root=root->right;
            else
                break;
        }
        return root;
    }
};