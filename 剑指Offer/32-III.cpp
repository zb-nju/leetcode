#include<iostream>
#include<stack>
#include<deque>
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
        stack<TreeNode*> q1, q2;
        vector<vector<int>> ans;
        bool flag = true;
        q2.push(root);
        TreeNode* temp;

        while(!q2.empty()){
            q1.swap(q2);
            vector<int> a;
            while(!q1.empty()){
                temp = q1.top();
                q1.pop();
                a.push_back(temp->val);
                if(flag){
                    if(temp->left)
                        q2.push(temp->left);
                    if(temp->right)
                        q2.push(temp->right);
                }else{
                    if(temp->right)
                        q2.push(temp->right);
                    if(temp->left)
                        q2.push(temp->left);
                }
            }
            flag = !flag;
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
        deque<TreeNode*> q;
        vector<vector<int>> ans;
        q.push_back(root);
        TreeNode* temp;

        while(!q.empty()){
            vector<int> a;
            for(int i = q.size(); i > 0; i--){
                temp = q.front();
                q.pop_front();
                a.push_back(temp->val);
                if(temp->left)
                    q.push_back(temp->left);
                if(temp->right)
                    q.push_back(temp->right);
            }
            ans.push_back(a);
            if(q.empty())
                break;
            vector<int> b;
            for(int i = q.size(); i > 0; i--){
                temp = q.back();
                q.pop_back();
                b.push_back(temp->val);
                if(temp->right)
                    q.push_front(temp->right);
                if(temp->left)
                    q.push_front(temp->left);
            }
            ans.push_back(b);
        }
        return ans;
    }
};