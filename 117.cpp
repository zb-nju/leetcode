/*
 * @Author: zb-nju
 * @Date: 2020-09-28 08:46:55
 * @LastEditors: zb-nju
 * @LastEditTime: 2020-09-28 09:04:23
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root){
            queue<Node*> q1,q2;
            Node* now=nullptr,*last = nullptr;
            q2.push(root);
            while(!q2.empty()){
                q1.swap(q2);
                last = nullptr;
                while (!q1.empty())
                {
                    now = q1.front();
                    q1.pop();
                    now->next = last;
                    last = now;
                    if(now->right)
                        q2.push(now->right);
                    if(now->left)
                        q2.push(now->left);
                }
            }
        }
        return root;
    }
};