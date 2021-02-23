/*
 * @Author: your name
 * @Date: 2020-07-16 18:06:56
 * @LastEditTime: 2020-07-16 18:06:57
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\785.cpp
 */ 

#include<vector>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color (n,0);
        queue<int>q;
        for(int k=0;k<n;k++){
            if(!color[k]){
                q.push(k);
                color[k]=1;
            }
            while(!q.empty()){
                int i=q.front();
                q.pop();
                for(int j=0;j<graph[i].size();j++){
                    int t=graph[i][j];
                    if(color[t]==color[i])
                        return false;
                    else if(!color[t]){
                        color[t]=3-color[i];
                        q.push(t);
                    }
                }
            }
        }
        return true;
    }
};