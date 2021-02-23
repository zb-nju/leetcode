/*
 * @Author: your name
 * @Date: 2020-07-29 08:32:58
 * @LastEditTime: 2020-07-29 08:32:58
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C++\leetcode\LCP13.cpp
 */ 
#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;

class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int m,n;

    bool isBound(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }

    vector<vector<int>> bfs(int x,int y,vector<string>& maze){
        vector<vector<int>> ret(n,vector<int>(m,-1));
        ret[x][y]=0;
        queue<pair<int,int>> Q;
        Q.push({x,y});
        while(!Q.empty()){
            auto p=Q.front();
            Q.pop();
            x=p.first,y=p.second;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(isBound(nx,ny)&&maze[nx][ny]!='#'&&ret[nx][ny]==-1){
                    ret[nx][ny]=ret[x][y]+1;
                    Q.push({nx,ny});
                }
            }
        }
        return ret;
    }

    int minimalSteps(vector<string>& maze) {
        n=maze.size();m=maze[0].size();
        vector<pair<int,int>>buttons,stones;
        int sx,sy,tx,ty;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                switch (maze[i][j])
                {
                case 'M':buttons.push_back({i,j});  break;
                case 'O':stones.push_back({i,j});   break;
                case 'S':sx=i;sy=j;     break;
                case 'T':tx=i;ty=j;     break;
                default:
                    break;
                }
            }
        }
        int nb=buttons.size(),ns=stones.size();
        vector<vector<int>> start_dist=bfs(sx,sy,maze);
        if(nb==0)
            return start_dist[tx][ty];

        vector<vector<int>>dist(nb,vector<int>(nb+2,-1));
        vector<vector<vector<int>>>dd(nb);
        for(int i=0;i<nb;i++){
            dd[i]=bfs(buttons[i].first,buttons[i].second,maze);
            dist[i][nb+1]=dd[i][tx][ty];
        }
        for(int i=0;i<nb;i++){
            int tmp=-1;
            for(int k=0;k<ns;k++){
                int mid_x=stones[k].first,mid_y=stones[k].second;
                if(dd[i][mid_x][mid_y]!=-1 && start_dist[mid_x][mid_y]!=-1){
                    if(tmp==-1||tmp>dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y])
                        tmp=dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y];
                }
            }
            dist[i][nb]=tmp;
            for(int j=i+1;j<nb;j++){
                int mn=-1;
                for(int k=0;k<ns;k++){
                    int mid_x=stones[k].first,mid_y=stones[k].second;
                    if(dd[i][mid_x][mid_y]!=-1 && dd[j][mid_x][mid_y]!=-1){
                        if(mn==-1||mn>dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y])
                            mn=dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y];
                    }
                }
                dist[i][j]=dist[j][i]=mn;
            }
        }
        for(int i=0;i<nb;i++){
            if(dist[i][nb]==-1||dist[i][nb+1]==-1)
                return -1;
        }
        vector<vector<int>>dp(1<<nb,vector<int>(nb,-1));
        for(int i=0;i<nb;i++)
            dp[1<<i][i]=dist[i][nb];

        for(int mask=1;mask<(1<<nb);mask++){
            for(int i=0;i<nb;i++){
                if(mask&(1<<i)){
                    for(int j=0;j<nb;j++){
                        if(!(mask&(1<<j))){
                            int next = mask|(1<<j);
                            if(dp[next][j]==-1||dp[next][j]>dp[mask][i]+dist[i][j])
                                dp[next][j]=dp[mask][i]+dist[i][j];
                        }
                    }
                }
            }
        }
        int ret = -1,final_mask=(1<<nb)-1;
        for(int i=0;i<nb;i++){
            if(ret==-1||ret>dp[final_mask][i]+dist[i][nb+1])
                ret=dp[final_mask][i]+dist[i][nb+1];
        }
        return ret;
    }
};