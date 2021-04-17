#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode*> q1, q2;
        vector<vector<int>> ans;
        q2.push(root);
        TreeNode* temp;

        while(!q2.empty()){
            q1.swap(q2);
            vector<int> a;
            while(!q1.empty()){
                temp = q1.front();
                q1.pop();
                a.push_back(temp->val);
                if(temp->left)
                    q2.push(temp->left);
                if(temp->right)
                    q2.push(temp->right);
            }
            ans.push_back(a);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        TreeNode* temp;

        while(!q.empty()){
            vector<int> a;
            for(int i = q.size();i>0;i--){
                temp = q.front();
                q.pop();
                a.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(a);
        }
        return ans;
    }
};