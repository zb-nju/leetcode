/*
 * @Author: your name
 * @Date: 2020-08-16 08:21:32
 * @LastEditTime: 2020-08-16 08:49:56
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\733.cpp
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int n=image.size(),m=image[0].size(),x,y,tx,ty,pre=image[sr][sc];
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.emplace(sr,sc);
        visit[sr][sc]=true;
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            image[x][y]=newColor;
            for(int i=0;i<4;i++){
                tx=x+dx[i];
                ty=y+dy[i];
                if(tx>=0&&tx<n&&ty>=0&&ty<m&&!visit[tx][ty]){
                    visit[tx][ty]=true;
                    if(image[tx][ty]==pre){
                        q.emplace(tx,ty);
                    }
                }
            }
        }
        return image;
    }
};