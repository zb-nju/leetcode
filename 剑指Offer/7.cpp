#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<int, int>mymap;
public:
    TreeNode* func(const vector<int>& preorder, const vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight){
        if(preLeft > preRight)
            return nullptr;
        int rootVal = preorder[preLeft];
        int inMiddle = mymap[rootVal];
        int leftChildNum = inMiddle - inLeft;

        TreeNode* root = new TreeNode(rootVal);
        root->left = func(preorder, inorder, preLeft + 1, preLeft + leftChildNum, inLeft, inMiddle - 1);
        root->right = func(preorder, inorder, preLeft + leftChildNum + 1, preRight, inMiddle + 1, inRight);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            mymap[inorder[i]]=i;
        return func(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};