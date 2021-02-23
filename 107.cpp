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
    vector<vector<int>> ans;
    int now;

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        now=-1;
        dfs(root,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(TreeNode*p,int l){
        if(p==nullptr)
            return;
        if(l>now){
            ans.push_back(vector<int>(0));
            now++;
        }
        ans[l].push_back(p->val);
        dfs(p->left,l+1);
        dfs(p->right,l+1);
        return;
    }
};
