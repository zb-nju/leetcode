#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visit(rooms.size(),false);
        queue<int> q;
        int t,t2;
        q.push(0);
        visit[0]=true;
        while(!q.empty()){
            t=q.front();
            q.pop();
            for(int i=0;i<rooms[t].size();i++){
                t2=rooms[t][i];
                if(!visit[t2]){
                    q.push(t2);
                    visit[t2]=true;
                }
            }
        }
        for(int i=0;i<visit.size();i++)
            if(!visit[i])
                return false;
        return true;
    }
};