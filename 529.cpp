/*
 * @Author: your name
 * @Date: 2020-08-20 14:58:09
 * @LastEditTime: 2020-08-21 09:18:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\529.cpp
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]]='X';
            return board;
        }
        int dx[8]={0,1,1,1,0,-1,-1,-1};
        int dy[8]={-1,-1,0,1,1,1,0,-1};
        int n=board.size(),m=board[0].size(),x,y,t,tx,ty;
        queue<pair<int,int>> q;
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        q.emplace(click[0],click[1]);
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            t=0;
            for(int i=0;i<8;i++){
                tx=x+dx[i];
                ty=y+dy[i];
                if(tx>=0&&tx<n&&ty>=0&&ty<m)
                    t+=board[tx][ty]=='M';
            }
            if(t>0)
                board[x][y]=t+'0';
            else{
                board[x][y]='B';
                for(int i=0;i<8;i++){
                    tx=x+dx[i];
                    ty=y+dy[i];
                    if(tx>=0&&tx<n&&ty>=0&&ty<m&&!visit[tx][ty]){
                        q.emplace(tx,ty);
                        visit[tx][ty]=true;
                    }
                }
            }
        }
        return board;
    }
}
