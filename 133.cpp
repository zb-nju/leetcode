/*
 * @Author: your name
 * @Date: 2020-08-12 07:58:43
 * @LastEditTime: 2020-08-13 23:18:31
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\133.cpp
 */
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    map<int,Node*> m;
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
            return nullptr;
        Node* ans=new Node(node->val);
        m[node->val]=ans;
        helper(ans,node);
        return ans;
    }

    void helper(Node*&newone,Node*&oldone){
        Node*t;
        vector<Node*>::iterator p;
        for(p=oldone->neighbors.begin();p!=oldone->neighbors.end();p++){
            if(m.find((*p)->val)==m.end()){
                t=new Node((*p)->val);
                m[(*p)->val]=t;
                newone->neighbors.push_back(t);
                helper(t,(*p));
            }
            else{
                t=m[(*p)->val];
                newone->neighbors.push_back(t);
            }
        }
    }
};