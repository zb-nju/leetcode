#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
//     unordered_map<int,int>m;
//     int max;
//     vector<int> findMode(TreeNode* root) {
//         vector<int> ans;
//         max = 0;
//         if(root){
//             func(root);
//             unordered_map<int,int>::iterator it;
//             for(it=m.begin();it!=m.end();it++){
//                 if(it->second==max)
//                     ans.push_back(it->first);
//             }
//         }
//         return ans;
//     }

//     void func(TreeNode* root){
//         if(root){
//             m[root->val]++;
//             if(m[root->val]>max)
//                 max = m[root->val];
//             func(root->left);
//             func(root->right);
//         }
//     }
// };

class Solution {
public:
    int base,count,maxCount;
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        if(root){
            count = 0,maxCount = 0,base = root->val;
            func(root);
            update();
        }
        return ans;
    }

    void update(){
        if(count == maxCount)
            ans.push_back(base);
        else if(count>maxCount){
            ans.erase(ans.begin(),ans.end());
            ans.push_back(base);
            maxCount = count;
        }
        return;
    }

    void func(TreeNode* root){
        if(root){
            func(root->left);
            if(root->val == base)
                count++;
            else{
                update();
                base = root->val;
                count = 1;
            }
            func(root->right);
        }
    }
};