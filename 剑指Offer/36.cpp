#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        pre = nullptr; head = nullptr;
        dfs(root);
        pre->right = head;
        head->left = pre;
        return head;
    }

private:
    Node *pre, *head;
    void dfs(Node*root){
        if(root == nullptr)
            return;
        dfs(root->left);
        if(pre != nullptr)
            pre->right = root;
        else
            head = root;
        root->left = pre;
        pre = root;
        dfs(root->right);
    }
};