#include<iostream>
#include<stack>
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
    void recoverTree(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode *first=nullptr,*second=nullptr,*pre=nullptr;
        while(!s.empty()||root!=nullptr){
            while(root!=nullptr){
                s.push(root);
                root=root->left;
            }
            root=s.top();
            s.pop();
            if(pre&&root->val<pre->val){
                second=root;
                if(first==nullptr)
                    first=pre;
            }
            pre=root;
            root=root->right;
        }
        int t=first->val;
        first->val=second->val;
        second->val=t;
    }
};