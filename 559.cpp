/*
 * @Author: your name
 * @Date: 2020-07-28 10:32:11
 * @LastEditTime: 2020-07-28 10:32:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\559.cpp
 */ 
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int max=0,t;
        for(int i=0;i<root->children.size();i++){
            t=maxDepth(root->children[i]);
            if(t>max)
                max=t;
        }
        return max+1;
    }
};